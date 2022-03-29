#ifndef _MATVECT_H_
#define _MATVECT_H_

#include <stdlib.h>
#include <stdio.h>

#include "../../Vectors/vector.h"
#include "../../Matrices/matrix.h"

/**
 * @brief Get the Matrix Row object
 * 
 * @param mat 
 * @param row 
 * @return vector 
 */
vector
getMatrixRow(matrix *mat, int row);

/**
 * @brief Get the Matrix Collumn object
 * 
 * @param mat 
 * @param collumn 
 * @return vector 
 */
vector
getMatrixCollumn(matrix *mat, int collumn);

/**
 * @brief 
 * 
 * @param mat 
 * @param vec 
 * @return vector 
 */
vector
multiplyMatVect(matrix mat, vector vec);

#endif  //  _MATVECT_H_