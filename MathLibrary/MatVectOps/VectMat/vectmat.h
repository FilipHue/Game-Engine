#ifndef _VECT_MAT_H_
#define _VECT_MAT_H_

#include <stdlib.h>
#include <stdio.h>

#include "../../Vectors/vector.h"
#include "../../Matrices/matrix.h"

/**
 * @brief 
 * 
 * @param vec 
 * @return matrix 
 */
matrix
MatrixRowToVector(vector *vec);

/**
 * @brief 
 * 
 * @param vec 
 * @return matrix 
 */
matrix
MatrixCollumnToVector(vector *vec);

#endif  //  _VECT_MAT_H_