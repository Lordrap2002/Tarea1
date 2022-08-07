all: tarea
tarea: main
	gcc -o tarea main.o
main: main.c
	gcc -c main.c