#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include "tarefa.h"
#include "file.h"
#define MAX_SIZE 6

typedef struct list{
    int tamanho;
    Tarefa* primeiro;
}List;


List* createList();
void printToDo(List* list);
void printDoing(List* list);
void printDone(List* list);
void novaTarefa(List* list);
void taskToDoing(List* ToDo, List* Doing);
void taskToDone(List* Doing, List* Done);
void taskToToDo(List* Done, List* ToDo);
void insertSortedPriority(List* list, Tarefa* tarefa);
void insertSortedName(List* list, Tarefa* tarefa);
void insertSortedDate(List* list, Tarefa* tarefa);
Tarefa* searchUntil(List* list, int id);
void deleteFromListId(List* list, int id);

void changeName(List* Doing);
void changePerson(List* list,int id);

void viewBoard(List* ToDo, List* Doing, List* Done);
void personTasks(List* Doing, List* Done);
void viewTasksCrono(List* list1, List* list2, List* list3);
int compareDates(const void *a, const void *b);

void addToDo(List* list, int prio, int id, char des[], int dataCriacao);
void addDoing(List* list, int prio, int id, char des[], int dataCriacao, char pessoa[], int dataLimite);
void addDone(List* list, int prio, int id, char des[], int dataCriacao, char pessoa[], int dataLimite, int dataConclusao);
#endif