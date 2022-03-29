#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../../../../src/constants.h"
#include "../../vector.h"
#include "./vector_vector.h"


vector
add(vector vec1, vector vec2) {
    if (vec1.size != vec2.size) {
        return VECTOR_UNDEFINED;
    }

    vector new_vector;

    new_vector = create(vec1.size);
    for (unsigned int i = 0; i < new_vector.size; i++) {
        new_vector.elements[i] = vec1.elements[i] + vec2.elements[i];
    }

    return new_vector;
}


bool
addTo(vector *vec1, vector vec2) {
    if (vec1->size != vec2.size) {
        return false;
    }

    for (unsigned int i = 0; i < vec1->size; i++) {
        vec1->elements[i] += vec2.elements[i];
    }

    return true;
}


vector
substract(vector vec1, vector vec2) {
    if (vec1.size != vec2.size) {
        return VECTOR_UNDEFINED;
    }

    vector new_vector;

    new_vector = create(vec1.size);
    for (unsigned int i = 0; i < new_vector.size; i++) {
        new_vector.elements[i] = vec1.elements[i] - vec2.elements[i];
    }

    return new_vector;
}


bool
substractTo(vector *vec1, vector vec2) {
    if (vec1->size != vec2.size) {
        return false;
    }

    for (unsigned int i = 0; i < vec1->size; i++) {
        vec1->elements[i] -= vec2.elements[i];
    }

    return true;
}


vector
vectorMultiplication(vector vec1, vector vec2) {
    if (vec1.size != vec2.size) {
        return VECTOR_UNDEFINED;
    }

    vector new_vector;

    new_vector = create(vec1.size);
    for (unsigned int i = 0; i < new_vector.size; i++) {
        new_vector.elements[i] = vec1.elements[i] * vec2.elements[i];
    }

    return new_vector;
}


bool
vectorMultiplicationBy(vector *vec1, vector vec2) {
    if (vec1->size != vec2.size) {
        return false;
    }

    for (unsigned int i = 0; i < vec1->size; i++) {
        vec1->elements[i] *= vec2.elements[i];
    }

    return true;
}


vector
vectorDivision(vector vec1, vector vec2) {
    if (vec1.size != vec2.size) {
        return VECTOR_UNDEFINED;
    }

    vector new_vector;

    new_vector = create(vec1.size);
    for (unsigned int i = 0; i < new_vector.size; i++) {
        new_vector.elements[i] = vec1.elements[i] / vec2.elements[i];
    }

    return new_vector;
}


bool
vectorDivisionBy(vector *vec1, vector vec2) {
    if (vec1->size != vec2.size) {
        return false;
    }

    for (unsigned int i = 0; i < vec1->size; i++) {
        vec1->elements[i] /= vec2.elements[i];
    }

    return true;
}


float
dotProduct(vector vec1, vector vec2) {
    float product;
    
    product = 0.0f;
    if (vec1.size == vec2.size) {
        for (unsigned int i = 0; i < vec1.size; i++) {
            product += vec1.elements[i] * vec2.elements[i];
        }
    }

    return product;
}


bool
isOrthogonal(vector vec1, vector vec2) {

    return vec1.size == vec2.size ? dotProduct(vec1, vec2) == 0.0f : false;
}


vector
crossProduct(vector vec1, vector vec2) {
    if (vec1.size != vec2.size) {
        return VECTOR_UNDEFINED;
    }

    vector parallel_vect;

    parallel_vect = create(3);
    parallel_vect.elements[0] = (vec1.elements[1] * vec2.elements[2]) - 
                                (vec1.elements[2] * vec2.elements[1]);
    parallel_vect.elements[1] = (vec1.elements[2] * vec2.elements[0]) -
                                (vec1.elements[0] * vec2.elements[2]);
    parallel_vect.elements[2] = (vec1.elements[0] * vec2.elements[1]) -
                                (vec1.elements[1] * vec2.elements[0]);

    return parallel_vect;
}


float
magnitude(vector vec) {
    
    return sqrt(magnitudeSquared(vec));
}


float
magnitudeSquared(vector vec) {
    float mag = 0.0f;

    for (unsigned int i = 0; i < vec.size; i++) {
        mag += vec.elements[i] * vec.elements[i];
    }

    return mag; 
}


vector
normalizeVector(vector vec) {
    vector normalized_vect;
    float mag;

    normalized_vect = create(vec.size);
    mag = magnitude(vec);
    for (unsigned int i = 0; i < vec.size; i++) {
        normalized_vect.elements[i] = vec.elements[i] / mag;
    }

    return normalized_vect;
}


void
normalizeVectorTo(vector *vec) {
    float mag;

    mag = magnitude(*vec);
    for (unsigned int i = 0; i < vec->size; i++) {
        vec->elements[i] /= mag;
    }
}