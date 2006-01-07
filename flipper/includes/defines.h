/***************************************************************************
                     defines.h  -  various macros
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
     
#define DIFF_DIMENTION 3
#define DIFF_QUADRANTS 8
#define DIFF_FIRST_QUADRANT(i) (&((i) -> pQuadrant[7]))
#define DIFF_QUADRANT_DECLARATION composed *pQuadrant[8]
#define DIFF_SIMPLE_TO_COMPOSED(simple , composed) composed -> is_simple=0; composed -> pQuadrant[7] = new__composed_simple(composed -> n_dim , simple); composed -> pQuadrant[3] = new__composed_simple(composed -> n_dim , simple); composed -> pQuadrant[5] = new__composed_simple(composed -> n_dim , simple); composed -> pQuadrant[1] = new__composed_simple(composed -> n_dim , simple); composed -> pQuadrant[6] = new__composed_simple(composed -> n_dim , simple); composed -> pQuadrant[2] = new__composed_simple(composed -> n_dim , simple); composed -> pQuadrant[4] = new__composed_simple(composed -> n_dim , simple); composed -> pQuadrant[0] = new__composed_simple(composed -> n_dim , simple); 
#define DIFF_FOR_EACH_QUADRANT( i , call ) call ( (i) -> pQuadrant[7] ); call ( (i) -> pQuadrant[3] ); call ( (i) -> pQuadrant[5] ); call ( (i) -> pQuadrant[1] ); call ( (i) -> pQuadrant[6] ); call ( (i) -> pQuadrant[2] ); call ( (i) -> pQuadrant[4] ); call ( (i) -> pQuadrant[0] ); 
#define DIFF_PAIRWISE_FOR_EACH_QUADRANT( i , j , call ) call ( (i) -> pQuadrant[7] , (j) -> pQuadrant[7] ); call ( (i) -> pQuadrant[3] , (j) -> pQuadrant[3] ); call ( (i) -> pQuadrant[5] , (j) -> pQuadrant[5] ); call ( (i) -> pQuadrant[1] , (j) -> pQuadrant[1] ); call ( (i) -> pQuadrant[6] , (j) -> pQuadrant[6] ); call ( (i) -> pQuadrant[2] , (j) -> pQuadrant[2] ); call ( (i) -> pQuadrant[4] , (j) -> pQuadrant[4] ); call ( (i) -> pQuadrant[0] , (j) -> pQuadrant[0] ); 
#define DIFF_ASSIGN_FOR_EACH_QUADRANT( i , j , call ) (i) -> pQuadrant[7] = call ( (j) -> pQuadrant[7] ); (i) -> pQuadrant[3] = call ( (j) -> pQuadrant[3] ); (i) -> pQuadrant[5] = call ( (j) -> pQuadrant[5] ); (i) -> pQuadrant[1] = call ( (j) -> pQuadrant[1] ); (i) -> pQuadrant[6] = call ( (j) -> pQuadrant[6] ); (i) -> pQuadrant[2] = call ( (j) -> pQuadrant[2] ); (i) -> pQuadrant[4] = call ( (j) -> pQuadrant[4] ); (i) -> pQuadrant[0] = call ( (j) -> pQuadrant[0] ); 
#define DIFF_ASSIGN_FOR_EACH_QUADRANT_P( i , j , call ) (i) -> pQuadrant[7] = call ( (j) -> pQuadrant[7] ); (i) -> pQuadrant[3] = call ( (j) -> pQuadrant[3] ); (i) -> pQuadrant[5] = call ( (j) -> pQuadrant[6] ); (i) -> pQuadrant[1] = call ( (j) -> pQuadrant[2] ); (i) -> pQuadrant[6] = call ( (j) -> pQuadrant[5] ); (i) -> pQuadrant[2] = call ( (j) -> pQuadrant[1] ); (i) -> pQuadrant[4] = call ( (j) -> pQuadrant[4] ); (i) -> pQuadrant[0] = call ( (j) -> pQuadrant[0] ); 
#define DIFF_ASSIGN_FOR_EACH_QUADRANT_R( i , j , call ) (i) -> pQuadrant[7] = call ( (j) -> pQuadrant[7] ); (i) -> pQuadrant[5] = call ( (j) -> pQuadrant[3] ); (i) -> pQuadrant[6] = call ( (j) -> pQuadrant[5] ); (i) -> pQuadrant[4] = call ( (j) -> pQuadrant[1] ); (i) -> pQuadrant[3] = call ( (j) -> pQuadrant[6] ); (i) -> pQuadrant[1] = call ( (j) -> pQuadrant[2] ); (i) -> pQuadrant[2] = call ( (j) -> pQuadrant[4] ); (i) -> pQuadrant[0] = call ( (j) -> pQuadrant[0] ); 
#define DIFF_ASSIGN_FOR_EACH_QUADRANT_S( i , j , call ) (i) -> pQuadrant[7] = call ( (j) -> pQuadrant[7] ); (i) -> pQuadrant[3] = call ( (j) -> pQuadrant[3] ); (i) -> pQuadrant[5] = call ( (j) -> pQuadrant[4] ); (i) -> pQuadrant[1] = call ( (j) -> pQuadrant[0] ); (i) -> pQuadrant[6] = call ( (j) -> pQuadrant[7] ); (i) -> pQuadrant[2] = call ( (j) -> pQuadrant[3] ); (i) -> pQuadrant[4] = call ( (j) -> pQuadrant[4] ); (i) -> pQuadrant[0] = call ( (j) -> pQuadrant[0] ); 
#define DIFF_FOR_EACH_QUADRANT_C0( i , call) call ( (i) -> pQuadrant[6], (i) -> pQuadrant[7]); call ( (i) -> pQuadrant[2], (i) -> pQuadrant[3]); call ( (i) -> pQuadrant[4], (i) -> pQuadrant[5]); call ( (i) -> pQuadrant[0], (i) -> pQuadrant[1]); 
#define DIFF_FOR_EACH_QUADRANT_C1( i , call) call ( (i) -> pQuadrant[5], (i) -> pQuadrant[7]); call ( (i) -> pQuadrant[1], (i) -> pQuadrant[3]); call ( (i) -> pQuadrant[4], (i) -> pQuadrant[6]); call ( (i) -> pQuadrant[0], (i) -> pQuadrant[2]); 
#define DIFF_FOR_EACH_QUADRANT_C2( i , call) call ( (i) -> pQuadrant[3], (i) -> pQuadrant[7]); call ( (i) -> pQuadrant[1], (i) -> pQuadrant[5]); call ( (i) -> pQuadrant[2], (i) -> pQuadrant[6]); call ( (i) -> pQuadrant[0], (i) -> pQuadrant[4]); 
