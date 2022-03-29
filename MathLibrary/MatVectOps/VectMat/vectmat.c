#include <stdlib.h>
#include <stdio.h>

#include "../../Vectors/vector.h"
#include "../../Matrices/matrix.h"
#include "./vectmat.h"


matrix
MatrixRowToVector(vector *vec) {
    matrix row_mat;

    row_mat = createMatrix(1, vec->size);
    for (unsigned int i = 0; i < vec->size; i++) {
        row_mat.elements[0][i] = vec->elements[i];
    }

    return row_mat;
}


matrix
MatrixCollumnToVector(vector *vec) {
    matrix collumn_mat;

    collumn_mat = createMatrix(vec->size, 1);
    for (unsigned int i = 0; i < vec->size; i++) {
        collumn_mat.elements[i][0] = vec->elements[i];
    }

    return collumn_mat;
}
