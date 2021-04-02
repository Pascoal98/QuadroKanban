#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "done.h"

DONE *addDoneTask(TAREFA *a) {

    DONE *b = (DONE*)malloc(sizeof(DONE));
    if(b == NULL)
        printf("Can't allocate memory for the task\n");
    
    b->doneID = &a->id;
    b->dataConclusao = &a->dataConclusao;
    b->nextDone = NULL;
    return b;
}
