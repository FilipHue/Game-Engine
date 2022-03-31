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
matrix*
MatrixRowToVector(vector *vec);

/**
 * @brief 
 * 
 * @param vec 
 * @return matrix 
 */
matrix*
MatrixCollumnToVector(vector *vec);

/**
 * @brief 
 * 
 * @param mat 
 * @param vec 
 * @return matrix 
 */
matrix*
augmentVect(matrix *mat, vector *vec);

#endif  //  _VECT_MAT_H_