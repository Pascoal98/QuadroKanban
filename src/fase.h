#ifndef FASE_H
#define FASE_H

#include <stdio.h>
#include <stdlib.h>
#include "tarefa.h"
#define NOME_BUFFER 256

typedef struct fase {
    Tarefa *tarefa;
    char nomeTarefa[NOME_BUFFER];
    struct fase* next;
}Fase;

typedef struct {
    int tamanho;
    Fase* primeiro;
    Fase* ultimo;
}List;

List* createList();

#endif