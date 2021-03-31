#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doing.h"

DOING *addDoingTask(TAREFA *a) {

    DOING *b = (DOING*)malloc(sizeof(DOING));
    if(b == NULL)
        fprintf(stderr, "Can't allocate memory for the task\n");
    
    b->doingID = a->id;
    //b->nomePessoa = a->pessoa;
    b->dataLimite = a->dataLimite;
    b->nextDoing = NULL;
    return b;
}

