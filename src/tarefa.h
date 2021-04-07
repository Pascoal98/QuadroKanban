#ifndef TAREFA_H
#define TAREFA_H

#include <stdio.h>
#include <stdlib.h>
#define NOME_BUFFER 256

typedef struct tarefa{
    int id, prioridade, dataCriacao, dataLimite, dataConclusao;
    char descricao[NOME_BUFFER];
    char pessoa[NOME_BUFFER];
    struct tarefa* next;
}Tarefa;

typedef struct {
    int tamanho;
    Tarefa* primeiro;
    Tarefa* ultimo;
}List;

List* createList();
int getDate(int dia, int mes, int ano);
unsigned concatenate(unsigned x, unsigned y);


#endif