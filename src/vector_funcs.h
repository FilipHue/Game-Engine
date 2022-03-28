#ifndef _VECTOR_FUNCS_H_
#define _VECTOR_FUNCS_H_

#include "vector.h"
#include "constants.h"

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return true 
 * @return false 
 */
bool
equals(vector vec1, vector vec2);

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
vector
add(vector vec1, vector vec2);

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return true 
 * @return false 
 */
bool
addTo(vector *vec1, vector vec2);

/**
 * @brief
 * 
 * @param vec1 
 * @param vec2 
 * @return vector 
 */
vector
substract(vector vec1, vector vec2);

/**
 * @brief
 * 
 * @param vec1 
 * @param vec2 
 * @return true 
 * @return false 
 */
bool
substractTo(vector *vec1, vector vec2);

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return vector 
 */
vector
vectorMultiplication(vector vec1, vector vec2);

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return true 
 * @return false 
 */
bool
vectorMultiplicationBy(vector *vec1, vector vec2);

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return vector 
 */
vector
vectorDivision(vector vec1, vector vec2);

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return true 
 * @return false 
 */
bool
vectorDivisionBy(vector *vec1, vector vec2);

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return float 
 */
float
dotProduct(vector vec1, vector vec2);

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return true 
 * @return false 
 */
bool
isOrthogonal(vector vec1, vector vec2);

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return vector 
 */
vector
crossProduct(vector vec1, vector vec2);

/**
 * @brief 
 * 
 * @param vec 
 * @return float 
 */
float
magnitude(vector vec);

/**
 * @brief 
 * 
 * @param vec 
 * @return float 
 */
float
magnitudeSquared(vector vec);
/**
 * @brief 
 * 
 * @param vec 
 * @return vector 
 */
vector
normalizeVector(vector vec);

/**
 * @brief 
 * 
 * @param vec 
 */
void
normalizeVectorTo(vector *vec);

#endif  //  _VECTOR_FUNCS_H_
