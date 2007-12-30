/***************************************************************************
 *                           simple.h  -  algebras of summand type
 *                              -------------------
 *     copyright            : (C) 2005 by André Rognes
 *     email                : rognes@users.berlios.de
 *  ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#define SIMPLE_LIMBS 4 /* number of limbs */
#define MPN_ONE {1,0,0,0}  /* WARNING! length of this must equal SIMPLE_LIMBS */

typedef unsigned long int mp_limb_t;
typedef long int mp_size_t;

typedef struct _simple simple;
struct _simple {
     mp_limb_t  arr[SIMPLE_LIMBS];
};

typedef struct _score score;
struct _score {
     unsigned long int n_zeros;
     unsigned long int n_ones;
};

void score__init(score *x);
void score__pluss(DIFF_CONST score *x, score *y);
void score__not(score *x);
void score__x_p_y_m_xy_m_xy(int n_dim, unsigned int n_factor, DIFF_CONST score *y, DIFF_CONST score *xy, score *x);
void score__copy(DIFF_CONST score *x, score *y);

int simple__is_zero(DIFF_CONST simple *x);
int simple__is_one(int n_dim,DIFF_CONST simple *x);
/*int simple__arr_max(int n_dim);*/

void simple__global_init();
void simple__point(simple *x);
void simple__wqo(simple *x);
void simple__zero(simple *x);
void simple__one(int n_dim,simple *x);
void simple__or(DIFF_CONST simple *x, simple *y); 
void simple__xor(DIFF_CONST simple *x, simple *y);
void simple__and(DIFF_CONST simple *x, simple *y); 
void simple__not(int n_dim,simple *x); 
void simple__c0(simple *x);
void simple__c1(simple *x);
void simple__c2(simple *x);
void simple__p(simple *x); 
void simple__r(simple *x); 
void simple__s(simple *x);
void simple__s_inv(simple *x);
/* generate a random non-zero element */
void simple__random(simple *x);
/*void simple__next(simple *x);*/
void simple__random_reset(simple *x);
void simple__display(int n_dim, int tabs, DIFF_CONST simple *x);
void simple__describe();
void simple__score(int n_dim,DIFF_CONST simple *x,score *s);
unsigned long int simple__n_atoms(int n_dim);
void simple__test();

void table_filler__parse();
