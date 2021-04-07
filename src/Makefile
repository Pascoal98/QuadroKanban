CC = gcc
CCFLAGS = -Wall -std=c99 -c -g

EXECUTABLE = kanban

all: $(EXECUTABLE)

$(EXECUTABLE) : main.o tarefa.o file.o print.o
		$(CC) -o $(EXECUTABLE) main.o tarefa.o file.o print.o
		rm -f main.o tarefa.o fase.o file.o print.o

main.o: main.c
	$(CC) $(CCFLAGS) main.c

tarefa.o: tarefa.c tarefa.h
	$(CC) $(CCFLAGS) tarefa.c

file.o: file.c file.h
	$(CC) $(CCFLAGS) file.c

print.o: print.c print.h
	$(CC) $(CCFLAGS) print.c

clean:
	rm -f main.o tarefa.o fase.o file.o print.o kanban