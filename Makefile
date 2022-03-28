CC = gcc
CFLAGS = -Wall -Wextra -std=c99
DEBUG = -g -ggdb -O0 -march=native
TARGETS = src/engine
TARGETS_O = src/engine.o src/vector.o src/vector_funcs.o

build: $(TARGETS)

src/engine: $(TARGETS_O)
		$(CC) $(CFLAGS) $(DEBUG) $(TARGETS_O) -o $(TARGETS) -lm

src/vector.o: src/vector.h src/vector.c
		$(CC) $(CFLAGS) $(DEBUG) src/vector.c -c -o src/vector.o

src/vector_funcs.o: src/vector_funcs.h src/vector_funcs.c
		$(CC) $(CFLAGS) $(DEBUG) src/vector_funcs.c -c -o src/vector_funcs.o

run:
	./$(TARGETS)

val:
	valgrind ./$(TARGETS)

clean:
	rm -f src/*.o
	rm -f $(TARGETS)
	clear