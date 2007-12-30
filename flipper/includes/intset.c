/***************************************************************************
                     intset.c  -  set of natural numbers as bit word
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

unsigned long int arr_pow2[ULONG_BIT];

unsigned long int ipow2(unsigned long int x) {
     if (x >= ULONG_BIT) {
	  printf("WARNING: ipow2 overflow\n");
	  exit(1);
     }
     if (x == 0) {
	  return 1;
     } else {
	  return 2 * ipow2(x - 1);
     }
}

void intset__global_init() {
     int i;
     
     arr_pow2[0] = 1;
     for(i = 1; i < ULONG_BIT; ++i) {
	  arr_pow2[i] = arr_pow2[i - 1] * 2;
     }
}

unsigned long int intset__pow2(unsigned int x) {
     return arr_pow2[x];
}

void intset__init(intset *x) {
     int i;
     for (i = 0; i < INTSET_UNITS; ++i) {
	  x->x[i] = 0;
     }
}

int intset__member(unsigned int a, DIFF_CONST intset *x) {
     int i,unit;

     unit = 0;
     for (i = 0; i < INTSET_UNITS; ++i,++unit) {
	  if (a < ULONG_BIT) break;
	  a -= ULONG_BIT;
     }
     /*
      *      return x->x[unit] & arr_pow2[a];
     */
     return x->x[unit] & intset__pow2(a);

}

void intset__insert(unsigned int a, intset *x) {
     int i,unit;
     
     unit = 0;
     for (i = 0; i < INTSET_UNITS; ++i,++unit) {
	  if (a < ULONG_BIT) break;
	  a -= ULONG_BIT;
     }
     x->x[unit] |= intset__pow2(a);
}

void intset__or(DIFF_CONST intset *x, intset *y) {
     int i;
     
     for (i = 0; i < INTSET_UNITS; ++i) {
	  y->x[i] |= x->x[i]; 
     }
}

void intset__describe(DIFF_CONST intset *x) {
     unsigned int i;
     
     for (i = 0; i < ULONG_BIT; ++i) {
	  if (intset__member(i,x)) {
	       printf(" %u",i);
	  }
     }
}

int intset__is_within_bounds(unsigned int x) {
     if (x < ULONG_BIT * INTSET_UNITS) {
	  return 1;
     } else {
	  return 0;
     }
}
