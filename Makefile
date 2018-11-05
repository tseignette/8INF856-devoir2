CC = gcc
CFLAGS = -Wall -std=c99 -fopenmp $(FLAG)

all: d2s d2p generator

generator: build/generator.o
	$(CC) $(CFLAGS) $^ -o bin/generator

d2s: build/d2s.o
	$(CC) $(CFLAGS) $^ -o bin/d2s

d2p: build/d2p.o
	$(CC) $(CFLAGS) $^ -o bin/d2p

build/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm build/* bin/*