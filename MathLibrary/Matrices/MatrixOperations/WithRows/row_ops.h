#ifndef _ROW_OPS_H_
#define _ROW_OPS_H_

#include <stdarg.h>
#include <stdio.h>

#include "../../../../src/constants.h"
#include "../../matrix.h"

/**
 * @brief 
 * 
 * @param mat 
 * @param row1 
 * @param row2 
 * @return true 
 * @return false 
 */
bool
swapRows(matrix *mat, unsigned int row1, unsigned int row2);

/**
 * @brief 
 * 
 * @param mat 
 * @param row1 
 * @param row2 
 * @return true 
 * @return false 
 */
bool
addRows(matrix *mat, unsigned int row1, unsigned int row2);

/**
 * @brief 
 * 
 * @param mat 
 * @param row 
 * @param factor 
 * @return true 
 * @return false 
 */
bool
multiplyRow(matrix *mat, unsigned int row, float factor);

/**
 * @brief 
 * 
 * @param mat 
 * @param row1 
 * @param row2 
 * @param factor 
 * @return true 
 * @return false 
 */
bool
addMultipleRows(matrix *mat, unsigned int row1, unsigned int row2, float factor);

#endif  //  _ROW_OPS_H_
