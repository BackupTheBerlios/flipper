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
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include "parameters.h"
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
int global__n_rels;
char arr_rel_names[MAX_RELS][MAX_REL_NAME];
composed *arr_rels[MAX_RELS];
int global__n_current_rel_id;
composed *global__zero;
composed *global__zero0;  //0-dimensional
composed *global__one0;   //0-dimensional
composed *global__succ;

/* variables for keeping track of where things failed lastly */
composed *global__last_failed_sentence;

void register_relation(char *str_name, int n_rel_id) {
     if (n_rel_id >= global__n_rels)
	  global__n_rels = n_rel_id + 1;
     strcpy(arr_rel_names[n_rel_id],str_name);
     if (arr_rels[n_rel_id] == 0) {
	  arr_rels[n_rel_id] = new__composed_zero(3);
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
     register_relation(str_name,n_rel_id);
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

const composed *R(composed *r, int n_rel_id, int n_delta_rel_id, const composed *dx) {
          
     //if (!intset__member(global__n_current_rel_id,&r->s_relations)) return global__zero;
     
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
	  printf("\tzeros: %lld ones: %lld", x->s_score.n_zeros,x->s_score.n_ones);
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
	  printf("%s: ",arr_rel_names[i]);
	  composed__display(0,arr_rels[i]);
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
	  if (s->n_zeros != 0ull) {
	       global__last_failed_sentence = x;
	  }
	  score__copy(s,&(x->s_score));
	  return;	  
     default :
	  //composed__score(x,s);
	  composed__balanced_score(global__n_factor,x,s);
	  //printf("ones: %d, zeros: %d\n",s->n_ones,s->n_zeros);
	  if (s->n_zeros != 0ull) {
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
	  if (s->n_zeros != 0ull) {
	       global__last_failed_sentence = x;
	  }
	  return;	  
     default :
	  composed__balanced_score(global__n_factor,x,s);
	  //printf("ones: %d, zeros: %d\n",s->n_ones,s->n_zeros);
	  if (s->n_zeros != 0ull) {
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
	  return;	  
     default :
	  composed__balanced_score(global__n_factor,x,s);
	  score__copy(s,&(x->s_score));
	  return;
     }
}

int pick_a_rel_id(composed *x) {          
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
     //printf("whole evaluation:\n");
     //display(0,&set);
     }
     
     cleanup();
     exit(0);
}

const composed *evaluate(int n_rel_id, const composed *x) {
     
     global__n_current_rel_id = n_rel_id;
     F(n_rel_id,x);     
}


void random_assignment() {
     int i;
     composed *p,*x;
     score s_dummy;
     
     x = new__composed_composed(&set);
     
     for (i = 0; i < global__n_rels; ++i) {
	  
	  composed__randomize(x);
	  composed__xor(x,arr_rels[i]);
	  evaluate(i,x);
	  do_score_fast(&set,&s_dummy);
     }
     composed__delete(x);
}

/* resets each relation (so it is the empty relation) */
void zero_assignment() {
     int i;
     composed *p,*x;
     
//     x = new__composed_composed(&set);
     
     for (i = 0; i < global__n_rels; ++i) {
	  
	  x = new__composed_composed(arr_rels[i]);
	  composed__xor(x,arr_rels[i]);
	  evaluate(i,x);
	  composed__delete(x);
     }
}


const composed *flip(int n_rel_id,const composed *x) {
     composed__xor(x,arr_rels[n_rel_id]);
     return evaluate(n_rel_id,x);
}

unsigned int pow2(unsigned int x) {
     if (x == 0) return 1;
     if (x == 1) return 2;
     return 2*pow2(x - 1);
}

void show_progress(unsigned int zeros, int best_score_flips, int last_plateau) {
     if (SHOW_PROGRESS) printf("Best score: %u \t flips on penultimate plateau: %d \t total flips %d\n",zeros,best_score_flips,last_plateau);
}

/*indifferent sat variant*/
int isat(unsigned int n_tries) {
     unsigned int i,j;
     int n_total_flips = 0;
     score scr;
     double f_scr,f_best_scr;
     int best_scr_flips;
     unsigned int best_scr_zeros;
     int n_rel_id;
     composed *x;
     
     for (i = 0; i < n_tries; ++i) {
	  if (SHOW_PROGRESS) printf("Trial: %u, max flips: %u\n",i,global__n_max_flips);
	  fflush(0);
	  
	  random_assignment();
	  //zero_assignment();
	  do_score_fast(&set,&scr);
	  f_best_scr = ((double)scr.n_ones)/(scr.n_ones + scr.n_zeros);
	  best_scr_flips = 0;
	  best_scr_zeros = scr.n_zeros;
	  
	  
	  if (scr.n_zeros == 0) {
	       if (SHOW_PROGRESS) printf("Best score: %f with zeros: %u found after %u flips. Total flips %d\n",f_best_scr,best_scr_zeros,best_scr_flips,n_total_flips);
	       model();
	       //terminate
	       n_total_flips = 0;
	       i = n_tries;
	       j = global__n_max_flips;
	       return 0;
	  }
	  
	  for (j = 0; j < global__n_max_flips; ++j) {	  
	       x = new__composed_random(global__n_granularity);
	       
	       if (rand() > RAND_MAX/2) {
		    n_rel_id = global__n_rels * ((double) rand()/RAND_MAX);
	       } else {
		    n_rel_id = //global__n_last_failed_rel_id;
			 pick_a_rel_id(global__last_failed_sentence);
	       }
	       ++n_total_flips;
	       flip(n_rel_id,x);
	       
	       do_score_fast(&set,&scr);
	       
	       f_scr = ((double) scr.n_ones)/(scr.n_ones + scr.n_zeros);
	       //printf("score: %e\n",f_scr);
	       
	       
	       if (f_scr >= f_best_scr) {		    
		    
		    if (f_scr >  f_best_scr) {
			 f_best_scr = f_scr;
			 best_scr_flips = j;
			 best_scr_zeros = scr.n_zeros;
			 j = 0; //restart inner loop
			 //printf("inprovement, zeroes: %d\n",scr.n_zeros);
		    }
		    
		    if (scr.n_zeros == 0) {
			 composed__collect_delayed();
			 composed__delete(x);
			 if (SHOW_PROGRESS) printf("Best score: %f with zeros: %u found after %u flips. Total flips %d\n",f_best_scr,best_scr_zeros,best_scr_flips,n_total_flips);
			 model();
			      //terminate
			 i = n_tries;
			 j = global__n_max_flips;
		    }
		    
	       } else {
		    ++n_total_flips;
		    flip(n_rel_id,x); //resets the flip we made
		    do_score_fast(&set,&scr);

	       }
	       composed__collect_delayed();
	       composed__delete(x);
	       
	  }
	  if (SHOW_PROGRESS) printf("Best score: %f with zeros: %u found after %u flips. Total flips %d\n",f_best_scr,best_scr_zeros,best_scr_flips,n_total_flips);
	  
	  //composed__unsafe_mode();
     }
     return n_total_flips;
     //display(1,&set);
}

/*indifferent sat variant integer types only*/
int iisat(unsigned int n_tries) {
     unsigned int i,j,k;
     int n_total_flips = 0;
     score scr;
     unsigned long long int f_scr,f_best_scr;
     int best_scr_flips;
     int n_rel_id;
     composed *x,*y;
     
     for (i = 0; i < n_tries; ++i) {
	  if (SHOW_PROGRESS) printf("Trial: %u, max flips: %u\t",i,global__n_max_flips);
	  fflush(0);
	  
	  random_assignment();
	  //zero_assignment();
	  
	  do_score_fast(&set,&scr);
	  //display(0,&set);
	  f_best_scr = scr.n_zeros;
	  best_scr_flips = 0;
	  
	  if (scr.n_zeros == 0) {
	       show_progress(f_best_scr,best_scr_flips,n_total_flips);
	       model();
	       //terminate
	       n_total_flips = 0;
	       i = n_tries;
	       j = global__n_max_flips;
	       return 0;
	  }
	  
	  for (j = 0; j < global__n_max_flips; ++j) {	  
	       x = new__composed_random(global__n_granularity);
	       for (k = 0; k < 2; ++k) {
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
	       ++n_total_flips;
	       flip(n_rel_id,x);
	       
	       do_score_fast(&set,&scr);
	       
	       f_scr = scr.n_zeros;
	       
	       if (f_scr <= f_best_scr) {		    
		    
		    if (f_scr <  f_best_scr) {
			 f_best_scr = f_scr;
			 best_scr_flips = j;
			 j = 0; //restart inner loop
		    }
		    
		    if (scr.n_zeros == 0) {
			 composed__collect_delayed();
			 composed__delete(x);

			 show_progress(f_best_scr,best_scr_flips,n_total_flips);
			 model();
			      //terminate
			 i = n_tries;
			 j = global__n_max_flips;
		    }
		    
	       } else {
		    ++n_total_flips;
		    flip(n_rel_id,x); //resets the flip we made
		    do_score_fast(&set,&scr);

	       }
	       composed__collect_delayed();
	       composed__delete(x);

	       
	  }
	  show_progress(f_best_scr,best_scr_flips,n_total_flips);
	  
	  //composed__unsafe_mode();
     }
     return n_total_flips;
     //display(1,&set);
}

int annealing(unsigned int n_tries) {
     unsigned int i,j;
     int n_total_flips = 0;
     score scr;
     double f_scr,f_best_scr;
     int best_scr_flips;
     unsigned int best_scr_zeros;
     int n_rel_id;
     composed *x;
     int n_downward;
     
     for (i = 0; i < n_tries; ++i) {
	  if (SHOW_PROGRESS) printf("Trial: %u, max flips: %u\n",i,global__n_max_flips);
	  fflush(0);
	  
	  global__f_temprature = TEMPRATURE;
	  random_assignment();
	  do_score_fast(&set,&scr);
	  f_best_scr = ((double)scr.n_ones)/(scr.n_ones + scr.n_zeros);
	  best_scr_flips = 0;
	  best_scr_zeros = scr.n_zeros;
	  n_downward = 0;
	  
	  if (scr.n_zeros == 0) {
	       if (SHOW_PROGRESS) printf("Best score: %f with zeros: %u found after %u flips. Total flips %d\n",f_best_scr,best_scr_zeros,best_scr_flips,n_total_flips);
	       model();
	       //terminate
	       n_total_flips = 0;
	       i = n_tries;
	       j = global__n_max_flips;
	       return 0;
	  }
	  
	  for (j = 0; j < global__n_max_flips; ++j) {	  
	       
	       x = new__composed_random(global__n_granularity);
	       
	       if (rand() > RAND_MAX/2) {
		    n_rel_id = global__n_rels * ((double) rand()/RAND_MAX);
	       } else {
		    n_rel_id = pick_a_rel_id(global__last_failed_sentence);
	       }
	       ++n_total_flips;
	       flip(n_rel_id,x);
	       
	       do_score_fast(&set,&scr);
	       
	       f_scr = ((double) scr.n_ones)/(scr.n_ones + scr.n_zeros);
	       //printf("score: %e\n",f_scr);
	       
	       
	       if (f_scr >= f_best_scr) {		    
		    if (f_scr >  f_best_scr) {
			 f_best_scr = f_scr;
			 best_scr_flips = j;
			 best_scr_zeros = scr.n_zeros;
			 j = 0; //restart inner loop
		    }
		    if (scr.n_zeros == 0) {
			 composed__collect_delayed();
			 composed__delete(x);
			 if (SHOW_PROGRESS) printf("Best score: %f with zeros: %u found after %u flips. Total flips %d\n",f_best_scr,best_scr_zeros,best_scr_flips,n_total_flips);
			 model();
			      //terminate
			 i = n_tries;
			 j = global__n_max_flips;
		    }
		    
	       } else {
		    if ( exp((f_scr - f_best_scr)/global__f_temprature) <= ((double) rand()/RAND_MAX)) {
			 
			 ++n_total_flips;
			 flip(n_rel_id,x); //resets the flip we made
			 do_score_fast(&set,&scr);
		    } else {
			 //a downward move is allowed here
			 printf("\r%d",n_downward);
			 ++n_downward;
			 f_best_scr = f_scr;
			 best_scr_flips = 0;
			 best_scr_zeros = scr.n_zeros;
		    }
	       }
	       composed__collect_delayed();
	       composed__delete(x);
	       global__f_temprature *= COOLING_FACTOR;
	  }
	  if (SHOW_PROGRESS) printf("Best score: %f with zeros: %u found after %u flips.\n",f_best_scr,best_scr_zeros,best_scr_flips);
	  printf("downwards %d\n",n_downward);
     }
     return n_total_flips;
     //display(1,&set); 
}

/* function will run till an
 * assignment is found whose score is not 1.0
 */
void tautology() {
     unsigned int i,j;
     score score;
     int n_rel_id;
     composed *x;
     int n_actual_flips = 0;
     
     global__n_max_flips = 10000;
     
     for (i = 0; i < MAX_TRIES; ++i) {
	  printf("Trial: %u\n",i);
	  
	  random_assignment();
	  display_assignment();
	  
	  for (j = 0; j < global__n_max_flips; ++j) {	  
	       
	       x = new__composed_random(global__n_granularity);
	       //composed__display(x);printf("\n");
	       n_rel_id = global__n_rels * ((double) rand()/RAND_MAX);
	       //printf("random rel_id: %u\n",n_rel_id);
	       
	       flip(n_rel_id,x);
	       ++n_actual_flips;
	       
	       do_score_fast(&set,&score);
	       
	       if (score.n_zeros > 0) {
		    printf("Input is nontautological\n");
		    display_assignment();
		    display(0,&set);
		    //terminate
		    i = MAX_TRIES;
		    j = global__n_max_flips;
	       }
	       
	       
	       composed__collect_delayed();
	       composed__delete(x);
	  }
     }
     printf("total flips: %u\n",n_actual_flips);
     printf("score: %u\n",score.n_zeros);
     
}

/*
void test() {
     int i,n_rel_id;
     composed *x,*y;
     score score;
     double f_score;
     
     for (i = 0; i < 10;) {
	  random_assignment();
	  x = new__composed_random(global__n_granularity);                                  
	  n_rel_id = (global__n_max_rel_id + 1) * ((double) rand()/RAND_MAX);
	  y = flip(n_rel_id,x);
	  composed__score(y,&score);
	  
	  if (score.n_ones > 0) {
	       f_score = ((double)score.n_ones)/(score.n_ones + score.n_zeros);
	       printf("score: %f\n",f_score);
	       composed__minimizing_score(y,&score);
	       f_score = ((double)score.n_ones)/(score.n_ones + score.n_zeros);           
	       printf("minimized score: %f\n",f_score); 
	       composed__score(y,&score);                                                 
	       f_score = ((double)score.n_ones)/(score.n_ones + score.n_zeros);           
	       printf("score: %f\n\n",f_score);
	       ++i;
	  }
	  composed__collect_delayed();
	  composed__delete(x);
     }
}
*/

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
     simple__test();
     exit(0);
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
