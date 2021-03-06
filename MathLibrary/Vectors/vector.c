#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

const vector VECTOR_UNDEFINED = {0, NULL};

vector*
createVector(unsigned int size) {
    vector *new_vect;

    new_vect = malloc(sizeof(vector));
    new_vect->size = size;
    new_vect->elements = malloc(size * sizeof(float));

    return new_vect;
}


vector*
createDefaultVector(unsigned int size, float default_value) {
    vector *new_vector;
    
    new_vector = createVector(size);
    for (unsigned int i = 0; i < size; i++) {
        new_vector->elements[i] = default_value;
    }

    return new_vector;
}


vector*
createEmptyVector(unsigned int size) {
    return createDefaultVector(size, 0.0f);
}


vector*
createNewVector(unsigned int size, ...) {
    vector *new_vector;
    
    new_vector = createVector(size);
    va_list args_list;
    va_start(args_list, size);

    for (unsigned int i = 0; i < size; i++) {
        new_vector->elements[i] = va_arg(args_list, double);
    }

    va_end(args_list);

    return new_vector;
}


vector*
copyVector(vector *vec) {
    vector *copy_vector;

    copy_vector = createVector(vec->size);
    copy_vector->size = vec->size;
    for (unsigned int i = 0; i < vec->size; i++) {
        copy_vector->elements[i] = vec->elements[i];
    }

    return copy_vector;
}


vector*
copyVectorPtr(vector *vec) {
    
    return vec;
}


void
printVector(vector *vec) {
    printf("[");

    for (unsigned int i = 0; i < vec->size; i++) {
        printf("%f", vec->elements[i]);
        if (i < vec->size - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");
}


bool
equalVector(vector *vec1, vector *vec2) {
    if (vec1->size == vec2->size) {
        for (unsigned int i = 0; i < vec1->size; i++) {
            if (vec1->elements[i] != vec2->elements[i]) {
                return false;
            }
        }

        return true;
    }

    return false;
}

void
destroyVect(vector **vec) {
    if (!(*vec)) {
        return;
    }
    free((*vec)->elements);
    free(*vec);
    *vec = NULL;
}
