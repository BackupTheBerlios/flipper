/***************************************************************************
                    composed.c  -  algebras composed of simpler ones
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
#include <inttypes.h>
#include "parameters.h"
#include "intset.h"
//#include <assert.h>
#include "defines.h"
#include "simple.h"
#include "composed.h"

/* general principles:
 * Every object is refered to by only one pointer,
 * except within the scope of a single function.
 * Functions that produce new instances of things
 * have a name begining with new__ ...
 * There is no checking wether arguments are null pointers.
 */

/* internal operations */

/*
 * if _composed is simple, quadrants may contain garbage
 * but not allocated stuff.
 * othewise n_simple may contain garbage
 */

//int global__n_allocated = 0;
//int global__n_max_allocated = 0;
composed *global__composed_free = 0;
composed *global__composed_delayed = 0;
composed *mem_pop(); //implemented below
composed * (*global__mem_pop)() = &mem_pop;

/*
 * for use in macros
 */
composed *composed__id(composed *x) {
     //assert(composed__sane(x));
     return x;
}

void composed__clear_stack() {
     composed *current;
     composed *next;
     
     for(current = global__composed_free;current != 0; current = next) {
	  next = current->arg0;
	  free(current);
     }
}

/*
 * shallow clone
 * only for use within the scope of a function
 */
composed *new__shallow_clone(int n_dim, const composed *x) {
   composed *ret;
   
   ret = new__composed(n_dim);
   if (x->is_simple) 
     {	
	ret->is_simple = 1;
	ret->n_simple = x->n_simple;
     }
   else 
     {
	ret->is_simple = 0;
	DIFF_ASSIGN_FOR_EACH_QUADRANT(ret,x,composed__id);
     }
   
   return ret;
}

void assign(composed *x,const composed *y) {
     if (x->is_simple) {
	  if (y->is_simple) {
	       x->n_simple = y->n_simple;
	  } else {
	       x->is_simple = 0;
	       DIFF_ASSIGN_FOR_EACH_QUADRANT(x,y,new__composed_composed);
	  }
     } else {
	  if (y->is_simple) {
	       DIFF_FOR_EACH_QUADRANT(x,composed__delete);
	       x->is_simple = 1;
	       x->n_simple = y->n_simple;
	  } else {
	       DIFF_FOR_EACH_QUADRANT(x,composed__delete);
	       DIFF_ASSIGN_FOR_EACH_QUADRANT(x,y,new__composed_composed);
	  }
     }
//assert(composed__sane(x));
}

composed *new__composed_simple(int n_dim, const simple *x) {
     composed *ret;
     ret = new__composed(n_dim);
     ret->is_simple = 1;
     ret->n_simple = *x;
     return ret;
}

void mem_push(composed *x) {
     x->arg0 = global__composed_free;
     global__composed_free = x;
}

/* pops a struct of the free-stack */
composed *mem_pop() {
     static composed *ret;
     
     if (global__composed_free == 0) {
	  return (composed *) malloc(sizeof(composed));
     } else {
	  ret = global__composed_free;
	  global__composed_free = ret->arg0;
	  ret->arg0 = 0;
     }
     return ret;
}

/* a version of mem_pop that does not check wether the free-stack is empty*/
composed *unsafe_mem_pop() {
     static composed *ret;
     ret = global__composed_free;
     global__composed_free = ret->arg0;
     return ret;
}

/* switches to a version of mem_pop that does not check wether the free-stack is empty*/
void composed__unsafe_mode() {
     global__mem_pop = &unsafe_mem_pop;
}

/* note not deep*/
void composed__shallow_delete(composed *x) {
     
     //--global__n_allocated;
      
     mem_push(x);
}

/*************************
 * exported opperations
 *
 *************************/





/* creates an uninitialized instance*/
composed *new__composed(int n_dim) {
     composed *ret;

     //++global__n_allocated;
     //if (global__n_allocated > global__n_max_allocated) global__n_max_allocated = global__n_allocated;

     //ret = mem_pop();
     ret = (*global__mem_pop)();
     
     ret->n_dim = n_dim;
     ret->relations = 0;
     return ret;
}

