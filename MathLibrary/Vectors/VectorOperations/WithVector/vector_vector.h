#ifndef _VECTOR_VECTOR_H_
#define _VECTOR_VECTOR_H_

#include "../../vector.h"
#include "../../../../src/constants.h"


/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return vector 
 */
vector
addVect(vector vec1, vector vec2);

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return true 
 * @return false 
 */
bool
addVectBy(vector *vec1, vector vec2);

/**
 * @brief
 * 
 * @param vec1 
 * @param vec2 
 * @return vector 
 */
vector
substractVect(vector vec1, vector vec2);

/**
 * @brief
 * 
 * @param vec1 
 * @param vec2 
 * @return true 
 * @return false 
 */
bool
substractVectBy(vector *vec1, vector vec2);

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
normalizeVectorTo(vector vec);

/**
 * @brief 
 * 
 * @param vec 
 */
void
normalizeVectorAt(vector *vec);


#endif  //  _VECTOR_VECTOR_H_