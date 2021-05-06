CC = gcc
FLAGS = -Wall -Wextra -Werror -m32


all: main.o root.o test.o integral.o f1.o df1.o f2.o df2.o f3.o df3.o
	$(CC) $(FLAGS) main.o integral.o root.o test.o  f1.o df1.o f2.o df2.o f3.o df3.o -o area -lm

f3.o: f3.asm
	nasm -f elf32 f3.asm

df3.o: df3.asm
	nasm -f elf32 df3.asm

f1.o: f1.asm
	nasm -f elf32 f1.asm

df1.o: df1.asm
	nasm -f elf32 df1.asm

f2.o: f2.asm
	nasm -f elf32 f2.asm

df2.o: df2.asm
	nasm -f elf32 df2.asm

main.o: main.c funcs.h
	$(CC) $(FLAGS) main.c -c

integral.o: integral.c funcs.h
	$(CC) $(FLAGS) integral.c -c

root.o: root.c funcs.h
	$(CC) $(FLAGS) root.c -c 

test.o: test.c funcs.h
	$(CC) $(FLAGS) test.c -c

test: main.o root.o test.o integral.o
	$(CC) $(FLAGS) main.o integral.o root.o test.o -o test -lm
	./test

clean:
	rm -f *.o
	rm -f test
	rm -f area
