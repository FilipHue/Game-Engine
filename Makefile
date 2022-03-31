CC = gcc
CFLAGS = -Wall -Wextra -std=c99
DEBUG = -g -ggdb -O0 -march=native
VECTOR_PATH = MathLibrary/Vectors
VECTOR_PATH_OPS = $(VECTOR_PATH)/VectorOperations
MATRIX_PATH = MathLibrary/Matrices
MATRIX_PATH_OPS = $(MATRIX_PATH)/MatrixOperations
MATVECT_OPS = MathLibrary/MatVectOps/MatVect
SYSTEMS = MathLibrary/Systems
VECTMAT_OPS = MathLibrary/MatVectOps/VectMat
TARGETS = src/engine
TARGETS_O = src/engine.o $(VECTOR_PATH)/vector.o \
						$(VECTOR_PATH_OPS)/WithScalar/vector_scalar.o \
						$(VECTOR_PATH_OPS)/WithVector/vector_vector.o \
						$(MATRIX_PATH)/matrix.o \
						$(MATRIX_PATH_OPS)/WithScalar/matrix_scalar.o \
						$(MATRIX_PATH_OPS)/WithMatrix/matrix_matrix.o \
						$(MATVECT_OPS)/matvect.o \
						$(MATRIX_PATH_OPS)/WithRows/row_ops.o \
						$(VECTMAT_OPS)/vectmat.o \
						$(MATRIX_PATH_OPS)/WithCollumns/collumn_ops.o \
						$(SYSTEMS)/Ref/ref.o \
						$(SYSTEMS)/RRef/rref.o \
						$(SYSTEMS)/Determinant/det.o \
						$(SYSTEMS)/LU/lu.o

build: $(TARGETS)

src/engine: $(TARGETS_O)
		$(CC) $(CFLAGS) $(DEBUG) $(TARGETS_O) -o $(TARGETS) -lm

$(VECTOR_PATH)/vector.o: $(VECTOR_PATH)/vector.h $(VECTOR_PATH)/vector.c
		$(CC) $(CFLAGS) $(DEBUG) $(VECTOR_PATH)/vector.c \
								-c -o $(VECTOR_PATH)/vector.o

$(VECTOR_PATH_OPS)/WithScalar/vector_scalar.o: \
											$(VECTOR_PATH_OPS)/WithScalar/vector_scalar.h \
											$(VECTOR_PATH_OPS)/WithScalar/vector_scalar.c
		$(CC) $(CFLAGS) $(DEBUG) $(VECTOR_PATH_OPS)/WithScalar/vector_scalar.c \
								-c -o $(VECTOR_PATH_OPS)/WithScalar/vector_scalar.o

$(VECTOR_PATH_OPS)/WithScalar/vector_vector.o: \
											$(VECTOR_PATH_OPS)/WithScalar/vector_vector.h \
											$(VECTOR_PATH_OPS)/WithScalar/vector_vector.c
		$(CC) $(CFLAGS) $(DEBUG) $(VECTOR_PATH_OPS)/WithScalar/vector_vector.c \
								-c -o $(VECTOR_PATH_OPS)/WithScalar/vector_vector.o

$(MATRIX_PATH)/matrix.o: $(MATRIX_PATH)/matrix.h  $(MATRIX_PATH)/matrix.c
		$(CC) $(CFLAGS) $(DEBUG) $(MATRIX_PATH)/matrix.c \
								-c -o $(MATRIX_PATH)/matrix.o

$(MATRIX_PATH_OPS)/WithScalar/matrix_scalar.o : \
											$(MATRIX_PATH_OPS)/WithScalar/matrix_scalar.h \
											$(MATRIX_PATH_OPS)/WithScalar/matrix_scalar.c
		$(CC) $(CFLAGS) $(DEBUG) $(MATRIX_PATH_OPS)/WithScalar/matrix_scalar.c \
								-c -o $(MATRIX_PATH_OPS)/WithScalar/matrix_scalar.o

$(MATRIX_PATH_OPS)/WithMatrix/matrix_matrix.o : \
											$(MATRIX_PATH_OPS)/WithMatrix/matrix_matrix.h \
											$(MATRIX_PATH_OPS)/WithMatrix/matrix_matrix.c
		$(CC) $(CFLAGS) $(DEBUG) $(MATRIX_PATH_OPS)/WithMatrix/matrix_matrix.c \
								-c -o $(MATRIX_PATH_OPS)/WithMatrix/matrix_matrix.o

