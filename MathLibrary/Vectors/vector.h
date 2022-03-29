#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdarg.h>
#include <stdio.h>

#include "../../src/constants.h"


typedef struct vector vector;
struct vector {
    unsigned int size;
    float *elements;
};

extern const vector VECTOR_UNDEFINED;

/**
 * @brief 
 * 
 */
#define NUM_ARGS(type, ...) (sizeof((type[]){0.0f, ##__VA_ARGS__}) / sizeof(type) - 1)

/**
 * @brief 
 * 
 */
#define vector(...) createNewVector(NUM_ARGS(float, __VA_ARGS__), ##__VA_ARGS__)

/**
 * @brief 
 * 
 * @param size 
 * @return vector 
 */
vector
createVector(unsigned int size);

/**
 * @brief Create a Default Vector object
 * 
 * @param size 
 * @param default_value 
 * @return vector 
 */
vector
createDefaultVector(unsigned int size, float default_value);

/**
 * @brief Create a Empty Vector object
 * 
 * @param size 
 * @return vector 
 */
vector
createEmptyVector(unsigned int size);

/**
 * @brief Create a New Vector object
 * 
 * @param numArgs 
 * @param ... 
 * @return vector 
 */
vector
createNewVector(unsigned int numArgs, ...);

/**
 * @brief 
 * 
 * @param vec 
 * @return vector 
 */
vector
copyVector(vector *vec);

/**
 * @brief 
 * 
 * @param vec 
 * @return vector 
 */
vector
copyVectorPtr(vector vec);

/**
 * @brief 
 * 
 * @param vec 
 */
void
printVector(vector vec);

/**
 * @brief 
 * 
 * @param vec1 
 * @param vec2 
 * @return true 
 * @return false 
 */
bool
equalVector(vector vec1, vector vec2);

/**
 * @brief 
 * 
 * @param vec 
 */
void
destroyVect(vector *vec);


#endif  //  _VECTOR_H_
