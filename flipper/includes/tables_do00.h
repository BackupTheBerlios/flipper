/***************************************************************************
 *    tables_do00.h  -  tables for dense order without endpoint
 *                           and less than relations
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
 ***************************************************************************/mp_limb_t arr_exp[37][SIMPLE_LIMBS];
mp_limb_t arr_exp[13][SIMPLE_LIMBS];
char *str_arr_exp[] = {"1.","12.","122.","1222.","12222.","122222.","1222222.","12222222.","122222222.","1222222222.","12222222222.","122222222222.","1222222222222."};
unsigned long int tables__n_atoms[] = {1,1, 3, 13};
mp_limb_t tables__n_max_index[4][SIMPLE_LIMBS];
char * str_tables__n_max_index[] = {"12-", "12-", "1222-", "12222222222222-"};
mp_limb_t arr_s3[13][SIMPLE_LIMBS];
char *str_arr_s3[] = {
 "12222222222.12222222|122|1|12|"
, "0."
, "0."
, "0."
, "0."
, "1222222222222.122222222|122222|"
, "122222222222.1222222222|1222222|1222|12222|"
, "0."
, "0."
, "0."
, "0."
, "0."
, "0."
};
mp_limb_t arr_p3[13][SIMPLE_LIMBS];
char *str_arr_p3[] = {
 "1."
, "122."
, "12."
, "1222222222222."
, "122222222222."
, "122222."
, "1222222."
, "122222222."
, "12222222."
, "12222222222."
, "1222222222."
, "12222."
, "1222."
};
mp_limb_t arr_r3[13][SIMPLE_LIMBS];
char *str_arr_r3[] = {
 "1222."
, "1222222222."
, "12222."
, "1222222222222."
, "12222222222."
, "122222."
, "12222222."
, "122222222."
, "1222222."
, "122222222222."
, "122."
, "12."
, "1."
};
mp_limb_t arr_s2[3][SIMPLE_LIMBS];
char *str_arr_s2[] = {
 "0."
, "0."
, "1.12|122|"
};
mp_limb_t arr_p2[3][SIMPLE_LIMBS];
char *str_arr_p2[] = {
 "12."
, "1."
, "122."
};
mp_limb_t const_rel1[SIMPLE_LIMBS];char *str_const_rel1 = "122222222.1222222222|122|1222|12222|";
mp_limb_t const_rel2[SIMPLE_LIMBS];char *str_const_rel2 = "122222222.1222222222|122|1222|12222|";
mp_limb_t const_rel3[SIMPLE_LIMBS];char *str_const_rel3 = "122222222.1222222222|122|1222|12222|";
mp_limb_t arr_c2[13][SIMPLE_LIMBS];
char * str_arr_c2[] = {
 "122."
, "12."
, "1."
, "1."
, "1."
, "122."
, "122."
, "12."
, "1."
, "1."
, "12."
, "12."
, "12."
};
mp_limb_t arr_c1[3][SIMPLE_LIMBS];
char * str_arr_c1[] = {
 "1."
, "1."
, "1."
};
