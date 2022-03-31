#ifndef _LU_H_
#define _LU_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../Matrices/matrix.h"

/**
 * @brief 
 * 
 * @param mat 
 * @param L 
 * @param U 
 */
void
luDecomposition(matrix *mat, matrix **L, matrix **U);


#endif  //  _LU_H_