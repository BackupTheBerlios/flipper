/***************************************************************************
                         diff.c  -  main program
                              -------------------
     copyright            : (C) 2005 by André Rognes
     email                : rognes@users.berlios.de
  ***************************************************************************/

/***************************************************************************
  *                                                                         *
  *   This program is free software; you can redistribute it and/or modify  *
  *   it under the terms of the GNU General Public License as published by  *
  *   the Free Software Foundation; either version 2 of the License, or     *
  *   (at your option) any later version.                                   *
  *                                                                         *
  ***************************************************************************/
#include "headers.h"
#include "intset.h"
#include "defines.h"
#include "simple.h"
#include "composed.h"


unsigned int global__n_granularity;
unsigned int global__n_factor;  // 8^granularity;
unsigned int global__n_max_flips;
double global__f_temprature;     //used for annealing


/*
 * the maximal index of occuring relations
 * */

typedef struct _rel rel;
struct _rel {
     char arr_name[MAX_REL_NAME];
     unsigned int arity;
     composed *value;
};

int global__n_rels;
rel arr_struct_rel[MAX_RELS];
int global__n_current_rel_id;
composed *global__zero;
composed *global__zero0;  //0-dimensional
composed *global__one0;   //0-dimensional
composed *global__succ;
composed *global__eq;    //the closest we get to equality

/* variables for keeping track of where things failed lastly */
composed *global__last_failed_sentence;

unsigned int count_vars(char *str_descr) {
  const char *p;
  unsigned int ret;
 
  ret = 3; //the dimension
  for (p = str_descr,p += 2; *p != 'q'; p += 2) {
    if (*p == 's') --ret;
  }
     return ret;
}

void register_relation(char *str_name, char *str_descr,int n_rel_id) {
     unsigned int n_vars;

     if (arr_struct_rel[n_rel_id].value == 0) {
	  if (n_rel_id >= global__n_rels) {
	       global__n_rels = n_rel_id + 1;    
	  }
	  arr_struct_rel[n_rel_id].arity = count_vars(str_descr);
	  strcpy(arr_struct_rel[n_rel_id].arr_name,str_name);
	  arr_struct_rel[n_rel_id].value = new__composed_zero(3);
     } else {
	  n_vars = count_vars(str_descr);
	  if (n_vars > arr_struct_rel[n_rel_id].arity)
	       arr_struct_rel[n_rel_id].arity = n_vars;
     }
}

composed *p(const composed *q) {
     composed *ret;
     
     ret = new__composed_composed(q);
     composed__p(ret);
     composed__delayed_delete(ret);
     return ret;
}

composed *r(const composed *q) {
     composed *ret;
     
     ret = new__composed_composed(q);
     composed__r(ret);
     composed__delayed_delete(ret);
     return ret;
}

composed *s(const composed *q) {
     composed *ret;
     score s;
     
     ret = new__composed_composed(q);
     composed__s(ret);
     composed__minimizing_score(ret,&s); //for minimalization only
     composed__delayed_delete(ret);
     return ret;
}

composed *c0(const composed *q) {
     composed *ret;
     score s;
     
     ret = new__composed_composed(q);
     composed__c(0,ret);
     composed__minimizing_score(ret,&s); //for minimalization only
     composed__delayed_delete(ret);
     return ret;
}

composed *init_v(composed *x_or_y,
		 char *descr,
	    composed *arg0,
	    composed *arg1) {
     composed__initialize(arg0->n_dim,x_or_y);
     x_or_y->descr = descr;
     composed__or(arg0,x_or_y);
     composed__or(arg1,x_or_y);
     composed__set_arg0(x_or_y,arg0);
     composed__set_arg1(x_or_y,arg1);

     x_or_y->relations = malloc(sizeof(intset));
     intset__init(x_or_y->relations);
     intset__or(arg0->relations,x_or_y->relations);
     intset__or(arg1->relations,x_or_y->relations);
     return x_or_y;
}

