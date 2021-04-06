#include "tarefa.h"

typedef struct fase* Fase;

typedef struct fase {
    Tarefa *tarefa;
    int faseId;
    char *nomeTarefa;
    Fase next;
}Phase;

Fase criarLista();

void orderByPriority(Fase head);

void orderByName(Fase head);

void orderByDate(Fase head);