void composed__initialize(int n_dim, composed *x) {
     x->is_simple = 1;
     x->n_dim = n_dim;
     x->relations = 0;
     x->axyz = 0;
     simple__zero(&(x->n_simple));
     score__init(&(x->s_score));
//assert(composed__sane(x));
}

composed *new__composed_zero(int n_dim) {
     composed *ret;
     ret = new__composed(n_dim);
     composed__initialize(n_dim,ret);
     return ret;
}



composed *new__composed_composed(const composed *x) {
  composed *ret;
  ret = new__composed(x->n_dim);
  if (x->is_simple) {
    ret->is_simple = 1;
    ret->n_simple = x->n_simple;
  } else {
    ret->is_simple = 0;
    DIFF_ASSIGN_FOR_EACH_QUADRANT(ret,x,new__composed_composed);
  }
  return ret;
}

void composed__set_arg0(composed *this, composed *x) {
  this->arg0 = x;
}

void composed__set_arg1(composed *this, composed *x) {
  this->arg1 = x;
}

composed *composed__get_arg0(const composed *this) {
  return this->arg0;
}

composed *composed__get_arg1(const composed *this) {
  return this->arg1;
}

void composed__delete(composed *x) {
  if (x->is_simple) {
    composed__shallow_delete(x);
  } else {
    DIFF_FOR_EACH_QUADRANT(x,composed__delete);
    composed__shallow_delete(x);
  }
}

void composed__delayed_delete(composed *x) {
     x->arg0 = global__composed_delayed;
     global__composed_delayed = x;
}

void collect_delayed(composed *x) {
     if (x == 0) return;
     collect_delayed(x->arg0);
     composed__delete(x);
}

void composed__collect_delayed() {
     //collect_delayed(global__composed_delayed);
     composed *current;
     composed *next;
     
     for(current = global__composed_delayed;current != 0; current = next) {
	  next = current->arg0;
	  composed__delete(current);
     }
     
     global__composed_delayed = 0;
}


/*
 * 
void composed__delayed_delete(composed *x) {
     composed *holder;
     holder = new__composed(0);
     holder->arg0 = global__composed_delayed;
     global__composed_delayed = holder;
     holder->arg1 = x;
}

void collect_delayed(composed *x) {
     if (x == 0) return;
     collect_delayed(x->arg0);
     composed__delete(x->arg1);
     composed__shallow_delete(x);
}

void composed__collect_delayed() {
     collect_delayed(global__composed_delayed);
     global__composed_delayed = 0;
}
 * */


void composed__point(composed *x) {
     if (x->is_simple) {
	  simple__point(&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__delete);
	  x->is_simple = 1;
	  simple__point(&(x->n_simple));
     }
}

void composed__succ(composed *x) {
     if (x->is_simple) {
	  simple__succ(&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__delete);
	  x->is_simple = 1;
	  simple__point(&(x->n_simple));
     }
}

void composed__zero(composed *x) {
     if (x->is_simple) {
	  simple__zero(&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__delete);
	  x->is_simple = 1;
	  simple__zero(&(x->n_simple));
     }
//assert(composed__sane(x));
}

void composed__one(composed *x) {
     if (x->is_simple) {
	  simple__one(x->n_dim,&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__delete);
	  x->is_simple = 1;
	  simple__one(x->n_dim,&(x->n_simple));
     }
//assert(composed__sane(x));
}

