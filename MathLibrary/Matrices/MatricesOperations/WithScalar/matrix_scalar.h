#ifndef _MATRIX_SCALAR_H_
#define _MATRIX_SCALAR_H_

#include <stdarg.h>
#include <stdio.h>
#include "../../../../src/constants.h"
#include "../../matrix.h"

/**
 * @brief 
 * 
 * @param mat 
 * @param scalar 
 * @return matrix 
 */
matrix
addMatScalar(matrix mat, float scalar);

/**
 * @brief 
 * 
 * @param mat 
 * @param scalar 
 */
void
addMatScalarBy(matrix *mat, float scalar);

/**
 * @brief 
 * 
 * @param mat 
 * @param scalar 
 * @return matrix 
 */
matrix
subtractMatScalar(matrix mat, float scalar);

/**
 * @brief 
 * 
 * @param mat 
 * @param scalar 
 */
void
subtractMatScalarBy(matrix *mat, float scalar);

/**
 * @brief 
 * 
 * @param mat 
 * @param scalar 
 * @return matrix 
 */
matrix
divisionMatScalar(matrix mat, float scalar);

/**
 * @brief 
 * 
 * @param mat 
 * @param scalar 
 */
void
divisionMatScalarBy(matrix *mat, float scalar);

/**
 * @brief 
 * 
 * @param mat 
 * @param scalar 
 * @return matrix 
 */
matrix
multiplyMatScalar(matrix mat, float scalar);

/**
 * @brief 
 * 
 * @param mat 
 * @param scalar 
 */
void
multiplyMatScalarBy(matrix *mat, float scalar);

/**
 * @brief 
 * 
 * @param mat 
 * @param power 
 * @return matrix 
 */
matrix
powerMatrix(matrix mat, float power);

/**
 * @brief 
 * 
 * @param mat 
 * @param power 
 */
void
powerMatrixBy(matrix *mat, float power);

#endif  //  _MATRIX_SCALAR_H_