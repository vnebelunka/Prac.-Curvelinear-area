CC = gcc
FLAGS = -Wall -Wextra -Werror -m32

f3.o: f3.asm
	nasm -f elf32 f3.asm

f2.o: f2.asm
	nasm -f elf32 f2.asm

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