/* Formula for calculation;
 * (x+dx) | (y+dy) = (x | y) + (y+dy)*dx + (x+dx)*dy + (dx | dy)
 * Here
 * |     means or
 * +     means xor
 * (x | y) is the permanent value
 * (x | y) + (y+dy)*dx + (x+dx)*dy + (dx | dy) is the return value
 * dx    is a sparce value
 * dy    is a sparce value
 */
const composed *v(composed *x_or_y,
	    const composed *dx,
	    const composed *dy) {
     composed *dx_or_dy;
     composed *x_and_dy;
     composed *y_and_dx;
     const composed *x_xor_dx,*y_xor_dy;
     
     //if (!intset__member(global__n_current_rel_id,x_or_y->relations)) return global__zero;
     
     x_xor_dx = composed__get_arg0(x_or_y);
     y_xor_dy = composed__get_arg1(x_or_y);
          
     
     //start from the right
     dx_or_dy = new__composed_composed(dx);
     composed__or(dy,dx_or_dy);
     
     
     x_and_dy = new__composed_composed(dy);
     composed__and(x_xor_dx,x_and_dy);
     
     
     y_and_dx = new__composed_composed(dx);
     composed__and(y_xor_dy,y_and_dx);
     
     
     composed__xor(x_and_dy,dx_or_dy);
     
     composed__xor(y_and_dx,dx_or_dy);
     
     
     composed__xor(dx_or_dy,x_or_y);
          
     composed__delayed_delete(y_and_dx);
     composed__delayed_delete(x_and_dy);
     composed__delayed_delete(dx_or_dy);
          
     
     return dx_or_dy;
}

composed *init_neg(composed *not_x, char *descr,composed *x) {
     composed__initialize(x->n_dim, not_x);
     not_x->descr = descr;
     composed__or(x,not_x);
     composed__not(not_x);
     composed__set_arg0(not_x,x);
     composed__set_arg1(not_x,0);
     
     not_x->relations = malloc(sizeof(intset));
     intset__init(not_x->relations);
     intset__or(x->relations,not_x->relations);
     return not_x;
}

const composed *neg(composed *not_x,const composed *dx) {
     
     //if (!intset__member(global__n_current_rel_id,not_x->relations)) return global__zero;
     
     composed__xor(dx,not_x);
     return dx;
}


composed *init_axyz(composed *c, char *descr, composed *sibling) {
     composed__initialize(sibling->n_dim,c);
     c->descr = descr;
     
     composed__or(sibling,c);
     composed__not(c); //c is now the negation of sibling
     if (c->n_dim == 3) composed__c(2,c);
     if (c->n_dim == 2) composed__c(1,c);
     if (c->n_dim == 1) composed__c(0,c);
     composed__not(c); //cylindrify and negate
     
     //composed__axyz(c);
     composed__set_arg0(c,sibling);
     
     c->axyz = new__composed_composed(sibling);
     
     composed__balanced_score(global__n_factor,c->axyz,&(c->s_score));
     
     
          c->relations = malloc(sizeof(intset));
          intset__init(c->relations);
          intset__or(sibling->relations,c->relations);
          return c;
}

/*
 *  * score(x xor dx) = score(x) + score(dx) - 2*score(x & dx)
 *  * 
 *  */
const composed *axyz(composed *cx, const composed *dx) {
     const composed *x;
     composed *cx_and_dx;
     score score_dx, score_cx_and_dx;
     unsigned int n_prev_zeros;
     
     //if (!intset__member(global__n_current_rel_id,cx->relations)) return global__zero0;
     
     n_prev_zeros =  cx->s_score.n_zeros;
     x = composed__get_arg0(cx);
          
     cx_and_dx = new__composed_composed(dx);
     composed__and(cx->axyz,cx_and_dx);
     
     composed__balanced_score(global__n_factor,dx,&score_dx);
     composed__balanced_score(global__n_factor,cx_and_dx,&score_cx_and_dx);
     
     score__x_p_y_m_xy_m_xy(x->n_dim,global__n_factor,&score_dx,&score_cx_and_dx,&(cx->s_score));
     //composed__score(x,&(cx->s_score));
     
     
     composed__delayed_delete(cx_and_dx);
     
     //note cx now becomes the same as x
     composed__xor(dx,cx->axyz);
          
     if (cx->s_score.n_zeros == 0) {
	  if (n_prev_zeros == 0) {
	       return global__zero0;
	  } else {
	       composed__xor(global__one0,cx);
	       return global__one0;
	  }
     } else {
	  if (n_prev_zeros == 0) {
	       composed__xor(global__one0,cx);
	       return global__one0;
	  } else {
	       return global__zero0;
	  }
     }
}

