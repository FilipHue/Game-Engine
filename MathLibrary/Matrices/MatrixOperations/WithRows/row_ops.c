#include <stdarg.h>
#include <stdio.h>

#include "../../../../src/constants.h"
#include "./row_ops.h"
#include "../../matrix.h"
#include "../../../../src/utils.h"


bool
swapRows(matrix *mat, unsigned int row1, unsigned int row2) {
    if (row1 > mat->rows || row2 > mat->rows || !row1 || !row2) {
        return false;
    }

    float *temp;

    temp = mat->elements[row1 - 1];
    mat->elements[row1 - 1] = mat->elements[row2 - 1];
    mat->elements[row2 - 1] = temp;
    
    return true;
}


bool
addRows(matrix *mat, unsigned int row1, unsigned int row2) {
    if (row1 > mat->rows || row2 > mat->rows || !row1 || !row2) {
        return false;
    }

    for (unsigned int i = 0; i < mat->collums; i++) {
        mat->elements[row1 - 1][i] += mat->elements[row2 - 1][i];
    }

    return true;
}


bool
multiplyRow(matrix *mat, unsigned int row, float factor) {
    if (row > mat->rows || !row || factor == 0) {
        return false;
    }

    for (unsigned int i = 0; i < mat->collums; i++) {
        mat->elements[row - 1][i] *= factor;
    }

    return true;
}


bool
addMultipleRows(matrix *mat, unsigned int row1, unsigned int row2, float factor) {
    if (row1 > mat->rows || row2 > mat->rows || !row1 || !row2 || factor == 0) {
        return false;
    }
    
    for (unsigned int i = 0; i < mat->collums; i++) {
        mat->elements[row1 - 1][i] += mat->elements[row2 - 1][i] * factor;
    }

    return true;
}
