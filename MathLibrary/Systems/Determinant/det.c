#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./det.h"
#include "../../Vectors/vector.h"
#include "../../Matrices/matrix.h"


matrix
spliceMat(matrix *mat, unsigned int row, unsigned int collumn) {
    matrix new_matrix;
    unsigned int rowOffset;

    new_matrix = createMatrix(mat->rows - 1, mat->collums - 1);
    rowOffset = 0;
    for (unsigned int i = 0; i < new_matrix.rows; i++) {
        unsigned int collOffset;

        collOffset = 0;
        if (i == row - 1) {
            rowOffset++;
        }
        for (unsigned int j = 0; j < new_matrix.collums; j++) {
            if (j == collumn - 1) {
                collOffset++;
            }
            new_matrix.elements[i][j] = mat->elements[i + rowOffset][j + collOffset];
        }
    }

    return new_matrix;
}

float
detMat(matrix mat) {
    if (mat.rows != mat.collums) {
        return 0.0f;
    }
    if (mat.rows == 1) {
        return mat.elements[0][0];
    }

    char sign = 1;
    float det = 0.0f;

    for (unsigned int j = 0; j < mat.collums; j++) {
        matrix spliced = spliceMat(&mat, 1, j + 1);
        det += sign * mat.elements[0][j] * detMat(spliced);
        sign = -sign;
        destroyMat(&spliced);
    }

    return det;
}
