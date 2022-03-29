#ifndef _VECTOR_SCALAR_H_
#define _VECTOR_SCALAR_H_

#include "../../vector.h"
#include "../../../../src/constants.h"


/**
 * @brief 
 * 
 * @param vec 
 * @param scalar 
 * @return vector 
 */
vector
scalarMultiplication(vector vec, float scalar);

/**
 * @brief 
 * 
 * @param v 
 * @param scalar 
 */
void
scalarMultiplicationBy(vector *vec, float scalar);

/**
 * @brief 
 * 
 * @param vec 
 * @param scalar 
 * @return vector 
 */
vector
scalarDivision(vector vec, float scalar);

/**
 * @brief 
 * 
 * @param vec 
 * @param scalar 
 */
void
scalarDivisionBy(vector *vec, float scalar);

/**
 * @brief 
 * 
 * @param vec 
 * @param power 
 */
vector
powerVector(vector vec, float power);

/**
 * @brief 
 * 
 * @param vec 
 * @param power 
 * @return vector 
 */
void
powerVectorTo(vector *vec, float power);

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return vector 
 */


#endif