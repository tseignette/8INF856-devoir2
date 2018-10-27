CC = gcc
CFLAGS = -Wall -std=c99

all: build/main.o
	$(CC) $(CFLAGS) -fopenmp $^ -o bin/a.out

tst: build/test_parser.o build/parser.o build/useful.o
	$(CC) $(CFLAGS) $^ -o bin/tst

build/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

build/%.o: tst/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm build/* bin/*