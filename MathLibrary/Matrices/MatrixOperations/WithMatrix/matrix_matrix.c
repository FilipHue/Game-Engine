#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "./matrix_matrix.h"
#include "../../../MatVectOps/MatVect/matvect.h"
#include "../../matrix.h"
#include "../../../Vectors/vector.h"
#include "../../../Vectors/VectorOperations/WithVector/vector_vector.h"


matrix
addMat(matrix mat1, matrix mat2) {
    if (mat1.rows != mat2.rows || mat1.collums != mat2.collums) {
        return MATRIX_UNDEFINED;
    }

    matrix new_matrix;

    new_matrix = createMatrix(mat1.rows, mat1.collums);
    for (unsigned int i = 0; i < new_matrix.rows; i++) {
        for (unsigned int j = 0; j < new_matrix.collums; j++) {
            new_matrix.elements[i][j] = mat1.elements[i][j] + mat2.elements[i][j];
        }
    }

    return new_matrix;
}


bool
addMatBy(matrix *mat1, matrix mat2) {
    if (mat1->rows != mat2.rows || mat1->collums != mat2.collums) {
        return false;
    }

    for (unsigned int i = 0; i < mat1->rows; i++) {
        for (unsigned int j = 0; j < mat1->collums; j++) {
            mat1->elements[i][j] += mat2.elements[i][j];
        }
    }

    return true;
}


matrix
substractMat(matrix mat1, matrix mat2) {
    if (mat1.rows != mat2.rows || mat1.collums != mat2.collums) {
        return MATRIX_UNDEFINED;
    }

    matrix new_matrix;

    new_matrix = createMatrix(mat1.rows, mat1.collums);
    for (unsigned int i = 0; i < new_matrix.rows; i++) {
        for (unsigned int j = 0; j < new_matrix.collums; j++) {
            new_matrix.elements[i][j] = mat1.elements[i][j] - mat2.elements[i][j];
        }
    }

    return new_matrix;
}


bool
substractMatBy(matrix *mat1, matrix mat2) {
    if (mat1->rows != mat2.rows || mat1->collums != mat2.collums) {
        return false;
    }

    for (unsigned int i = 0; i < mat1->rows; i++) {
        for (unsigned int j = 0; j < mat1->collums; j++) {
            mat1->elements[i][j] -= mat2.elements[i][j];
        }
    }

    return true;
}


matrix
multiplyMat(matrix mat1, matrix mat2) {
    if (mat1.collums != mat2.rows) {
        return MATRIX_UNDEFINED;
    }

    vector *rows;
    vector *collumns;

    rows = malloc(mat1.rows * sizeof(vector));
    collumns = malloc(mat2.collums * sizeof(vector));

    for (unsigned int i = 0; i < mat1.rows; i++) {
        rows[i] = getMatrixRow(&mat1, i + 1);
    }

    for (unsigned int i = 0; i < mat2.collums; i++) {
        collumns[i] = getMatrixCollumn(&mat2, i + 1);
    }

    matrix product_matrix;

    product_matrix = createMatrix(mat1.rows, mat2.collums);
    for (unsigned int i = 0; i < mat1.rows; i++) {
        for (unsigned int j = 0; j < mat2.collums; j++) {
            product_matrix.elements[i][j] = dotProduct(rows[i], collumns[j]);
        }
    }

    return product_matrix;
}


matrix
transposeMat(matrix *mat) {
    matrix transpose;
    
    transpose = createMatrix(mat->rows, mat->collums);
    for (unsigned int i = 0; i < mat->rows; i++) {
        for (unsigned int j = 0; j < mat->collums; j++) {
            transpose.elements[i][j] = mat->elements[j][i];
        }
    }

    return transpose;
}

matrix
augmentMat(matrix *mat1, matrix *mat2) {
    if (mat1->rows != mat2->rows) {
        return MATRIX_UNDEFINED;
    }

    matrix augMat;

    augMat = createMatrix(mat1->rows, mat1->collums + mat2->collums);
    for (unsigned int i = 0; i < mat1->rows; i++) {
        unsigned int j;

        for (j = 0; j < mat1->collums; j++) {
            augMat.elements[i][j] = mat1->elements[i][j];
        }

        for (unsigned int t = 0; t < mat2->collums; t++) {
            augMat.elements[i][j + t] = mat2->elements[i][t];
        }
    }

    return augMat;
}
