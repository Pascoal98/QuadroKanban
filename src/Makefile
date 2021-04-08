CC = gcc
CCFLAGS = -Wall -std=c99 -c -g

EXECUTABLE = kanban

all: $(EXECUTABLE)

$(EXECUTABLE) : main.o tarefa.o file.o list.o
		$(CC) -o $(EXECUTABLE) main.o tarefa.o file.o list.o
		rm -f main.o tarefa.o fase.o file.o list.o

main.o: main.c
	$(CC) $(CCFLAGS) main.c

tarefa.o: tarefa.c tarefa.h
	$(CC) $(CCFLAGS) tarefa.c

file.o: file.c file.h
	$(CC) $(CCFLAGS) file.c

list.o: list.c list.h
	$(CC) $(CCFLAGS) list.c

clean:
	rm -f main.o tarefa.o fase.o file.o list.o kanban