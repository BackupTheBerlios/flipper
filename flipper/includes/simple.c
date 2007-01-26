/***************************************************************************
                         simple.c  -  simpler algebras
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
#include "defines.h"
#include "simple.h"
#include "tables.h"


unsigned long long int arr_s3_inv[sizeof(arr_s3)];

void score__init(score *x) {
     x->n_zeros = 0;
     x->n_ones = 0;
}

void score__pluss(const score *x, score *y) {
     y->n_zeros += x->n_zeros;
     y->n_ones += x->n_ones;
}

/*use of the xor swap trick*/
void score__not(score *x) {
     x->n_zeros ^= x->n_ones;
     x->n_ones ^= x->n_zeros;
     x->n_zeros ^= x->n_ones;
}

void score__x_p_y_m_xy_m_xy(int n_dim,unsigned int n_factor,const score *y, const score *xy, score *x) {
     x->n_ones  = x->n_ones + y->n_ones - xy->n_ones - xy->n_ones;
     x->n_zeros = n_factor * tables__n_atoms[n_dim] - x->n_ones;
}

void score__copy(const score *x, score *y) {
     y->n_zeros = x->n_zeros;
     y->n_ones = x->n_ones;
}

/********************* simple **********************************/


int simple__is_zero(const simple *x)
{
   return (*x == 0ull);
}

int simple__is_one(int n_dim,const simple *x)
{
   return (*x == tables__n_max_index[n_dim]);
}

int simple__arr_max(int n_dim) {
     return tables__n_max_index[n_dim];
}

/* operations on 0 (the minimal boolean algebra)*/

void simple__point(simple *x) {
     *x = const_rel2;
}

void simple__succ(simple *x) {
     *x = const_rel1;
}

void simple__zero(simple *x) {
   *x = 0ull;
}

void simple__one(int n_dim, simple *x) {
   *x = tables__n_max_index[n_dim];
}

void simple__or(const simple *x, simple *y) {
     *y |= *x;
}

void simple__xor(const simple *x, simple *y) {
     *y ^= *x;
}


void simple__and(const simple *x, simple *y) {
  *y &= *x;
}

void simple__not(int n_dim, simple *x) {
  *x ^= tables__n_max_index[n_dim];
}


void disjoin(unsigned long long int arr[], simple *x) {
     int i;
     simple ret = 0ull;
     
     for (i = 0; *x != 0ull; ++i) {
	  if (*x & 1ull) {
	       ret |= arr[i];
	       *x ^= 1ull;
	  }
	  //*x = *x / 2ull;
	  *x >>= 1;
     }
     *x = ret;
}


void simple__c0(simple *x) {
     if (!simple__is_zero(x)) {
	  simple__one(0,x);
     }
}

void simple__c1(simple *x) {
     disjoin(arr_c1,x);
}

void simple__c2(simple *x) {
     disjoin(arr_c2,x);
}

void simple__p(simple *x) {
     disjoin(arr_p3,x);
}

/*
void simple__point(simple *x) {
}
*/

void simple__r(simple *x) {
     disjoin(arr_r3,x);
}

void simple__s(simple *x) {
     disjoin(arr_s3,x);
}

//inverse of s (also additive)
void simple__s_inv(simple *x) {
     disjoin(arr_s3_inv,x);
}


/*
 * note does not return 0
 * */
void simple__random(simple *x) {
     *x = arr_exp[(int)((tables__n_atoms[3]) * ((double) rand()/RAND_MAX))];
     //if (*x * 2 >= tables__n_max_index[3]) printf("random: %llu\n",*x);
     /*
     static simple s = 0ull;
     *x = s; 
     ++s;
     s = s % (tables__n_max_index3 + 1);
     *x ^= s;
     */
}

void simple__random_reset(simple *x) {
     *x = ((tables__n_max_index[3] + 1) * ((double) rand()/RAND_MAX));
     //printf("random: %llu\n",*x);
}

void simple__next(simple *x) {     
     static simple s = 0ull;
     *x = s;
     ++s;
     s = s % (tables__n_max_index[3] + 1ull);
     *x ^= s;
}


int evaluate_at(const simple *x,int j) {
     simple s;
     int i;
     
     s = *x;
     s >>= j;
     return s & 1ull;
}

void display_binary(int n_dim, unsigned int tabs,const simple *x) {
     simple s;
     unsigned int i;
     
     for(i = 0; i < tabs; ++i) printf(" ");
     if (n_dim == 3 && tables__n_atoms[n_dim] == 8) {
	  
	  printf("%d",evaluate_at(x,4));
	  printf("%d",evaluate_at(x,6));
	  printf("%d",evaluate_at(x,1));
	  printf("%d",evaluate_at(x,7));
	  //printf("\n");
	  //for(i = 0; i < tabs+1; ++i) printf(" ");
	  printf("%d",evaluate_at(x,2));
	  printf("%d",evaluate_at(x,3));
	  printf("%d",evaluate_at(x,0));  
	  printf("%d",evaluate_at(x,5));
     } else {
	  s = *x;
	  for (i = 0; i < tables__n_atoms[n_dim]; ++i) {
	       if (s & 1ull) {
		    printf("1");
		    s ^= 1ull;
	       } else {
		    printf("0");
	       }
	       s >>= 1;
	  }
     }
}