/*
composed *init_axyez(composed *c, char *descr, composed *sibling) {
          composed__initialize(sibling->n_dim,c);
          c->descr = descr;
          composed__or(sibling,c);
          //composed__axyez(c);
          composed__set_arg0(c,sibling);
          composed__set_arg1(c,0);
          composed__balanced_score(global__n_factor,c,&(c->s_score));
     
     
          c->relations = malloc(sizeof(intset));
          intset__init(c->relations);
          intset__or(sibling->relations,c->relations);
          return c;
}
*/

/*
 *  * score(x xor dx) = score(x) + score(dx) - 2*score(x & dx)
 *  * 
 *  */

/*
const composed *axyez(composed *cx, const composed *dx) {
     composed *c2dx;
     
     c2dx = new__composed_composed(dx);
     composed__c2(c2dx);
     
     composed__delayed_delete(c2dx);
     
     return axyz(cx,c2dx);
}
*/

composed *init_c(composed *c, int n_projection, char *descr, composed *sibling) {
     composed__initialize((sibling->n_dim), c);
     c->descr = descr;
     composed__or(sibling,c);
     composed__c(n_projection,c);
     composed__set_arg0(c,sibling);
     composed__set_arg1(c,0);
     
     c->relations = malloc(sizeof(intset));
     intset__init(c->relations);
     intset__or(sibling->relations,c->relations);
     return c;
}

/* 
 * strip := c(dx);     //changes are garanteed to occur within strip
 * sx_sdx := (x+dx) * strip; // the part of x+dx that lies within strip
 * oldstrip := cx * strip;    // the part of c(x) that lies within strip
 * newstrip := c(sx_sdx);
 * c(x) := c(x) + oldstrip; //erase strip from c(x)
 * c(x) := c(x) + newstrip
 * 
 * c(x+dx) = c(x) + oldstrip   + newstrip
 * c(x+dx) = c(x) + c(x)*c(dx) + c((x+dx)*c(dx))
 * now c((c+dx)*c(dx)) is not defined due to nesting of cylindrification
 * so use t instead, now c(x)*t(dx) translates to c(x)*c(t(dx))
 * c(x+dx) = c(x) + c(x)*c(t(dx)) + c((x+dx)*t(dx))
*/
const composed *c_local(composed *cx, int n_projection, const composed *dx) {
     const composed *x_xor_dx;
     composed *oldstrip;
     composed *newstrip;
     score dummy_score;
     
     //if (!intset__member(global__n_current_rel_id,cx->relations)) return global__zero;
     
     x_xor_dx = composed__get_arg0(cx);
          
     oldstrip = new__composed_composed(dx);        //oldstrip = dx     
     composed__t(n_projection,oldstrip);           //oldstrip = t(dx) = strip
     newstrip = new__composed_composed(oldstrip);  //newstrip = t(dx) = strip
     
     //finish oldstrip
     composed__c(n_projection,oldstrip); //to get dimension right
     composed__and(cx,oldstrip);    //oldstrip done
     
     //finish newstrip
     composed__and(x_xor_dx,newstrip);    //newstrip = strip*(x+dx);
     composed__c(n_projection,newstrip); // newstrip = c(strip*(x+dx)*strip);
     
     //add strips (reuse newstrip)
     composed__xor(oldstrip,newstrip);
     composed__minimizing_score(newstrip,&dummy_score); //just to minimize representation
     
     //do changes to cx
     composed__xor(newstrip,cx);

     composed__delayed_delete(oldstrip);
     composed__delayed_delete(newstrip);
          
     return newstrip;
}

/*
 *  c(x+dx) = c(x) + c(x) + c(x+dx)
 */
