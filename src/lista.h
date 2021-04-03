#include "tarefa.h"

typedef struct lista* Lista;

typedef struct lista {
    Tarefa *tarefa;
    int listId;
    char *nomeTarefa;
    Lista next;
}List;

Lista criarLista();