void simple__display(int n_dim, int tabs,const simple *x) {
     //printf("%d:",*x);
     display_binary(n_dim, tabs,x);
}

void plain_display(int n_dim, const simple x) {
     printf(" ");
     simple__display(n_dim,0,&x);
     printf("\n\n");
}

/*
 * describes the simple algebra
 */
/*
void simple__describe() {
     int i;
     simple pow2;
     
     for (i = 0,pow2 = 1; i < simple__n_atoms(3); ++i,pow2 <<= 1) {
	  if (arr_r3[pow2] == pow2) {
	       printf("diogonal:\n");
	       plain_display(3,pow2);
	       printf("x axis:\n");
	       plain_display(3,pow2 ^ arr_c2[pow2]);
	       printf("y axis:\n");
	       plain_display(3,pow2 ^ arr_r3[arr_c2[pow2]]);
	       printf("z axis:\n");
	       plain_display(3,pow2 ^ arr_r3[arr_r3[arr_c2[pow2]]]);
	  }
     }
     for (i = 0,pow2 = 1; i < simple__n_atoms(3); ++i,pow2 <<= 1) {
	  printf("s(");
	  simple__display(3,0,&pow2);
	  printf(") = ");
	  simple__display(3,0,&arr_s3[pow2]);
	  printf("\n");
	  
	  printf("r(");
	  simple__display(3,0,&pow2);
	  printf(") = ");
	  simple__display(3,0,&arr_r3[pow2]);
	  printf("\n");
	  
	  printf("p(");
	  simple__display(3,0,&pow2);
	  printf(") = ");
	  simple__display(3,0,&arr_p3[pow2]);
	  printf("\n");
	  
	  printf("c(");
	  simple__display(3,0,&pow2);
	  printf(") = ");
	  simple__display(3,0,&arr_c2[pow2]);
	  printf("\n");
	  
	  printf("r(%d) = %d\n",pow2,arr_r[pow2]);
	  printf("s(%d) = %d\n",pow2,arr_s[pow2]);
	  printf("p(%d) = %d\n",pow2,arr_p[pow2]);
	  printf("c(%d) = %d\n",pow2,arr_c0[pow2]);
	  
	  printf("\n");
     }
}
*/


unsigned long long int bitcount(unsigned long long int n) {
     unsigned long long int ret = 0ull;
     while (n != 0ull) {
	  if (n & 1ull) {
	       ++ret;
	       n ^= 1ull;
	  }
	  n >>= 1;
     }
     return ret;
}


// taken from Gurmeet Singh Manku at http://www-db.stanford.edu/~manku/bitcount/bitcount.html
#define TWO(c)     (0x1ull << (c))
#define MASK(c)    (((unsigned long long int)(-1)) / (TWO(TWO(c)) + 1ull))
#define COUNT(x,c) ((x) & MASK(c)) + (((x) >> (TWO(c))) & MASK(c))
     
int bitcount2(unsigned long long int n)
{
     n = COUNT(n, 0) ;
     n = COUNT(n, 1) ;
     n = COUNT(n, 2) ;
     n = COUNT(n, 3) ;
     n = COUNT(n, 4) ;
     n = COUNT(n, 5) ;    //for 64-bit integers
     return n ;
}

#define MASK_01010101 (((unsigned int)(-1))/3)
#define MASK_00110011 (((unsigned int)(-1))/5)
#define MASK_00001111 (((unsigned int)(-1))/17)

int bitcount3 (unsigned int n)
{
     //for 32-bits tall
         n = (n & MASK_01010101) + ((n >> 1) & MASK_01010101) ; 
         n = (n & MASK_00110011) + ((n >> 2) & MASK_00110011) ; 
         n = (n & MASK_00001111) + ((n >> 4) & MASK_00001111) ; 
         return n % 255 ;
}

unsigned int simple__n_atoms(int n_dim) {
     return tables__n_atoms[n_dim];
}

void simple__score(int n_dim, const simple *x, score *ret) {
     ret->n_ones = bitcount(*x);
     ret->n_zeros = tables__n_atoms[n_dim] - ret->n_ones;
     //printf("x: %d, dim: %d, ones: %d, zeros: %d\n",*x,n_dim,ret->n_ones,ret->n_zeros);
}

void simple__test() {
     simple x;
     simple__succ(&x);
     simple__r(&x);    
     simple__r(&x);
     //simple__r(&x);
     simple__display(3,0,&x);
     printf(":%lld\n",x);
     simple__c2(&x);
     simple__display(2,0,&x);
     printf(":%lld\n",x);
     printf("\n");
}


void simple__global_init() {
     int i,j;
     // initialize the inverse of the s3 operation, namely s3_inv
     for (i = 0; i < tables__n_atoms[3];++i)
	  arr_s3_inv[i] = 0ull;
     
     for (i = 0; i < tables__n_atoms[3]; ++i) {
	  
	  if (arr_s3[i] != 0ull) {
	       for (j = 0; j < tables__n_atoms[3]; ++j) {
		    if (evaluate_at(&(arr_s3[i]),j)) {
			 arr_s3_inv[j] |= arr_exp[i];
		    }
	       }
	  }
     }
}
