CC = gcc
FLAGS = -Wall -Wextra -Werror -m32

f3.o: f3.asm
	nasm -f elf32 f3.asm

f2.o: f2.asm
	nasm -f elf32 f2.asm

main.o: main.c
	$(CC) $(FLAGS) main.c -c

foo.o: foo.c
	$(CC) $(FLAGS) foo.c -c 

test.o: test.c
	$(CC) $(FLAGS) test.c -c

test: main.o foo.o test.o
	$(CC) $(FLAGS) main.o foo.o test.o -o test -lm
	./test

clean:
	rm -f *.o
