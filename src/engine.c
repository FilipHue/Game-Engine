#include <stdio.h>

#include "./constants.h"
#include "../MathLibrary/Vectors/vector.h"
#include "../MathLibrary/Vectors/VectorOperations/WithScalar/vector_scalar.h"
#include "../MathLibrary/Vectors/VectorOperations/WithVector/vector_vector.h"
#include "../MathLibrary/Matrices/matrix.h"
#include "../MathLibrary/Matrices/MatricesOperations/WithScalar/matrix_scalar.h"
#include "../MathLibrary/Matrices/MatricesOperations/WithMatrix/matrix_matrix.h"
#include "../MathLibrary/MatVectOps/MatVect/matvect.h"
#include "../MathLibrary/MatVectOps/VectMat/vectmat.h"

int main() {

    matrix mat = createNewMatrix(4, 4, 2.0f, -1.0f, 3.0f, 5.0f,
                                        1.0f, 3.0f, 0.0f, 4.0f,
                                        3.0f, 0.0f, -1.0f, -2.0f,
                                        0.0f, 0.0f, 0.0f, 1.0f);
    vector vec = vector(2.0f, 0.0f, -1.0f, 1.0f);

    vector row_vec = multiplyMatVect(mat, vec);
    printVector(vec);
    printMatrix(mat);

    printVector(row_vec);

    matrix mat1 = createNewMatrix(2, 2, 1.0f, 2.0f, 3.0f, 4.0f);
    matrix mat2 = createNewMatrix(2, 2, 4.0f, 2.0f, 2.0f, 1.0f);
    printMatrix(mat1);
    printMatrix(mat2);
    printMatrix(multiplyMat(mat1, mat2));

    matrix mat3 = matrix(2, 2, 1.0f, 2.0f, 3.0f, 4.0f);
    printMatrix(mat3);


    return 0;
}