const composed *c(composed *cx, int n_projection, const composed *dx) {
     const composed *x_xor_dx;
     composed *ctx_xor_dx;
     composed *tcx;
     
     //if (!intset__member(global__n_current_rel_id,cx->relations)) return global__zero;
     
     x_xor_dx = composed__get_arg0(cx);
          
     ctx_xor_dx = new__composed_composed(x_xor_dx);
     
     composed__c(n_projection,ctx_xor_dx);
     
     tcx = new__composed_composed(cx);
     
     //reuse of tcx
     composed__xor(ctx_xor_dx,tcx);
     composed__xor(tcx,cx);
     
     composed__delayed_delete(ctx_xor_dx);
     composed__delayed_delete(tcx);
          
     return tcx;
}

/*initial value of relations are 0, so x is not used */
composed *init_R(composed *r, char *str_name, char *descr,int n_rel_id, const composed *x) {
     register_relation(str_name, descr, n_rel_id);
     r->descr = descr;
     composed__initialize(3,r);
     composed__set_arg0(r,0);
     composed__set_arg1(r,0);
     
     r->relations = malloc(sizeof(intset));
     intset__init(r->relations);
     intset__insert(n_rel_id,r->relations);
     r->n_rel_id = n_rel_id;
     return r;
}

static const composed *R(composed *r, int n_rel_id, int n_delta_rel_id, const composed *dx) {
          
     //if (!intset__member(global__n_current_rel_id,&r->s_relations)) return global__zero;
     
     
     //composed__xor(dx, r);
     //return dx;
     

     if (n_rel_id == n_delta_rel_id) {
	  
	  composed__xor(dx, r);
	  return dx;
     } else {
	  return global__zero;
     }

}

composed *init_succ(composed *r, char *str_name, char *descr, const composed *x) {
     r->descr = descr;
     composed__initialize(3,r);
     composed__or(x,r); //is now successor provided init() is called with succesor as argument
     composed__set_arg0(r,0);
     composed__set_arg1(r,0);
     
     r->relations = malloc(sizeof(intset));
     intset__init(r->relations);
     
     return r;
}

// this funcion is never called as succ is a constant and constants never change
composed *succ(composed *r,composed * dx) {
     return global__zero;
}

void uninit(composed *x) {
     int i;
     if (x == 0) {
	  return;
     } else {
	  free(x->relations);
	  uninit(x->arg0);
	  if (*(x->descr) == 'v') uninit(x->arg1);
	  if (*(x->descr) == 'a') composed__delete(x->axyz);
	  if (!x->is_simple) {
	       DIFF_FOR_EACH_QUADRANT(x,composed__delete);
	       for (i = 0; i < DIFF_QUADRANTS;++i) {
		    x->pQuadrant[i] = 0;
	       }
	  }
     }
}

/* check sanity of sets */
int sane(composed *x) {
     if (!composed__sane(x)) return 0;
     if (x->arg0 != 0 && !sane(x->arg0)) return 0;
     if (x->arg1 != 0 && !sane(x->arg1)) return 0;
     return 1;
}

void display(int tabs, composed *x) {
     int i;
     
     for (i = 0; i < tabs; ++i) {
	  printf(" ");
     }
     composed__display(1,x);
     printf("\t"),
     printf(x->descr);
     if (*(x->descr) == 'a') {
	  printf("\tsibling dim: %d",x->arg0->n_dim);
	  printf("\tzeros: %u ones: %u", x->s_score.n_zeros,x->s_score.n_ones);
     }
     printf("\tdim: %d:", x->n_dim);
     printf("\trelations:");
     intset__describe(x->relations);
     printf("\n");
     if (x->arg0 != 0) display(tabs + 1, x->arg0);
     if (*(x->descr) == 'v') display(tabs + 1, x->arg1);
}


composed *make_zero(composed *q) {
}


#include "formula.h"

void display_assignment() {
     int i;
     for (i = 0; i < global__n_rels; ++i) {
	  printf("%s: ",arr_struct_rel[i].arr_name);
	  composed__display(0,arr_struct_rel[i].value);
	  printf("\n");
     }
}

