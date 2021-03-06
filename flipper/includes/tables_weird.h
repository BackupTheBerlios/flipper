/***************************************************************************
               tables_weird.h  -  tables for ?
                              -------------------
     copyright            : (C) 2005 by Andr� Rognes
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
     
unsigned long long int arr_exp[] = {1ULL,2ULL*1ULL,2ULL*2ULL*1ULL,2ULL*2ULL*2ULL*1ULL,2ULL*2ULL*2ULL*2ULL*1ULL,2ULL*2ULL*2ULL*2ULL*2ULL*1ULL,2ULL*2ULL*2ULL*2ULL*2ULL*2ULL*1ULL};
unsigned long long int tables__n_atoms[] = {1,2,4,7};
unsigned long long int tables__n_max_index[] = {1ULL, (2ULL*2ULL*1ULL)-1ULL, (2ULL*2ULL*2ULL*2ULL*1ULL)-1ULL, (2ULL*2ULL*2ULL*2ULL*2ULL*2ULL*2ULL*1ULL)-1ULL};
unsigned long long int arr_s3[] = {
 1ULL|2ULL*2ULL*2ULL*2ULL*2ULL*2ULL*1ULL|0ULL
,0ULL
,0ULL
,2ULL*1ULL|2ULL*2ULL*2ULL*2ULL*2ULL*1ULL|2ULL*2ULL*2ULL*1ULL|0ULL
,2ULL*2ULL*1ULL|2ULL*2ULL*2ULL*2ULL*1ULL|0ULL
,0ULL
,0ULL
};
unsigned long long int arr_p3[] = {
 1ULL|0ULL
,2ULL*2ULL*2ULL*2ULL*2ULL*2ULL*1ULL|0ULL
,2ULL*2ULL*2ULL*2ULL*2ULL*1ULL|0ULL
,2ULL*2ULL*2ULL*1ULL|0ULL
,2ULL*2ULL*2ULL*2ULL*1ULL|0ULL
,2ULL*2ULL*1ULL|0ULL
,2ULL*1ULL|0ULL
};
unsigned long long int arr_r3[] = {
 2ULL*2ULL*1ULL|0ULL
,2ULL*2ULL*2ULL*2ULL*1ULL|0ULL
,2ULL*2ULL*2ULL*2ULL*2ULL*1ULL|0ULL
,2ULL*2ULL*2ULL*1ULL|0ULL
,2ULL*2ULL*2ULL*2ULL*2ULL*2ULL*1ULL|0ULL
,1ULL|0ULL
,2ULL*1ULL|0ULL
};
unsigned long long int arr_s2[] = {
 0ULL
,0ULL
,1ULL|2ULL*2ULL*1ULL|0ULL
,2ULL*2ULL*2ULL*1ULL|2ULL*1ULL|0ULL
};
unsigned long long int arr_p2[] = {
 2ULL*1ULL|0ULL
,1ULL|0ULL
,2ULL*2ULL*1ULL|0ULL
,2ULL*2ULL*2ULL*1ULL|0ULL
};
unsigned long long int const_rel1 = 2ULL*2ULL*1ULL|2ULL*1ULL|0ULL;
unsigned long long int const_rel2 = 2ULL*2ULL*1ULL|2ULL*1ULL|0ULL;
unsigned long long int arr_c2[] = {
 2ULL*2ULL*2ULL*1ULL|0ULL
,1ULL|0ULL
,1ULL|0ULL
,2ULL*2ULL*2ULL*1ULL|2ULL*2ULL*1ULL|0ULL
,2ULL*2ULL*1ULL|0ULL
,2ULL*1ULL|0ULL
,2ULL*1ULL|0ULL
};
unsigned long long int arr_c1[] = {
 2ULL*1ULL|0ULL
,1ULL|0ULL
,1ULL|0ULL
,2ULL*1ULL|0ULL
};
