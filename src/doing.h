#include "task.h"

typedef struct doing{
    
    int *doingID; //ID da tarefa overall para nao perder de vista
    char *nomePessoa[20];
    int *dataLimite;
    struct DOING *nextDoing;
}DOING;