void do_score(composed *x, score *s) {
     score n_s;
     
     switch(*(x->descr)) {
     case '-' :
	  do_score(composed__get_arg0(x),s);
	  score__not(s);
	  score__copy(s,&(x->s_score));
	  return;
     case 'v' :
	  do_score(composed__get_arg0(x),&n_s);
	  do_score(composed__get_arg1(x),s);
	  score__pluss(&n_s,s);
	  score__copy(s,&(x->s_score));
	  return;
     case 'a' :
	  score__copy(&(x->s_score),s);
	  //composed__balanced_score(global__n_factor,x,s);
	  //printf("ones: %d, zeros: %d\n",s->n_ones,s->n_zeros);
	  if (s->n_zeros != 0) {
	       global__last_failed_sentence = x;
	  }
	  score__copy(s,&(x->s_score));
	  return;	  
     default :
	  //composed__score(x,s);
	  composed__balanced_score(global__n_factor,x,s);
	  //printf("ones: %d, zeros: %d\n",s->n_ones,s->n_zeros);
	  if (s->n_zeros != 0) {
	       global__last_failed_sentence = x;
	  }
	  score__copy(s,&(x->s_score));
	  return;
      }
}

void do_score_fast(composed *x, score *s) {
     score n_s;
     
     
     if (!intset__member(global__n_current_rel_id,x->relations)) {
	  score__copy(&(x->s_score),s);
	  return;
     }
     
       
     switch(*(x->descr)) {
     case '-' :
	  do_score_fast(composed__get_arg0(x),s);
	  score__not(s);
	  score__copy(s,&(x->s_score));
	  return;
     case 'v' :
	  do_score_fast(composed__get_arg0(x),&n_s);
	  do_score_fast(composed__get_arg1(x),s);
	  score__pluss(&n_s,s);
	  score__copy(s,&(x->s_score));
	  return;
     case 'a' :
	  score__copy(&(x->s_score),s);
	  //printf("ones: %d, zeros: %d\n",s->n_ones,s->n_zeros);
	  if (s->n_zeros != 0) {
	       global__last_failed_sentence = x;
	  }
	  return;
     default :
	  composed__balanced_score(global__n_factor,x,s);
	  //printf("ones: %d, zeros: %d\n",s->n_ones,s->n_zeros);
	  if (s->n_zeros != 0) {
	       global__last_failed_sentence = x;
	  }
	  score__copy(s,&(x->s_score));
	  return;
     }
}


void do_score_all(composed *x, score *s) {
     score n_s;
     
     switch(*(x->descr)) {
     case '-' :
	  do_score_all(composed__get_arg0(x),s);
	  score__not(s);
	  score__copy(s,&(x->s_score));
	  return;
     case 'v' :
	  do_score_all(composed__get_arg0(x),&n_s);
	  do_score_all(composed__get_arg1(x),s);
	  score__pluss(&n_s,s);
	  score__copy(s,&(x->s_score));
	  return;
     case 'a' :
	  composed__balanced_score(global__n_factor,x->axyz,s);
	  score__copy(s,&(x->s_score));
	  if (s->n_zeros != 0) {
	       global__last_failed_sentence = x;
	  }
	  if (global__last_failed_sentence == 0)
	       global__last_failed_sentence = x;
	  return;	  
     default :
	  composed__balanced_score(global__n_factor,x,s);
	  score__copy(s,&(x->s_score));
	  return;
     }
}

int pick_a_rel_id(const composed *x) {          
     switch(*(x->descr)) {
     case '-' :
	  return pick_a_rel_id(composed__get_arg0(x));
     case 'v' :
	  if (rand() > RAND_MAX/2) {
	       pick_a_rel_id(composed__get_arg0(x));
	  } else {
	       pick_a_rel_id(composed__get_arg1(x));
	  }
     case 'a' :
	  return pick_a_rel_id(composed__get_arg0(x));
     case 'e' :
	  return pick_a_rel_id(composed__get_arg0(x));
     default :
	  //we're at a relation symbol
	  return x->n_rel_id;
     }
}

void cleanup() {
     uninit(&set);
     composed__clear_stack();
     
     //printf("\n");
     //composed__stats();
     
     composed__delete(global__zero);
     composed__delete(global__zero0);
     composed__delete(global__one0);
     composed__delete(global__succ);
}

