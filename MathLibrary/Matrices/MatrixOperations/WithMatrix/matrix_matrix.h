#ifndef _MATRIX_MATRIX_H_
#define _MATRIX_MATRIX_H_

#include <stdarg.h>
#include <stdio.h>
#include "../../../../src/constants.h"
#include "../../matrix.h"

/**
 * @brief 
 * 
 * @param mat1 
 * @param mat2 
 * @return matrix 
 */
matrix
addMat(matrix mat1, matrix mat2);

/**
 * @brief 
 * 
 * @param mat1 
 * @param mat2 
 * @return true 
 * @return false 
 */
bool
addMatBy(matrix *mat1, matrix mat2);

/**
 * @brief 
 * 
 * @param mat1 
 * @param mat2 
 * @return matrix 
 */
matrix
substractMat(matrix mat1, matrix mat2);

/**
 * @brief 
 * 
 * @param mat1 
 * @param mat2 
 * @return true 
 * @return false 
 */
bool
substractMatBy(matrix *mat1, matrix mat2);
/**
 * @brief 
 * 
 * @param mat1 
 * @param mat2 
 * @return matrix 
 */
matrix
multiplyMat(matrix mat1, matrix mat2);

/**
 * @brief 
 * 
 * @param mat 
 * @return matrix 
 */
matrix
transposeMat(matrix *mat);

/**
 * @brief 
 * 
 * @param mat1 
 * @param mat2 
 * @return matrix 
 */
matrix
augmentMat(matrix *mat1, matrix *mat2);

#endif  //  _MATRIX_MATRIX_H_