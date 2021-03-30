#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "done.h"

DONE *addDoneTask(TAREFA *a) {

    DONE *b = (DONE*)malloc(sizeof(DONE));
    if(b == NULL)
        fprintf(stderr, "Can't allocate memory for the task\n");
    
    *b->doNEID = a->id;
    *b->dataConclusao = a->dataConclusao;
    *b->nextDoNE = NULL;
    return *b;
}
