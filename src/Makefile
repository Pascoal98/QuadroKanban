CC = gcc
CCFLAGS = -Wall -std=c99 -c -g

EXECUTABLE = kanban

all: $(EXECUTABLE)

$(EXECUTABLE) : main.o tarefa.o
		$(CC) -o $(EXECUTABLE) main.o tarefa.o
		rm -f main.o tarefa.o

main.o: main.c
	$(CC) $(CCFLAGS) main.c

tarefa.o: tarefa.c tarefa.h
	$(CC) $(CCFLAGS) tarefa.c

clean:
	rm -f main.o tarefa.o kanban