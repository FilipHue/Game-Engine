#include <stdarg.h>
#include <stdio.h>

#include "../../../../src/constants.h"
#include "./collumn_ops.h"
#include "../../matrix.h"
#include "../../../../src/utils.h"


bool
swapCollumns(matrix *mat, unsigned int collumn1, unsigned int collumn2) {
    if (collumn1 > mat->collums || collumn2 > mat->collums || !collumn1 || !collumn2) {
        return false;
    }

    float temp;

    for (unsigned int i = 0; i < mat->rows; i++) {
        temp = mat->elements[i][collumn1 - 1];
        mat->elements[i][collumn1 - 1] = mat->elements[i][collumn2 - 1];
        mat->elements[i][collumn2 - 1] = temp;
    }

    return true;
}

bool
addCollumns(matrix *mat, unsigned int collumn1, unsigned int collumn2) {
    if (collumn1 > mat->collums || collumn2 > mat->collums || !collumn1 || !collumn2) {
        return false;
    }

    for (unsigned int i = 0; i < mat->rows; i++) {
        mat->elements[i][collumn1 - 1] += mat->elements[i][collumn2 - 1];
    }

    return true;
}

bool
multiplyCollumn(matrix *mat, unsigned int collumn, float factor) {
    if (collumn > mat->collums  || !collumn || factor == 0) {
        return false;
    }

    for (unsigned int i = 0; i < mat->rows; i++) {
        mat->elements[i][collumn - 1] *= factor;
    }

    return true;
}

bool
addMultipleCollumns(matrix *mat, unsigned int collumn1, unsigned int collumn2, float factor) {
    if (collumn1 > mat->collums || collumn2 > mat->collums || !collumn1 || !collumn2 || factor == 0) {
        return false;
    }

    for (unsigned int i = 0; i < mat->rows; i++) {
        mat->elements[i][collumn1 - 1] += mat->elements[i][collumn2 - 1] * factor;
    }

    return true;
}