void composed__or(const composed *x, composed *y) {
  composed temp;

     composed__initialize(x->n_dim,&temp);
  if (x->is_simple)
    {
       /* thisone prunes for scarse x's */
       if (simple__is_zero(&(x->n_simple))) return;
      if (y->is_simple) {
	  /* both are simple */
	  simple__or(&(x->n_simple),&(y->n_simple)); 
	} else {
	  /* x is simple y is composed */
	     
	     DIFF_SIMPLE_TO_COMPOSED(&(x->n_simple),(&temp));
	  DIFF_PAIRWISE_FOR_EACH_QUADRANT((&temp),y,composed__or);
	  DIFF_FOR_EACH_QUADRANT((&temp),composed__shallow_delete);
	}
    } else {
      if (y->is_simple) {
	/* x is composed y is simple */
	   if (simple__is_one(y->n_dim,&(y->n_simple))) return;
	DIFF_SIMPLE_TO_COMPOSED(&(y->n_simple),y);
	DIFF_PAIRWISE_FOR_EACH_QUADRANT(x,y,composed__or);
      } else {
	/* x is composed y is composed */
	DIFF_PAIRWISE_FOR_EACH_QUADRANT(x,y,composed__or);
      }
    }
//assert(composed__sane(x));
}

void composed__xor(const composed *x, composed *y) {
     composed temp;
     
     composed__initialize(x->n_dim,&temp);
     if (x->is_simple)
     {
	  /* thisone prunes for scarse x's */
	  if (simple__is_zero(&(x->n_simple))) return;
	  if (y->is_simple) {
	       /* both are simple */
	       simple__xor(&(x->n_simple),&(y->n_simple));
	  } else {
	       /* x is simple y is composed */
	       
	       DIFF_SIMPLE_TO_COMPOSED(&(x->n_simple),(&temp));
	       DIFF_PAIRWISE_FOR_EACH_QUADRANT((&temp),y,composed__xor);
	       DIFF_FOR_EACH_QUADRANT((&temp),composed__shallow_delete);
	       
	  }
     } else {
	  if (y->is_simple) {
	       /* x is composed y is simple */
	       DIFF_SIMPLE_TO_COMPOSED(&(y->n_simple),y);
	       DIFF_PAIRWISE_FOR_EACH_QUADRANT(x,y,composed__xor);
	  } else {
	       /* x is composed y is composed */
	       DIFF_PAIRWISE_FOR_EACH_QUADRANT(x,y,composed__xor);
	  }
     }
     //assert(composed__sane(x));
}

void composed__and(const composed *x, composed *y) {
  composed temp;
     
          composed__initialize(x->n_dim,&temp);
  if (x->is_simple)
    {
       /* thisone prunes for dense x's */
       if (simple__is_one(x->n_dim,&(x->n_simple))) return;
      if (y->is_simple) {
	/* both are simple */
	simple__and(&(x->n_simple),&(y->n_simple));
      } else {
	/* x is simple y is composed */
	DIFF_SIMPLE_TO_COMPOSED(&(x->n_simple),(&temp));
	DIFF_PAIRWISE_FOR_EACH_QUADRANT((&temp),y,composed__and);
	DIFF_FOR_EACH_QUADRANT((&temp),composed__shallow_delete);
      }
    } else {
      if (y->is_simple) {
        /* x is composed y is simple */
	   if (simple__is_zero(&(y->n_simple))) return;
        DIFF_SIMPLE_TO_COMPOSED(&(y->n_simple),y);
        DIFF_PAIRWISE_FOR_EACH_QUADRANT(x,y,composed__and);
      } else {
        /* x is composed y is composed */
        DIFF_PAIRWISE_FOR_EACH_QUADRANT(x,y,composed__and);
      }
    }
//assert(composed__sane(x));
}
void composed__not(composed *x) {
     if (x->is_simple) {
	  simple__not(x->n_dim,&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__not);
     }
//assert(composed__sane(x));
}

/* for use in macros */
void zero_first(composed *first,const composed *second) {
     composed__zero(first);
}


void composed__axyz(composed *x) {
     x->n_dim = 0;
}

/* cylindrification */
void composed__c0(composed *x) {
          
     --(x->n_dim);
     
     if (x->is_simple) {
	  simple__c0(&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__c0);
	  DIFF_FOR_EACH_QUADRANT_C0(x,composed__or);
	  DIFF_FOR_EACH_QUADRANT_C0(x,assign);
     }
//assert(composed__sane(x));
}

