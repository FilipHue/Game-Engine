CC = gcc
CFLAGS = -Wall -Wextra -std=c99
DEBUG = -g -ggdb -O0 -march=native
VECTOR_PATH = MathLibrary/Vectors
VECTOR_PATH_OPS = $(VECTOR_PATH)/VectorOperations
TARGETS = src/engine
TARGETS_O = src/engine.o $(VECTOR_PATH)/vector.o \
						$(VECTOR_PATH_OPS)/WithScalar/vector_scalar.o \
						$(VECTOR_PATH_OPS)/WithVector/vector_vector.o

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

run:
	./$(TARGETS)

val:
	valgrind ./$(TARGETS)

clean:
	rm -f $(VECTOR_PATH)/*.o
	rm -f $(VECTOR_PATH_OPS)/WithScalar/*.o
	rm -f $(VECTOR_PATH_OPS)/WithVector/*.o
	rm -f $(TARGETS)
	rm -f src/*.o
	clear