#include "task.h"

typedef struct done{
    
    int *doneID; //ID da tarefa overall para nao perder de vista
    int *dataConclusao;
    struct DONE *nextDone;
}DONE;
