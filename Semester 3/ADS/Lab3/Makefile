all: main

main.o: main.c 
	gcc -Wall -O3 -c main.c

Huffman.o: Huffman.c Huffman.h
	gcc -Wall -O3 -c Huffman.c

main: main.o Huffman.o
	gcc -o main main.o Huffman.o

clean:
	rm main.exe *.o

.PHONY: clean all