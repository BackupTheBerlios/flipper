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

#include "headers.h"
#include "defines.h"
#include "simple.h"
#include "tables.h"



static void mpn__zero (mp_limb_t x[]) {
     unsigned int i;
   
     for (i = SIMPLE_LIMBS; i--;) {
	  x[i] = 0;
     }
}

static void mpn__binary_one (mp_limb_t x[]) {
          mpn__zero(x);
          ++x[0];
}

static void mpn__double(mp_limb_t x[]) {
     unsigned int i, carry0, carry1;
     
     carry0 = 0;
     for (i = 0; i < SIMPLE_LIMBS; ++i) {
	  carry1 = x[i] >> (ULONG_BIT - 1);
	  x[i] <<= 1;
	  x[i] |= carry0;
	  carry0 = carry1;
     }
}

static void mpn__copy(DIFF_CONST mp_limb_t from[],mp_limb_t to[]) {
     unsigned int i;
     for (i = SIMPLE_LIMBS; i--;) {
	  to[i] = from[i];
     }
}

static void mpn__decr(DIFF_CONST mp_limb_t from[], mp_limb_t to[]) {
     unsigned int i,carry;
     
     carry = 1;
     for (i = 0; i < SIMPLE_LIMBS; ++i) {
	  to[i] = from[i] - carry;
	  if (to[i] != ULONG_MAX) carry = 0;
     }
}

static void mpn__or(DIFF_CONST mp_limb_t from[],mp_limb_t to[]) {
     unsigned int i;
     
     for (i = SIMPLE_LIMBS; i--;) {
	  to[i] |= from[i];
     }
}

static void mpn__xor(DIFF_CONST mp_limb_t from[],mp_limb_t to[]) {
     unsigned int i;
     
     for (i = SIMPLE_LIMBS; i--;) {
	  to[i] ^= from[i];
     }
}

static void mpn__and(DIFF_CONST mp_limb_t from[],mp_limb_t to[]) {
     int i;
          
     for (i = SIMPLE_LIMBS; i--;) {
	  to[i] &= from[i];
     }
}

int mpn__is_zero(DIFF_CONST mp_limb_t x[]) {
     unsigned int i;
     mp_limb_t acc;
     
     acc = x[0];
     for (i = SIMPLE_LIMBS; i--;) {
	  acc |= x[i];
     }
     return !acc;
}

static unsigned int mpn__popcount(DIFF_CONST mp_limb_t x[]) {
     unsigned int ret = 0;
     mp_limb_t n;
     unsigned int i, carry;
     
     for (i = SIMPLE_LIMBS;i--;) {
	  n = x[i];
	  while (n != 0) {
	       carry = n & 1;
	       ret += carry;
	       n >>= 1;
	  }
     }
     return ret;
}





mp_limb_t arr_s3_inv[sizeof(arr_s3)][SIMPLE_LIMBS]; /*TODO this is way oversized*/

/*************************** score ******************************************/

void score__init(score *x) {
     x->n_zeros = 0;
     x->n_ones = 0;
}
  
void score__pluss(DIFF_CONST score *x, score *y) {
     y->n_zeros += x->n_zeros;
     y->n_ones += x->n_ones;
}
  
/*use of the xor swap trick*/
void score__not(score *x) {
     x->n_zeros ^= x->n_ones;
     x->n_ones ^= x->n_zeros;
     x->n_zeros ^= x->n_ones;
}

void score__x_p_y_m_xy_m_xy(int n_dim,unsigned int n_factor,DIFF_CONST score *y, DIFF_CONST score *xy, score *x) {
     x->n_ones  = x->n_ones + y->n_ones - xy->n_ones - xy->n_ones;
     x->n_zeros = n_factor * tables__n_atoms[n_dim] - x->n_ones;
}

void score__copy(DIFF_CONST score *x, score *y) {
     y->n_zeros = x->n_zeros;
     y->n_ones = x->n_ones;
}

/********************* simple **********************************/

int simple__is_zero(DIFF_CONST simple *x)
{
      return mpn__is_zero(x->arr);
}

int simple__is_one(int n_dim,DIFF_CONST simple *x)
{
     int i;
     for (i = 0; i < SIMPLE_LIMBS; ++i) {
	  if (x->arr[i] != tables__n_max_index[n_dim][i]) return 0;
     }
     return 1;
}
  /*
int simple__arr_max(int n_dim) {
     return tables__n_max_index[n_dim];
}
  */

