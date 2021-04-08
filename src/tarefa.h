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

int getDate(int dia, int mes, int ano);
unsigned concatenate(unsigned x, unsigned y);

void readDescTarefa(Tarefa* tarefa);

void setPessoaTarefa(Tarefa* tarefa);

void setStartDate(Tarefa* tarefa);
void setFinishDate(Tarefa* tarefa);
void setLimitDate(Tarefa* tarefa);
void setPriority(Tarefa* tarefa);
#endif