void composed__c1(composed *x) {
          
     --(x->n_dim);
     
     if (x->is_simple) {
	  simple__c1(&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__c1);
	  DIFF_FOR_EACH_QUADRANT_C1(x,composed__or);
	  DIFF_FOR_EACH_QUADRANT_C1(x,assign);
     }
//assert(composed__sane(x));
}

void composed__c2(composed *x) {
          
     --(x->n_dim);
     
     if (x->is_simple) {
	  simple__c2(&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__c2);
	  DIFF_FOR_EACH_QUADRANT_C2(x,composed__or);
	  DIFF_FOR_EACH_QUADRANT_C2(x,assign);
     }
//assert(composed__sane(x));
}

void composed__c(int n_projection, composed *x) {
     score s;
     switch(n_projection) {
     case 0 :
	  composed__c0(x);
	  break;
     case 1 :
	  composed__c1(x);
	  break;
     case 2 :
	  composed__c2(x);
	  break;
     }
}






/* sloppy dimention preserving cylindrification */
void composed__t0(composed *x) {
     
     if (x->is_simple) {
	  simple__one(x->n_dim,&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__t0);
	  DIFF_FOR_EACH_QUADRANT_C0(x,composed__or);
	  DIFF_FOR_EACH_QUADRANT_C0(x,assign);
     }
//assert(composed__sane(x));
}

void composed__t1(composed *x) {

     if (x->is_simple) {
	  simple__one(x->n_dim,&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__t1);
	  DIFF_FOR_EACH_QUADRANT_C1(x,composed__or);
	  DIFF_FOR_EACH_QUADRANT_C1(x,assign);
     }
//assert(composed__sane(x));
}

void composed__t2(composed *x) {
     
     if (x->is_simple) {
	  simple__one(x->n_dim,&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__t2);
	  DIFF_FOR_EACH_QUADRANT_C2(x,composed__or);
	  DIFF_FOR_EACH_QUADRANT_C2(x,assign);
     }
//assert(composed__sane(x));
}

void composed__t(int n_projection, composed *x) {
     switch(n_projection) {
     case 0 :
	  composed__t0(x);
	  break;
     case 1 :
	  composed__t1(x);
	  break;
     case 2 :
	  composed__t2(x);
	  break;
     }
}

/* substitutions */
void composed__p(composed *x) {
   composed temp;
     
          composed__initialize(x->n_dim,&temp);
   
   if (x->is_simple) {
	simple__p(&(x->n_simple));
   } else {
	DIFF_FOR_EACH_QUADRANT(x,composed__p);
	DIFF_ASSIGN_FOR_EACH_QUADRANT((&temp),x,composed__id);
	DIFF_ASSIGN_FOR_EACH_QUADRANT_P(x,(&temp),composed__id);
   }
//assert(composed__sane(x));
}

void composed__r(composed *x) {
     composed temp;
     
          composed__initialize(x->n_dim,&temp);
     if (x->is_simple) {
	  simple__r(&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__r);
	  DIFF_ASSIGN_FOR_EACH_QUADRANT((&temp),x,composed__id);
	  DIFF_ASSIGN_FOR_EACH_QUADRANT_R(x,(&temp),composed__id);
     }
//assert(composed__sane(x));
}

void composed__s(composed *x) {
     composed temp;
     
          composed__initialize(x->n_dim,&temp);
     
     if (x->is_simple) {
	  simple__s(&(x->n_simple));
     } else {
	  DIFF_FOR_EACH_QUADRANT(x,composed__s);
	  DIFF_ASSIGN_FOR_EACH_QUADRANT((&temp),x,composed__id);
	  DIFF_ASSIGN_FOR_EACH_QUADRANT_S(x,(&temp),new__composed_composed);
	  DIFF_FOR_EACH_QUADRANT((&temp),composed__delete);
     }
//assert(composed__sane(x));
}