/* operations on 0 (the minimal boolean algebra)*/
void simple__point(simple *x) {
     mpn__copy(const_rel2,x->arr);
  
}

void simple__wqo(simple *x) {
  
     mpn__copy(const_rel1,x->arr);
}

void simple__zero(simple *x) {
     mpn__zero(x->arr);
}

void simple__one(int n_dim, simple *x) {
  int i;
  for (i = 0; i < SIMPLE_LIMBS;++i) {
    
      mpn__copy(tables__n_max_index[n_dim],x->arr);
  }
}

void simple__or(DIFF_CONST simple *x, simple *y) {
     mpn__or(x->arr, y->arr);
}

void simple__xor(DIFF_CONST simple *x, simple *y) {
     mpn__xor(x->arr, y->arr);
}

void simple__and(DIFF_CONST simple *x, simple *y) {
     mpn__and(x->arr, y->arr);
}

void simple__not(int n_dim, simple *x) {
     mpn__xor(tables__n_max_index[n_dim],x->arr);
}

static void disjoin(int n_dim, mp_limb_t arr[][SIMPLE_LIMBS], simple *x) {
     unsigned int i,bit;
     mp_limb_t *limb;
     mp_limb_t ret[SIMPLE_LIMBS];
     
     mpn__zero(ret);
     limb = x->arr;
     bit = 0;
     for (i = 0; i < tables__n_atoms[n_dim]; ++i) {
	  if (*limb & 1) {
	       mpn__or(arr[i],ret);
	  }
	  *limb >>= 1;
	  ++ bit;
	  if (bit == ULONG_BIT) {
	       ++limb;
	       bit = 0;
	  }
     }
     mpn__copy(ret,x->arr);
}

void simple__c0(simple *x) {
     if (!simple__is_zero(x)) {
	  simple__one(0,x);
     }
}

void simple__c1(simple *x) {
     disjoin(2,arr_c1,x);
}

void simple__c2(simple *x) {
     disjoin(3,arr_c2,x);
}

void simple__p(simple *x) {
     disjoin(3,arr_p3,x);
}

/*
void simple__point(simple *x) {
}
*/

void simple__r(simple *x) {
     disjoin(3,arr_r3,x);
}

void simple__s(simple *x) {
     disjoin(3,arr_s3,x);
}

void simple__s_inv(simple *x) {
     disjoin(3,arr_s3_inv,x);
}

/*
 * produces random simple with bitcount 1
 * note does not produce 0
 * */
void simple__random(simple *x) {
     int i;
     simple__zero(x);
     x->arr[0] |= 1;
     for (i = (unsigned int)((tables__n_atoms[3]) * ((double) rand()/RAND_MAX)); i--;) {
	  mpn__double(x->arr);
     }
}

void simple__random_reset(simple *x) {
     int i;
     mp_limb_t max_val = -1;
     for (i = 0; i < SIMPLE_LIMBS; ++i) {
	  x->arr[i] = max_val * ((double) rand()/RAND_MAX);
     }
     mpn__and(tables__n_max_index[3],x->arr);
}


/*
void simple__next(simple *x) {     
     simple s;
     int i;

     simple__zero(&s);
     

     *x = s;
     ++s;
     s = s % (tables__n_max_index[3] + 1);
     *x ^= s;
}
*/

int evaluate_at(DIFF_CONST mp_limb_t *x,int j) {
     mp_limb_t s;
     
     s = *x;
     s >>= j;
     return s & 1;
}


void display_binary(int n_dim, unsigned int tabs,DIFF_CONST mp_limb_t *x) {
     mp_limb_t s;
     unsigned int i,j;
     
     for(i = 0; i < tabs; ++i) printf(" ");
     if (n_dim == 3 && tables__n_atoms[n_dim] == 8) {
	  
	  printf("%d",evaluate_at(x,4));
	  printf("%d",evaluate_at(x,6));
	  printf("%d",evaluate_at(x,1));
	  printf("%d",evaluate_at(x,7));
	  
	  
	  printf("%d",evaluate_at(x,2));
	  printf("%d",evaluate_at(x,3));
	  printf("%d",evaluate_at(x,0));  
	  printf("%d",evaluate_at(x,5));
     } else {
	  s = *x;
	  for (i = 0, j = 0; i < tables__n_atoms[n_dim]; ++i) {
	       if (s & 1) {
		    printf("1");
		    s ^= 1;
	       } else {
		    printf("0");
	       }
	       s >>= 1;
	       if (i == ULONG_BIT - 1) {
		 ++j;
		 s = x[j];
	       }
	  }
     }
}


