CC = gcc
CCFLAGS = -Wall -std=c99 -c -g

EXECUTABLE = kanban

all: $(EXECUTABLE)

$(EXECUTABLE) : main.o task.o
		$(CC) -o $(EXECUTABLE) main.o task.o
		rm -f main.o task.o

main.o: main.c
	$(CC) $(CCFLAGS) main.c

task.o: task.c task.h
	$(CC) $(CCFLAGS) task.c

clean:
	rm -f main.o task.o kanban