$(MATRIX_PATH_OPS)/WithRows/row_ops.o : \
									$(MATRIX_PATH_OPS)/WithRows/row_ops.h \
									$(MATRIX_PATH_OPS)/WithRows/row_ops.c
		$(CC) $(CFLAGS) $(DEBUG) $(MATRIX_PATH_OPS)/WithRows/row_ops.c \
								-c -o $(MATRIX_PATH_OPS)/WithRows/row_ops.o

$(MATRIX_PATH_OPS)/WithCollumns/collumn_ops.o : \
									$(MATRIX_PATH_OPS)/WithCollumns/collumn_ops.h \
									$(MATRIX_PATH_OPS)/WithCollumns/collumn_ops.c
		$(CC) $(CFLAGS) $(DEBUG) $(MATRIX_PATH_OPS)/WithCollumns/collumn_ops.c \
								-c -o $(MATRIX_PATH_OPS)/WithCollumns/collumn_ops.o

$(MATVECT_OPS)/matvect.o: $(MATVECT_OPS)/matvect.h $(MATVECT_OPS)/matvect.c
		$(CC) $(CFLAGS) $(DEBUG) $(MATVECT_OPS)/matvect.c \
								-c -o $(MATVECT_OPS)/matvect.o

$(VECTMAT_OPS)/vectmat.o: $(VECTMAT_OPS)/vectmat.h $(VECTMAT_OPS)/vectmat.c
		$(CC) $(CFLAGS) $(DEBUG) $(VECTMAT_OPS)/vectmat.c \
								-c -o $(VECTMAT_OPS)/vectmat.o

$(SYSTEMS)/Ref/ref.o: $(SYSTEMS)/Ref/ref.h $(SYSTEMS)/Ref/ref.c
		$(CC) $(CFLAGS) $(DEBUG) $(SYSTEMS)/Ref/ref.c \
								-c -o $(SYSTEMS)/Ref/ref.o

$(SYSTEMS)/RRef/rref.o: $(SYSTEMS)/RRef/rref.h $(SYSTEMS)/RRef/rref.c
		$(CC) $(CFLAGS) $(DEBUG) $(SYSTEMS)/RRef/rref.c \
								-c -o $(SYSTEMS)/RRef/rref.o

$(SYSTEMS)/Determinant/det.o: $(SYSTEMS)/Determinant/det.h $(SYSTEMS)/Determinant/det.c
		$(CC) $(CFLAGS) $(DEBUG) $(SYSTEMS)/Determinant/det.c \
								-c -o $(SYSTEMS)/Determinant/det.o

$(SYSTEMS)/LU/lu.o: $(SYSTEMS)/LU/lu.h $(SYSTEMS)/LU/lu.c
		$(CC) $(CFLAGS) $(DEBUG) $(SYSTEMS)/LU/lu.c \
								-c -o $(SYSTEMS)/LU/lu.o

run:
	./$(TARGETS)

val:
	valgrind --leak-check=full ./$(TARGETS)

clean:
	rm -f $(VECTOR_PATH)/*.o
	rm -f $(VECTOR_PATH_OPS)/WithScalar/*.o
	rm -f $(VECTOR_PATH_OPS)/WithVector/*.o
	rm -f $(MATRIX_PATH)/*.o
	rm -f $(MATRIX_PATH_OPS)/WithScalar/*.o
	rm -f $(MATRIX_PATH_OPS)/WithMatrix/*.o
	rm -f $(MATRIX_PATH_OPS)/WithRows/*.o
	rm -f $(MATRIX_PATH_OPS)/WithCollumns/*.o
	rm -f $(MATVECT_OPS)/*.o
	rm -f $(VECTMAT_OPS)/*.o
	rm -f $(SYSTEMS)/Ref/*.o
	rm -f $(SYSTEMS)/RRef/*.o
	rm -f $(SYSTEMS)/Determinant/*.o
	rm -f $(SYSTEMS)/LU/*.o
	rm -f $(TARGETS)
	rm -f src/*.o
	clear