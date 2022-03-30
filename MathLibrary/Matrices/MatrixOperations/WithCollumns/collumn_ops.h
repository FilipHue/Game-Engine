#ifndef _COLLUMN_OPS_H_
#define _COLLUMN_OPS_H_

#include <stdarg.h>
#include <stdio.h>

#include "../../../../src/constants.h"
#include "../../matrix.h"

/**
 * @brief 
 * 
 * @param mat 
 * @param collumn1 
 * @param collumn2 
 * @return true 
 * @return false 
 */
bool
swapCollumns(matrix *mat, unsigned int collumn1, unsigned int collumn2);

/**
 * @brief 
 * 
 * @param mat 
 * @param collumn1 
 * @param collumn2 
 * @return true 
 * @return false 
 */
bool
addCollumns(matrix *mat, unsigned int collumn1, unsigned int collumn2);

/**
 * @brief Construct a new multiply C Ollumn object
 * 
 * @param mat 
 * @param factor 
 */
bool
multiplyCollumn(matrix *mat, unsigned int collumn, float factor);

/**
 * @brief 
 * 
 * @param mat 
 * @param collumn1 
 * @param collumn2 
 * @param factor 
 * @return true 
 * @return false 
 */
bool
addMultipleCollumns(matrix *mat, unsigned int collumn1, unsigned int collumn2, float factor);


#endif  //  _COLLUMN_OPS_H_