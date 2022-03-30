#include <stdio.h>

#include "./constants.h"
#include "../MathLibrary/Vectors/vector.h"
#include "../MathLibrary/Vectors/VectorOperations/WithScalar/vector_scalar.h"
#include "../MathLibrary/Vectors/VectorOperations/WithVector/vector_vector.h"
#include "../MathLibrary/Matrices/matrix.h"
#include "../MathLibrary/Matrices/MatrixOperations/WithScalar/matrix_scalar.h"
#include "../MathLibrary/Matrices/MatrixOperations/WithMatrix/matrix_matrix.h"
#include "../MathLibrary/Matrices/MatrixOperations/WithRows/row_ops.h"
#include "../MathLibrary/Matrices/MatrixOperations/WithCollumns/collumn_ops.h"
#include "../MathLibrary/MatVectOps/MatVect/matvect.h"
#include "../MathLibrary/MatVectOps/VectMat/vectmat.h"
#include "../MathLibrary/Systems/Ref/ref.h"
#include "../MathLibrary/Systems/RRef/rref.h"
#include "../MathLibrary/Systems/Determinant/det.h"
#include "../MathLibrary/Systems/LU/lu.h"

int main() {
    matrix m = matrix(3, 3,
                            -2.0, 1.0, 3.0,
                            -4.0, 4.0, 1.0,
                            6.0, 3.0, -1.0);

    matrix L, U;
    float d1, d2;
    d1 = detMat(m);
    d2 = luDet(m);
    printf("%f\n%f\n", d1, d2);
    return 0;
}