void simple__display(int n_dim, int tabs, DIFF_CONST simple *x) {
     /*
     int i;
     for (i = 0; i < tabs; ++i) {
	  printf(" ");
     }
     mpn__display_binary(tables__n_atoms[n_dim],x->arr);     
      */
     display_binary(n_dim,tabs,x->arr);
}

/*
 * describes the simple algebra
 */
/*
void simple__describe() {
     printf("ULONG_BIT: %u\n",ULONG_BIT);
     printf("max_index: \n");
     mpn__display_binary(tables__n_atoms[0], tables__n_max_index[0]);printf("\n");
     mpn__display_binary(tables__n_atoms[1], tables__n_max_index[1]);printf("\n");
     mpn__display_binary(tables__n_atoms[2], tables__n_max_index[2]);printf("\n");
     mpn__display_binary(tables__n_atoms[3], tables__n_max_index[3]);printf("\n");
}
*/
unsigned long int simple__n_atoms(int n_dim) {
     return tables__n_atoms[n_dim];
}

void simple__score(int n_dim, DIFF_CONST simple *x, score *ret) {
     ret->n_ones = mpn__popcount(x->arr);
     ret->n_zeros = tables__n_atoms[n_dim] - ret->n_ones;
     
}

void simple__test() {
     printf("\n");
}

/************************* table filler **************************************************/

/*
 * language for 2 register machine one is called reg the other accu.
 * 0   reg = 0;
 * 1   reg = 1;
 * 2   reg *= 2; (lshift in gmp)
 * .   accu = reg;        (accu += 1)?
 * -   accu = reg - 1     (monus)
 * |   accu |= reg;
 */

mp_limb_t reg[SIMPLE_LIMBS];

void fill_const(char *str,mp_limb_t accu[SIMPLE_LIMBS]) {
     char *p;
     
     for (p = str; *p != '\0'; ++p) {
	  if (*p == '0') {
	       mpn__zero(reg);
	  } else if (*p == '1') {
	       mpn__binary_one(reg);
	  } else if (*p == '2') {
	       mpn__double(reg);
	  } else if (*p == '-') {
	       mpn__copy(reg,accu);
	       mpn__decr(accu,accu);
	  } else if (*p == '.') {
	       mpn__copy(reg,accu);
	  } else if (*p == '|') {
	       mpn__or(reg,accu);
	  } else {
	       printf("Error: unrecognized instruction in string representation of table\n");
	       exit(1);
	  }
     }
     
}

void fill(int len, char *str[],mp_limb_t accus[][SIMPLE_LIMBS]) {
     int i;
     
     for (i = 0; i < len; ++i) {
	  fill_const(str[i],accus[i]);
     }
}

void table_filler__parse() {
     /*check bounds of arrays*/
     if (tables__n_atoms[3] > ULONG_BIT*SIMPLE_LIMBS) {
	  printf("Error: SIMPLE_LIMBS is to small for this table\n");
	  exit(1);
     } else {
	  fill(tables__n_atoms[3],str_arr_exp,arr_exp);
	  fill(4,str_tables__n_max_index,tables__n_max_index);
	  fill(tables__n_atoms[3],str_arr_s3,arr_s3);
	  fill(tables__n_atoms[3],str_arr_p3,arr_p3);
	  fill(tables__n_atoms[3],str_arr_r3,arr_r3);
	  fill(tables__n_atoms[2],str_arr_s2,arr_s2);
	  fill(tables__n_atoms[2],str_arr_p2,arr_p2);
	  fill_const(str_const_rel1,const_rel1);
	  fill_const(str_const_rel2,const_rel2);
	  fill_const(str_const_rel3,const_rel3);
	  fill(tables__n_atoms[3],str_arr_c2,arr_c2);
	  fill(tables__n_atoms[2],str_arr_c1,arr_c1);
     }
}


void simple__global_init() {
     unsigned long int i,j;

     table_filler__parse();
     /* initialize the inverse of the s3 operation, namely s3_inv */
     for (i = tables__n_atoms[3];i--;)
	  mpn__zero(arr_s3_inv[i - 1]);
     for (i = 0; i < tables__n_atoms[3]; ++i) {
	  if (!mpn__is_zero(arr_s3[i])) {
	       for (j = 0; j < tables__n_atoms[3]; ++j) {
		    if (evaluate_at(arr_s3[i],j)) {
			 mpn__or(arr_exp[i],arr_s3_inv[j]);
		    }
	       }
	  }
     }	   
}

