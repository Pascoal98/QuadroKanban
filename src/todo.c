#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "todo.h"

TODO *addToDoTask(TAREFA *a) {

    TODO *b = (TODO*)malloc(sizeof(TODO));
    if(b == NULL)
        fprintf(stderr, "Can't allocate memory for the task\n");
    
    *b->todoID = a->id;
    *b->prio = a->prioridade;
    *b->dataCriacao = a->dataCriacao;
    *b->nextTodo = NULL;
    return *b;
}