composed *new__composed_random(int n_granularity) {
     composed *ret;
     
     int n_index;
     
     
     if (n_granularity == 0) {
	  ret = new__composed(3);
	  ret->is_simple = 1;
	  simple__random(&(ret->n_simple));
     } else {
	  ret = new__composed(3);
	  ret->is_simple = 1;  //TODO: remove this line
	  simple__zero(&(ret->n_simple));
	  DIFF_SIMPLE_TO_COMPOSED(&(ret->n_simple),ret);
	  n_index = DIFF_QUADRANTS * ((double) rand()/RAND_MAX);
	  composed__delete(ret->pQuadrant[n_index]);
	  ret->pQuadrant[n_index] = new__composed_random(n_granularity -1);
	  
     }
     //assert(composed__sane(ret));
     return ret;
}

void composed__randomize(composed *x) {
     int i;
     if (x->is_simple) {
	  simple__random_reset(&(x->n_simple));
     } else {
	  for (i = 0; i < DIFF_QUADRANTS; ++i) {
	       composed__randomize(x->pQuadrant[i]);
	  }
     }
     
}

void composed__display(int tabs,const composed *x) {
     int i;
          
     if (x->is_simple) {
	  simple__display(x->n_dim,tabs,&(x->n_simple));
	  //printf(" %d",x->n_simple);
     } else {
	  printf("(");
	  for (i = 0; i < DIFF_QUADRANTS; ++i) {
	       composed__display(tabs,x->pQuadrant[i]);
	  }
	  printf(")");
     }
}

void composed__stats() {
     //printf("max allocated: %d\n",global__n_max_allocated);
}

int composed__sane(const composed *x) {
     if (x->is_simple != 0 && x->is_simple != 1) return 0;
     return 1;
}

/*calculates a score (0 means true) */
void composed__score(composed *x, score *ret) {
     int i;
     score s;
     
     score__init(ret);
     
     if (x->is_simple) {
	  //ret = (double)x->n_simple/simple__arr_max();
	  simple__score(x->n_dim, &(x->n_simple),ret);	  
     } else {
	  for (i = 0; i < DIFF_QUADRANTS; ++i) {
	       composed__score(x->pQuadrant[i],&s);
	       score__pluss(&s,ret);
	  }
     }
}

/*calculates a score (0 means true) */
void composed__balanced_score(unsigned int factor, const composed *x, score *ret) {
     int i;
     score s;
     
     score__init(ret);
     
     if (x->is_simple) {
	  simple__score(x->n_dim,&(x->n_simple),ret);
	  ret->n_ones *= factor;
	  ret->n_zeros *= factor;
     } else {
	  for (i = 0; i < DIFF_QUADRANTS; ++i) {
	       composed__balanced_score(factor/8, x->pQuadrant[i],&s);
	       score__pluss(&s,ret);
	  }
     }
}


/*calculates a score and simplyfies x iff possible*/
void composed__minimizing_score(composed *x, score *ret) {
     int i;
     score s;
     
     score__init(ret);
     
     if (x->is_simple) {
	  //ret = (double)x->n_simple/simple__arr_max();
	  simple__score(x->n_dim, &(x->n_simple),ret);	  
     } else {
	  for (i = 0; i < DIFF_QUADRANTS; ++i) {
	       composed__score(x->pQuadrant[i],&s);
	       score__pluss(&s,ret);
	  }
	  
	  if (ret->n_ones == 0) {
	       DIFF_FOR_EACH_QUADRANT(x,composed__delete);
	       x->is_simple = 1;
	       simple__zero(&(x->n_simple));
	       //ret->n_ones = 0;
	       //ret->n_zeros = simple__n_atoms();
	  } else if (ret->n_zeros == 0) {                                                   
	       DIFF_FOR_EACH_QUADRANT(x,composed__delete);
	       x->is_simple = 1;                                                     
	       simple__one(x->n_dim,&(x->n_simple));                                          
	       //ret->n_ones = 0;                                                    
	       //ret->n_zeros = simple__n_atoms();                                   
	  }
	  
	  
     }
}

int composed__fast_score(const composed *x) {
     if (x->is_simple) {
	  if (simple__is_one(x->n_dim,&(x->n_simple))) {
	       return 1;
	  } else {
	       return 0;
	  }
     } else {
	  return composed__fast_score(x->pQuadrant[0]);
     }
}
