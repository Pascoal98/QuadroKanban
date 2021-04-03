#include "tarefa.h"

typedef struct fase* Fase;

typedef struct fase {
    Tarefa *tarefa;
    int faseId;
    char *nomeTarefa;
    Fase next;
}Fase_node;

Fase criarLista();

void orderById(Fase );