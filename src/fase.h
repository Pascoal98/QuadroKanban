#include "tarefa.h"

typedef struct fase* Fase;

typedef struct fase {
    Tarefa *tarefa;
    int listId;
    char *nomeTarefa;
    Fase next;
}Fase_node;

Fase criarLista();

void orderById(Fase )