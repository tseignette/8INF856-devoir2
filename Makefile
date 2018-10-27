CC = gcc
CFLAGS = -Wall -std=c99

all: d2s d2p

d2s: build/d2s.o
	$(CC) $(CFLAGS) $^ -o bin/d2s

d2p: build/d2p.o
	$(CC) $(CFLAGS) -fopenmp $^ -o bin/d2p

build/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm build/* bin/*