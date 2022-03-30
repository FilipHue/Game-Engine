#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../Matrices/matrix.h"
#include "../../Matrices/MatrixOperations/WithRows/row_ops.h"
#include "./lu.h"


void
luDecomposition(matrix mat, matrix *L, matrix *U) {
    *L = createIdentityMatrix(mat.rows);
    *U = copyMatrixPointer(&mat);
    unsigned int currentRow;

    currentRow = 0;
    for (unsigned int i = 0; i < U->collums; i++) {
        unsigned int j;
        float coefficient, factor;

        j = currentRow;
        if (j == mat.rows) {
            break;
        }
        coefficient = U->elements[currentRow][i];
        for (unsigned int t = currentRow + 1; t < U->rows; t++) {
            factor = U->elements[t][i] / coefficient;
            L->elements[t][i] = factor;
            addMultipleRows(U, t + 1, currentRow + 1, -1 * factor);
        }
        currentRow++;
    }
}