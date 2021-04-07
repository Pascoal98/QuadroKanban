#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fase.h"
#include "file.h"
#define NOME_BUFFER 256


void insertToDo(List* ToDo, Tarefa* a);
void orderByPriority(Fase* head);
void orderByName(Fase* head);
void orderByDate(Fase* head);
void novaTarefa(List* list);
void addTarefa(List* list, char des[]);
int getDate(int dia, int mes, int ano);

unsigned concatenate(unsigned x, unsigned y);

#endif