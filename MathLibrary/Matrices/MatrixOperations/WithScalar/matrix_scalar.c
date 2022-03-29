#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "./matrix_scalar.h"
#include "../../matrix.h"


matrix
addMatScalar(matrix mat, float scalar) {
    matrix new_matrix;

    new_matrix = createMatrix(mat.rows, mat.collums);
    for (unsigned int i = 0; i < mat.rows; i++) {
        for (unsigned int j = 0; j < mat.collums; j++) {
            new_matrix.elements[i][j] = mat.elements[i][j] + scalar;
        }
    }

    return new_matrix;
}

void
addMatScalarBy(matrix *mat, float scalar) {
    for (unsigned int i = 0; i < mat->rows; i++) {
        for (unsigned int j = 0; j < mat->collums; j++) {
            mat->elements[i][j] += scalar;
        }
    }
}


matrix
subtractMatScalar(matrix mat, float scalar) {
    matrix new_matrix;

    new_matrix = createMatrix(mat.rows, mat.collums);
    for (unsigned int i = 0; i < mat.rows; i++) {
        for (unsigned int j = 0; j < mat.collums; j++) {
            new_matrix.elements[i][j] = mat.elements[i][j] - scalar;
        }
    }

    return new_matrix;
}


void
subtractMatScalarBy(matrix *mat, float scalar) {
    for (unsigned int i = 0; i < mat->rows; i++) {
        for (unsigned int j = 0; j < mat->collums; j++) {
            mat->elements[i][j] -= scalar;
        }
    }
}


matrix
divisionMatScalar(matrix mat, float scalar) {
    matrix new_matrix;

    new_matrix = createMatrix(mat.rows, mat.collums);
    for (unsigned int i = 0; i < mat.rows; i++) {
        for (unsigned int j = 0; j < mat.collums; j++) {
            new_matrix.elements[i][j] = mat.elements[i][j] / scalar;
        }
    }

    return new_matrix;
}


void
divisionMatScalarBy(matrix *mat, float scalar) {
    for (unsigned int i = 0; i < mat->rows; i++) {
        for (unsigned int j = 0; j < mat->collums; j++) {
            mat->elements[i][j] /= scalar;
        }
    }
}


matrix
multiplyMatScalar(matrix mat, float scalar) {
    matrix new_matrix;

    new_matrix = createMatrix(mat.rows, mat.collums);
    for (unsigned int i = 0; i < mat.rows; i++) {
        for (unsigned int j = 0; j < mat.collums; j++) {
            new_matrix.elements[i][j] = mat.elements[i][j] * scalar;
        }
    }

    return new_matrix;
}


void
multiplyMatScalarBy(matrix *mat, float scalar) {
    for (unsigned int i = 0; i < mat->rows; i++) {
        for (unsigned int j = 0; j < mat->collums; j++) {
            mat->elements[i][j] *= scalar;
        }
    }
}


matrix
powerMatrix(matrix mat, float power) {
    matrix new_matrix;

    new_matrix = createMatrix(mat.rows, mat.collums);
    for (unsigned int i = 0; i < mat.rows; i++) {
        for (unsigned int j = 0; j < mat.collums; j++) {
            new_matrix.elements[i][j] = pow(mat.elements[i][j], power);
        }
    }

    return new_matrix;
}


void
powerMatrixBy(matrix *mat, float scalar) {
    for (unsigned int i = 0; i < mat->rows; i++) {
        for (unsigned int j = 0; j < mat->collums; j++) {
            pow(mat->elements[i][j], scalar);
        }
    }
}
