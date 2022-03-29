#ifndef _MATRIX_MATRIX_H_
#define _MATRIX_MATRIX_H_

#include <stdarg.h>
#include <stdio.h>
#include "../../../../src/constants.h"
#include "../../matrix.h"

matrix
addMat(matrix mat1, matrix mat2);

bool
addMatBy(matrix *mat1, matrix mat2);

matrix
substractMat(matrix mat1, matrix mat2);

bool
substractMatBy(matrix *mat1, matrix mat2);


matrix
multiplyMat(matrix mat1, matrix mat2);

#endif  //  _MATRIX_MATRIX_H_