void model() {     
     if (DESCRIBE_MODEL) {
	  printf("model found!\n");
	  display_assignment();
     /*
      printf("whole evaluation:\n");
      display(0,&set);
      */
     }
     
     cleanup();
     exit(0);
}

const composed *flip(int n_rel_id,const composed *x) {
     composed__xor(x,arr_struct_rel[n_rel_id].value);
     global__n_current_rel_id = n_rel_id;
     return F(n_rel_id,x);
}

void reverse_substitute(const char* descr, composed *x) {
     const char *p;
     
     for (p = descr,p += 2; *p != 'q'; p += 2) {
	  switch (*p) {
	  case 'r' :
	       composed__r(x);
	       composed__r(x);
	       break;
	  case 's' :
	       composed__s_inv(x);
	       break;
	  case 'p' :
	       composed__p(x);
	       break;
	  }
     }
}

/* if successful this function picks a relation and the change to be made to that relation 
   returnes 0 if the choice can be made deterministically */

int head_not_shallow(int *rel_id, composed *x) {
     unsigned int i;
     composed *r,*p;  //general temporary pointer
     const composed *a;
     
     if (*(global__last_failed_sentence->descr) == 'a') {
	  p = composed__get_arg0(global__last_failed_sentence);
	  if (*(p->descr) == 'r') {
	       r = p;
	       composed__zero(x);
	       composed__not(x);
	       composed__xor(r,x);
	       *rel_id = r->n_rel_id;
	       reverse_substitute(r->descr,x);
	       return 0;
	  }
	  if (*(p->descr) == 'v') {
	       a = composed__get_arg1(p);
	       p = composed__get_arg0(p);
	       if (*(p->descr) == 'r') {
		    // this sentence is aaa(r(X) v A) so enlarge r by the complement of A
		    r = p;
		    //if (count_vars(r->descr) < arr_struct_rel[r->n_rel_id].arity)
			 //return 1;
		    p = new__composed_composed(r);
		    
		    composed__not(p);
		    composed__zero(x);
		    composed__not(x);
		    composed__xor(a,x);
		    composed__and(p,x); //TODO: possibly turn this around for speed
		    
		    composed__delete(p);
		    
		    *rel_id = r->n_rel_id;
		    reverse_substitute(r->descr,x);
		    return 0;
	       }
	       if (*(p->descr) == '-') {
		 p = composed__get_arg0(p);
		 if (*(p->descr) == 'r') {
		    // this sentence is aaa(-r(X) v A) so shrink r by the complement of A
		    r = p;
		    //if (count_vars(r->descr) < arr_struct_rel[r->n_rel_id].arity)
			 //return 1;
		    p = new__composed_composed(a);
		    
		    composed__zero(x);
		    composed__not(x);
		    composed__xor(a,x);
		    composed__and(r,x); //TODO: possibly turn this around for speed
		    
		    composed__delete(p);
		    
		    *rel_id = r->n_rel_id;
		    reverse_substitute(r->descr,x);
		    return 0;
		 }
	       }
	  }
	  if (*(p->descr) == '-') {
	       p = composed__get_arg0(p);
	       if (*(p->descr) == 'r') {
		    r = p;
		    composed__zero(x);
		    composed__xor(r,x);
		    *rel_id = r->n_rel_id;
		    reverse_substitute(r->descr,x);
		    return 0;
	       }
	  }
     }
     return 1;
}

void deduce(const composed *x,score *scr) {
     int n_rel_id;
     composed *dx;
     
     if (*(x->descr) == 'v') {
	  deduce(composed__get_arg0(x),scr);
	  deduce(composed__get_arg1(x),scr);
     } else if (*(x->descr) == 'a') {
	  dx = new__composed_zero(3);
	  
	  if (head_not_shallow(&n_rel_id,dx)) {
	       composed__delete(dx);
	       return;
	  } else {
	       flip(n_rel_id,dx);
	       do_score_fast(&set,scr);
	       if (scr->n_zeros == 0) {
		    composed__delete(dx);
		    model();
	       }
	  }
	  composed__delete(dx);
     } else {
	  deduce(composed__get_arg0(x),scr);
     }
}


