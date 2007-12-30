/***************************************************************************
 *                           composed.h  -  algebras composed of simpler ones
 *                              -------------------
 *     copyright            : (C) 2005 by André Rognes
 *     email                : rognes@users.berlios.de
 *  ***************************************************************************/

/***************************************************************************
 *  *                                                                         *
 *  *   This program is free software; you can redistribute it and/or modify  *
 *  *   it under the terms of the GNU General Public License as published by  *
 *  *   the Free Software Foundation; either version 2 of the License, or     *
 *  *   (at your option) any later version.                                   *
 *  *                                                                         *
 *  ***************************************************************************/

/* 
 * relation type
 * should be kept minimal in representation
 */

typedef struct _composed composed;


struct _composed {
     int      is_simple;
     simple    n_simple;
     score     s_score;
     int n_dim;
     char *descr;     
     intset *relations;
     composed *arg0;
  /*     union { */
  composed *arg1;  /*for disjunction only*/
  composed *axyz;  /*for universal closure only*/
  int n_rel_id;    /*for atomic formulae only*/
  /*     }; */
     DIFF_QUADRANT_DECLARATION;
};

/* returns an uninitialized composed */
composed *new__composed(int n_dim);
composed *new__composed_zero(int n_dim);
composed *new__composed_composed(DIFF_CONST composed *p);
/* generate a random sparse non-zero composed */
composed *new__composed_random(int n_granularity);
/* randomizes a given composed whithout changing its shape */
void composed__randomize(composed *x);

void composed__delete(composed *x);
void composed__delayed_delete(composed *x);
void composed__collect_delayed();
void composed__unsafe_mode();
void composed__clear_stack();

void composed__initialize(int n_dim,composed *x);

void composed__display(int tabs,DIFF_CONST composed *x);
int composed__sane(DIFF_CONST composed *x);
composed *composed__id(composed *x);
void composed__stats();

void composed__set_arg0(composed *this, composed *arg0);
void composed__set_arg1(composed *this, composed *arg1);
composed *composed__get_arg0(DIFF_CONST composed *this);
composed *composed__get_arg1(DIFF_CONST composed *this);

/* constants */
void composed__point(composed *x);
void composed__wqo(composed *x);

/* polyadic homomorphisms */
void composed__zero(composed *x);
void composed__one(composed *x);
void composed__or(DIFF_CONST composed *x, composed *y); 
void composed__xor(DIFF_CONST composed *x, composed *y); 
void composed__and(DIFF_CONST composed *x, composed *y); 
void composed__not(composed *x); 
void composed__p(composed *x); 
void composed__r(composed *x);
void composed__s(composed *x);
void composed__s_inv(composed *x);
/* quantifier-like operations */
void composed__c(int n_projection, composed *x);
void composed__t(int n_projection, composed *x);
void composed__axyz(composed *x);
void composed__c2(composed *x);  /*used in axyez*/

/* score related */
void composed__score(composed* x, score *ret);
void composed__balanced_score(unsigned int factor, DIFF_CONST composed* x, score *ret);
void composed__minimizing_score(composed* x, score *ret);
int composed__fast_score(DIFF_CONST composed *x);
