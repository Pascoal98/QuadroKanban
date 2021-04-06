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

Fase* criarLista(char nome[]);
void orderByPriority(Fase* head);
void orderByName(Fase* head);
void orderByDate(Fase* head);