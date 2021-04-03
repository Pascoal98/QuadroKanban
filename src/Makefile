CC = gcc
CCFLAGS = -Wall -std=c99 -c -g

EXECUTABLE = kanban

all: $(EXECUTABLE)

$(EXECUTABLE) : main.o tarefa.o fase.o
		$(CC) -o $(EXECUTABLE) main.o tarefa.o fase.o
		rm -f main.o tarefa.o fase.o

main.o: main.c
	$(CC) $(CCFLAGS) main.c

tarefa.o: tarefa.c tarefa.h
	$(CC) $(CCFLAGS) tarefa.c

fase.o: fase.c fase.h
	$(CC) $(CCFLAGS) fase.c

clean:
	rm -f main.o tarefa.o fase.o kanban