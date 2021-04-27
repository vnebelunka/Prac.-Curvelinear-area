CC = gcc
FLAGS = -Wall -Wextra -Werror -m32

all: main.o f3.o f2.o
	$(CC) $(FLAGS) main.o f3.o f2.o -o main -lm

f3.o: f3.asm
	nasm -f elf32 f3.asm

f2.o: f2.asm
	nasm -f elf32 f2.asm

main.o: main.c
	$(CC) $(FLAGS) main.c -c


test: main.o f3.o
	$(CC) $(FLAGS) main.o f3.o -o test -lm
	./test
