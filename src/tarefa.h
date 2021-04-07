#ifndef TAREFA_H
#define TAREFA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#define NOME_BUFFER 256
#define maxAno 2999
#define minAno 2000

typedef struct tarefa{
    int id, prioridade, dataCriacao, dataLimite, dataConclusao;
    char descricao[NOME_BUFFER];
    char pessoa[NOME_BUFFER];
    struct tarefa* next;
}Tarefa;

typedef struct {
    int tamanho;
    Tarefa* primeiro;
}List;

List* createList();
int getDate(int dia, int mes, int ano);
unsigned concatenate(unsigned x, unsigned y);
void printToDo(List* list);
void novaTarefa(List* list);
void addTarefa(List* list, char des[]);
void insertSorted(List* list, Tarefa* tarefa);
void taskToDoing(List* ToDo, List* Doing);
void changeName(List* Doing);
void taskToDone(List* Doing, List* Done);
void taskToToDo(List* Done, List* ToDo) ;
void viewBoard(List* ToDo, List* Doing, List* Done);
void personTasks(List* Doing, List* Done);
void viewTasksCrono();

#endif