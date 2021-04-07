CC = gcc
CCFLAGS = -Wall -std=c99 -c -g

EXECUTABLE = kanban

all: $(EXECUTABLE)

$(EXECUTABLE) : main.o tarefa.o fase.o file.o func.o
		$(CC) -o $(EXECUTABLE) main.o tarefa.o fase.o file.o func.o
		rm -f main.o tarefa.o fase.o file.o func.o

main.o: main.c
	$(CC) $(CCFLAGS) main.c

tarefa.o: tarefa.c tarefa.h
	$(CC) $(CCFLAGS) tarefa.c

fase.o: fase.c fase.h
	$(CC) $(CCFLAGS) fase.c

file.o: file.c file.h
	$(CC) $(CCFLAGS) file.c

func.o: func.c func.h
	$(CC) $(CCFLAGS) func.c

clean:
	rm -f main.o tarefa.o fase.o file.o func.o kanban