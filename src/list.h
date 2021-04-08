#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include "tarefa.h"

typedef struct {
    int tamanho;
    Tarefa* primeiro;
}List;

List* createList();
void printList(List* list);
void printIds(List* list);
void printNames(List* list);
void novaTarefa(List* list);
void taskToDoing(List* ToDo, List* Doing);
void taskToDone(List* Doing, List* Done);
void taskToToDo(List* Done, List* ToDo);
void insertSortedPriority(List* list, Tarefa* tarefa);
void insertSortedName(List* list, Tarefa* tarefa);
Tarefa* searchUntil(List* list, int id);
void deleteFromListId(List* list, int id);


void changeName(List* Doing);
void change(List* list,int id);


void viewBoard(List* ToDo, List* Doing, List* Done);
void personTasks(List* Doing, List* Done);
void viewTasksCrono();

#endif