#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../../vector.h"
#include "../../../../src/constants.h"
#include "vector_scalar.h"


vector
scalarMultiplication(vector vec, float scalar) {
    vector new_vector;

    new_vector = create(vec.size);
    for (unsigned int i = 0; i < vec.size; i++) {
        new_vector.elements[i] = vec.elements[i] * scalar;
    }

    return new_vector;
}


void
scalarMultiplicationBy(vector *vec, float scalar) {
    for (unsigned int i = 0; i < vec->size; i++) {
        vec->elements[i] *= scalar;
    }
}


vector
scalarDivision(vector vec, float scalar) {
    vector new_vector;

    new_vector = create(vec.size);
    for (unsigned int i = 0; i < vec.size; i++) {
        new_vector.elements[i] = vec.elements[i] / scalar;
    }

    return new_vector;
}


void
scalarDivisionBy(vector *vec, float scalar) {
    for (unsigned int i = 0; i < vec->size; i++) {
        vec->elements[i] /= scalar;
    }
}


vector
powerVector(vector vec, float power) {
    vector new_vector;

    new_vector = create(vec.size);
    for (unsigned int i = 0; i < vec.size; i++) {
        new_vector.elements[i] = pow(vec.elements[i], power);
    }

    return new_vector;
}


void
powerVectorTo(vector *vec, float power) {
    for (unsigned int i = 0; i < vec->size; i++) {
        pow(vec->elements[i], power);
    }
}