/* resets each relation (so it is the empty relation) */
void zero_assignment(score *scr) {
     int n_rel_id;
     composed *p,*dx;
     
     for (n_rel_id = 0; n_rel_id < global__n_rels; ++n_rel_id) {
	  dx = new__composed_composed(arr_struct_rel[n_rel_id].value);
	  flip(n_rel_id,dx);
	  do_score_fast(&set,scr);
	  composed__delete(dx);
     }
}

void random_assignment(score *scr) {
     int n_rel_id;
     composed *p,*dx;
     
     dx = new__composed_composed(&set);
     
     for (n_rel_id = 0; n_rel_id < global__n_rels; ++n_rel_id) {
	  
	  composed__randomize(dx);
	  flip(n_rel_id,dx);
	  do_score_fast(&set,scr);
     }
     composed__delete(dx);
}

void repair_by_deduction(score *scr) {
     int i;
     score s;
     
     for (i = 2; i--;) {
	  printf("\n");display_assignment();
	  deduce(&set,scr);
	  composed__collect_delayed();
     }
}

unsigned int pow2(unsigned int x) {
     if (x == 0) return 1;
     if (x == 1) return 2;
     return 2*pow2(x - 1);
}

void show_progress(unsigned int zeros, int best_score_flips, int last_plateau) {
     if (SHOW_PROGRESS) printf("Best score: %u \t flips on penultimate plateau: %d \t total flips %d\n",zeros,best_score_flips,last_plateau);
}

int pick_random_pair(composed *x) {
     unsigned int i;
     composed *y;  //general temporary pointer
     int n_rel_id;
     
     for (i = RADIUS * ((double) rand()/RAND_MAX); i--;) {
	  y = new__composed_random(global__n_granularity);
	  composed__xor(y,x);
	  composed__delete(y);
     }
     if (rand() > RAND_MAX/2) {
	  n_rel_id = global__n_rels * ((double) rand()/RAND_MAX);
     } else {
	  n_rel_id = //global__n_last_failed_rel_id;
	       pick_a_rel_id(global__last_failed_sentence);
     }
     return n_rel_id;
}



/*indifferent sat variant integer types only*/
int iisat(unsigned int n_tries) {
     unsigned int i,j;
     int n_total_flips = 0;
     score scr;
     unsigned long int n_scr,n_best_scr;
     int best_scr_flips;
     int n_rel_id;
     composed *x;

     for (i = 0; i < n_tries; ++i) {
	  if (SHOW_PROGRESS) printf("Trial: %u, max flips: %u\t",i,global__n_max_flips);
	  fflush(0);
	  
	  
	  //random_assignment(&scr);
	  zero_assignment(&scr);
	  
	  repair_by_deduction(&scr);
	  
	  
	  //display(0,&set);
	  n_best_scr = scr.n_zeros;
	  best_scr_flips = 0;
	  
	  if (scr.n_zeros == 0) {
	       show_progress(n_best_scr,best_scr_flips,n_total_flips);
	       model();
	       //terminate
	       n_total_flips = 0;
	       i = n_tries;
	       j = global__n_max_flips;
	       return 0;
	  }
	  
	  for (j = 0; j < global__n_max_flips; ++j) {	  
	       x = new__composed_random(global__n_granularity);
//	       if (head_not_shallow(&n_rel_id,x)) {
		    n_rel_id = pick_random_pair(x);
//	       }
	       ++n_total_flips;

	       flip(n_rel_id,x);
	       do_score_fast(&set,&scr);

	       n_scr = scr.n_zeros;
	       
	       if (n_scr <= n_best_scr) {		    
		    
		    if (n_scr <  n_best_scr) {
			 n_best_scr = n_scr;
			 best_scr_flips = j;
			 j = 0; //restart inner loop
		    }
		    if (scr.n_zeros == 0) {
			 composed__collect_delayed();
			 composed__delete(x);

			 show_progress(n_best_scr,best_scr_flips,n_total_flips);
			 model();
			      //terminate
			 i = n_tries;
			 j = global__n_max_flips;
		    }
	       } else {
		    if (rand() < 0) {  //allow downward motion
			 n_best_scr = n_scr;
		    } else {
			 ++n_total_flips;
			 flip(n_rel_id,x); //resets the flip we made
			 do_score_fast(&set,&scr);
		    }
	       }
	       composed__collect_delayed();
	       composed__delete(x);
	  }
	  show_progress(n_best_scr,best_scr_flips,n_total_flips);
	  //composed__unsafe_mode();
     }
     return n_total_flips;
     //display(1,&set);
}

