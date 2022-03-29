#include <stdlib.h>
#include <stdio.h>

#include "../../Vectors/vector.h"
#include "../../Vectors/VectorOperations/WithVector/vector_vector.h"
#include "../../Matrices/matrix.h"
#include "./matvect.h"


vector
getMatrixRow(matrix *mat, int row) {
    if (row < 1 || row > (int)mat->rows) {
        return VECTOR_UNDEFINED;
    }

    vector vec_row;
    vec_row = createVector(mat->collums);

    for (unsigned int i = 0; i < vec_row.size; i++) {
        vec_row.elements[i] = mat->elements[row - 1][i];
    }

    return vec_row;
}


vector
getMatrixCollumn(matrix *mat, int collumn) {
    if (collumn < 1 || collumn > (int)mat->rows) {
        return VECTOR_UNDEFINED;
    }

    vector vec_collumn;
    vec_collumn = createVector(mat->rows);

    for (unsigned int i = 0; i < vec_collumn.size; i++) {
        vec_collumn.elements[i] = mat->elements[i][collumn - 1];
    }

    return vec_collumn;
}


vector
multiplyMatVect(matrix mat, vector vec) {
    if (mat.collums != vec.size) {
        return VECTOR_UNDEFINED;
    }

    vector row_vect;

    row_vect = createVector(mat.rows);
    for (unsigned int i = 0; i < row_vect.size; i++) {
        row_vect.elements[i] = dotProduct(vec, getMatrixRow(&mat, i + 1));
    }

    return row_vect;
}
