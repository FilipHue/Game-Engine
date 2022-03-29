#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "matrix.h"

const matrix MATRIX_UNDEFINED = {0, 0, NULL};


matrix
createMatrix(unsigned int rows, unsigned int collums) {
    matrix new_matrix;

    new_matrix.rows = rows;
    new_matrix.collums = collums;
    new_matrix.elements = malloc(rows * sizeof(float *));
    for (unsigned int i = 0; i < rows; i++) {
        new_matrix.elements[i] = malloc(collums * sizeof(float));
    }

    return new_matrix;
}


matrix
createIdentityMatrix(unsigned int size) {
    matrix new_matrix;
    
    new_matrix = createMatrix(size, size);
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < size; j++) {
            new_matrix.elements[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }

    return new_matrix;
}


matrix
createDefaultMatrix(unsigned int rows, unsigned int collumns, float default_value) {
    matrix new_matrix;
    
    new_matrix = createMatrix(rows, collumns);
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < collumns; j++) {
            new_matrix.elements[i][j] = default_value;
        }
    }

    return new_matrix;
}


matrix
createZeroMatrix(unsigned int rows, unsigned int collumns) {
    
    return createDefaultMatrix(rows, collumns, 0.0f);
}


matrix
createNewMatrix(unsigned int rows, unsigned int collumns, ...) {
    matrix new_matrix;
    unsigned int copy_collumns;

    new_matrix = createMatrix(rows, collumns);
    copy_collumns = collumns;
    collumns *= rows;

    va_list args_list;
    va_start(args_list, collumns);

    collumns = copy_collumns;
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < collumns; j++) {
            new_matrix.elements[i][j] = va_arg(args_list, double);
        }
    }

    va_end(args_list);

    return new_matrix;
}


matrix
copyMatrix(matrix mat) {
    return mat;
}


matrix
copyMatrixPointer(matrix *mat) {
    matrix new_matrix;

    memcpy(&new_matrix, mat, sizeof(matrix));

    return new_matrix;
}


void
printMatrix(matrix mat) {
    for (unsigned int i = 0; i < mat.rows; i++) {
        printf("|");
        for (unsigned int j = 0; j < mat.collums; j++) {
            printf("%f", mat.elements[i][j]);
            if (j < mat.collums - 1) {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("\n");
}


bool
equalMatrix(matrix mat1, matrix mat2) {
    if (mat1.rows == mat2.rows && mat1.collums == mat2.collums) {
        for (unsigned int i = 0; i < mat1.rows; i++) {
            for (unsigned int j = 0; j < mat1.collums; j++) {
                if (mat1.elements[i][j] != mat2.elements[i][j]) {

                    return false;
                }
            }
        }

        return true;
    }

    return false;
}
