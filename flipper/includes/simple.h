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


typedef unsigned long long int simple;
typedef struct _score score;

struct _score {
     unsigned long long int n_zeros;
     unsigned long long int n_ones;
};

void score__init(score *x);
void score__pluss(const score *x, score *y);
void score__not(score *x);
void score__x_p_y_m_xy_m_xy(int n_dim, unsigned int n_factor, const score *y, const score *xy, score *x);
void score__copy(const score *x, score *y);

int simple__is_zero(const simple *x);
int simple__is_one(int n_dim,const simple *x);
int simple__arr_max(int n_dim);

void simple__point(simple *x);
void simple__succ(simple *x);
void simple__zero(simple *x);
void simple__one(int n_dim,simple *x);
void simple__or(const simple *x, simple *y); 
void simple__xor(const simple *x, simple *y);
void simple__and(const simple *x, simple *y); 
void simple__not(int n_dim,simple *x); 
void simple__c0(simple *x);
void simple__c1(simple *x);
void simple__c2(simple *x);
void simple__p(simple *x); 
void simple__r(simple *x); 
void simple__s(simple *x);
/* generate a random non-zero element */
void simple__random(simple *x);
void simple__next(simple *x);
void simple__random_reset(simple *x);
void simple__display(int n_dim, int tabs,const simple *x);
void simple__describe();
void simple__score(int n_dim,const simple *x,score *s);
unsigned int simple__n_atoms(int n_dim);
void simple__test();
