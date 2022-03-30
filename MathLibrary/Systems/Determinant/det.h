#ifndef _DET_H_
#define _DEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../../Vectors/vector.h"
#include "../../Matrices/matrix.h"

/**
 * @brief 
 * 
 * @param mat 
 * @param row 
 * @param collumn 
 * @return matrix 
 */
matrix
spliceMat(matrix *mat, unsigned int row, unsigned int collumn);

/**
 * @brief 
 * 
 * @param mat 
 * @return float 
 */
float
detMat(matrix mat);

/**
 * @brief 
 * 
 * @param mat 
 * @return float 
 */
float
luDet(matrix mat);

#endif  //  _DET_H_