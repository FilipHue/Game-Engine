#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../Matrices/MatrixOperations/WithRows/row_ops.h"
#include "../../Matrices/matrix.h"
#include "./rref.h"

void
rref(matrix *mat) {
    unsigned int currentRow;

    currentRow = 0;
    for (unsigned int i = 0; i < mat->collums; i++) {
        unsigned int j;

        j = currentRow;
        if (j >= mat->rows) {
            break;
        }
        for (; j < mat->rows; j++) {
            if (mat->elements[j][i] != 0.0f) {
                break;
            }
        }
        if (j == mat->rows) {
            continue;
        }
        swapRows(mat, currentRow + 1, j + 1);
        float factor;

        factor = 1/ mat->elements[currentRow][i];
        for (unsigned int c = i; c < mat->collums; c++) {
            mat->elements[currentRow][c] *= factor;
        }
        for (unsigned int r = 0; r < mat->rows; r++) {
            if (r != currentRow) {
                addMultipleRows(mat, r + 1, currentRow + 1, -1 * mat->elements[r][i]);
            }
        }
        currentRow++;
    }
}
