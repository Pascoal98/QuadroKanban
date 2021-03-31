CC = gcc
CCFLAGS = -Wall -std=c99 -c -g

EXECUTABLE = kanban

all: $(EXECUTABLE)

$(EXECUTABLE) : main.o task.o todo.o doing.o done.o
		$(CC) -o $(EXECUTABLE) main.o task.o todo.o doing.o done.o
		rm -f main.o task.o todo.o doing.o done.o


main.o: main.c
	$(CC) $(CCFLAGS) main.c

task.o: task.c task.h
	$(CC) $(CCFLAGS) task.c

todo.o: todo.c todo.h
	$(CC) $(CCFLAGS) todo.c

doing.o: doing.c doing.h
	$(CC) $(CCFLAGS) doing.c

done.o: done.c done.h
	$(CC) $(CCFLAGS) done.c

clean:
	rm -f main.o task.o todo.o doing.o done.o kanban