void initialize_globals() {
     unsigned int i;
     unsigned int rseed;
     score s_dummy;
     
     if (INITIAL_RANDOM_SEED) {
	  rseed = INITIAL_RANDOM_SEED;
     } else {
	  rseed = time(0);
     }
     printf("Random seed: %u\n",rseed);
     srand(rseed);
     
     intset__global_init();
     simple__global_init();
     
     global__zero = new__composed_zero(3);
     global__zero0 = new__composed_zero(0);
     global__one0 =  new__composed_zero(0);
     
     global__succ = new__composed_zero(3);
     composed__succ(global__succ);
     
     composed__one(global__one0);
     
     global__n_granularity = GRANULARITY;
     global__f_temprature = TEMPRATURE;     //used for annealing
     
     global__n_factor = 1;//simple__n_atoms();
     for (i = 0; i < global__n_granularity; ++i) {
	  global__n_factor *= 8; //8 is 2^3 3 beeing the dimension
     }
     
     global__n_rels = 0;
     init(0,global__succ); //registers all relations so 0 is just a dummy
     global__last_failed_sentence = 0;
     do_score_all(&set,&s_dummy);
     if (!intset__is_within_bounds(global__n_rels)) {
	  printf("Error: number of relations is to high: up INTSET_UNINTS in intset.h\n");
	  exit(1);
     }
     
     global__n_max_flips = FLIP_FACTOR * global__n_factor * global__n_rels * simple__n_atoms(3);
     //display(0,&set);
}



/* main */
int main(int argc, char **argv) {
     composed *zero;
     unsigned int n_tries = 0;
     unsigned int n_successes = 0;
     double f_avg;
     score dummy;
     int i;
     
     /* initialization */
     initialize_globals();
     //display(0,&set);
     /* end initialization */
     
     //simple__describe();
     printf("\n");

     /*
     printf("\n-----------------------------------------------------\n");
     composed test;
     composed *dx;
     composed__initialize(3,&test);
     dx = new__composed_random(0);
     composed__xor(dx,&test);
     composed__display(0,&test);printf("\n");
     composed__s_inv(&test);
     composed__display(0,&test);printf("\n");
     composed__s(&test);
     composed__display(0,&test);printf("\n");
     composed__s_inv(&test);
     composed__display(0,&test);printf("\n");
     composed__delete(dx);
     
     printf("\n-----------------------------------------------------\n");
     */
     
     n_tries = MAX_TRIES;
     for(i = 0; i >= 0;++i) {
	  printf("\ngranularity: %d\n",global__n_granularity);
	  
	  //isat(n_tries);
	  iisat(n_tries);
	  //annealing(n_tries);
	  //tautology();
	  
	  ++global__n_granularity;
	  global__n_factor *= 8; // 8 beeing 2^3
	  global__n_current_rel_id = global__n_rels;
	  do_score_all(&set,&dummy);
	  global__n_max_flips = FLIP_FACTOR * global__n_factor * global__n_rels * simple__n_atoms(3);
	  n_tries *= MAX_TRIES_FACTOR;
     }
     
     //isat(MAX_TRIES);
     
/*     
     do {
	  ++n_successes;
	  n_tries += isat(MAX_TRIES);
	  //n_tries += annealing(MAX_TRIES);
	  f_avg = ((double)n_tries)/n_successes;
	  printf("avrg: %u / %u = %g\n",n_successes,n_tries,f_avg);
     } while(!DESCRIBE_MODEL);
*/     
     
     cleanup();
     exit(1);
}
