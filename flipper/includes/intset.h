/***************************************************************************
         intset.h  -  set of natural numbers as fixed size binary word
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
     
#define INTSET_UNITS ((MAX_RELS+1)/64)

typedef struct _intset intset;

struct _intset {
     uint64_t x[INTSET_UNITS];
};

void intset__global_init();
uint64_t intset__pow2(unsigned int x);
void intset__init(intset *x);
int intset__member(unsigned int a, const intset *x);
void intset__insert(unsigned int a, intset *x);
void intset__or(const intset *x, intset *y);
void intset__describe(const intset *x);
int intset__is_within_bounds(unsigned int x);
