#include <stdlib.h>
#include <stdio.h>

#include "../../Vectors/vector.h"
#include "../../Matrices/matrix.h"
#include "./vectmat.h"


matrix*
MatrixRowToVector(vector *vec) {
    matrix *row_mat;

    row_mat = createMatrix(1, vec->size);
    for (unsigned int i = 0; i < vec->size; i++) {
        row_mat->elements[0][i] = vec->elements[i];
    }

    return row_mat;
}


matrix*
MatrixCollumnToVector(vector *vec) {
    matrix *collumn_mat;

    collumn_mat = createMatrix(vec->size, 1);
    for (unsigned int i = 0; i < vec->size; i++) {
        collumn_mat->elements[i][0] = vec->elements[i];
    }

    return collumn_mat;
}

matrix*
augmentVect(matrix *mat, vector *vec) {
    if (vec->size != mat->rows) {
        return NULL;
    }

    matrix *augMat;

    augMat = createMatrix(mat->rows, mat->collums + 1);
    for (unsigned int i = 0; i < mat->rows; i++) {
        unsigned int j;

        j = 0;
        for (; j < mat->collums; j++) {
            augMat->elements[i][j] = mat->elements[i][j];
        }

        augMat->elements[i][j] = vec->elements[i];
    }

    return augMat;
}
