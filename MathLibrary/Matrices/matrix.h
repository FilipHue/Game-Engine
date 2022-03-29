#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdarg.h>
#include <stdio.h>
#include "../../src/constants.h"
#include "../Vectors/vector.h"

typedef struct matrix matrix;
struct matrix
{
    unsigned int rows;
    unsigned int collums;
    float **elements;
};

extern const matrix MATRIX_UNDEFINED;

#define matrix(rows, collumns, ...) createNewMatrix(rows, collumns, NUM_ARGS(float, __VA_ARGS__), ##__VA_ARGS__)

/**
 * @brief
 * 
 * @param rows 
 * @param collums 
 * @return matrix 
 */
matrix
createMatrix(unsigned int rows, unsigned int collums);

/**
 * @brief Create a Identity Matrix object
 * 
 * @param size 
 * @return matrix 
 */
matrix
createIdentityMatrix(unsigned int size);

/**
 * @brief Create a Default Matrix object
 * 
 * @param rows 
 * @param collumsn 
 * @param default_value 
 * @return matrix 
 */
matrix
createDefaultMatrix(unsigned int rows, unsigned int collumsn, float default_value);

/**
 * @brief Create a Zero Matrix object
 * 
 * @param rows 
 * @param collumns 
 * @return matrix 
 */
matrix
createZeroMatrix(unsigned int rows, unsigned int collumns);

/**
 * @brief Create a New Matrix object
 * 
 * @param rows 
 * @param collumns 
 * @param ... 
 * @return matrix 
 */
matrix
createNewMatrix(unsigned int rows, unsigned int collumns, ...);

/**
 * @brief 
 * 
 * @param mat 
 * @return matrix 
 */
matrix
copyMatrix(matrix mat);

/**
 * @brief 
 * 
 * @param mat 
 * @return matrix 
 */
matrix
copyMatrixPointer(matrix *mat);

/**
 * @brief 
 * 
 * @param mat 
 */
void
printMatrix(matrix mat);

/**
 * @brief 
 * 
 * @param mat1 
 * @param mat2 
 * @return true 
 * @return false 
 */
bool
equalMatrix(matrix mat1, matrix mat2);

/**
 * @brief 
 * 
 * @param mat 
 */
void
destroyMat(matrix *mat);

#endif