CC = gcc
CCFLAGS = -Wall -std=c99 -c -g

EXECUTABLE = kanban

all: $(EXECUTABLE)

$(EXECUTABLE) : main.o tarefa.o lista.o
		$(CC) -o $(EXECUTABLE) main.o tarefa.o lista.o
		rm -f main.o tarefa.o lista.o

main.o: main.c
	$(CC) $(CCFLAGS) main.c

tarefa.o: tarefa.c tarefa.h
	$(CC) $(CCFLAGS) tarefa.c

lista.o: lista.c lista.h
	$(CC) $(CCFLAGS) lista.c

clean:
	rm -f main.o tarefa.o lista.o kanban