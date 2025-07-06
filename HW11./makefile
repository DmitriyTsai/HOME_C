CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: prog

prog: main.o temp_api.o
	gcc -o prog main.o temp_api.o

main.o: main.c temp_api.h
	gcc -c -o main.o main.c

temp_api.o: temp_api.c temp_api.h
	gcc -c -o temp_api.o temp_api.c

clean:
	del *.o
	del prog.exe