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
scalarVectMultiplicationTo(vector vec, float scalar);

/**
 * @brief 
 * 
 * @param v 
 * @param scalar 
 */
void
scalarVectMultiplicationAt(vector *vec, float scalar);

/**
 * @brief 
 * 
 * @param vec 
 * @param scalar 
 * @return vector 
 */
vector
scalarVectDivisionTo(vector vec, float scalar);

/**
 * @brief 
 * 
 * @param vec 
 * @param scalar 
 */
void
scalarVectDivisionAt(vector *vec, float scalar);

/**
 * @brief 
 * 
 * @param vec 
 * @param power 
 */
vector
powerVectorTo(vector vec, float power);

/**
 * @brief 
 * 
 * @param vec 
 * @param power 
 * @return vector 
 */
void
powerVectorAt(vector *vec, float power);

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return vector 
 */


#endif