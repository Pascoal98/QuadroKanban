#include "task.h"

typedef struct doing{
    
    TAREFA *doingID; //ID da tarefa overall para nao perder de vista
    TAREFA *nomePessoa[20];
    TAREFA *dataLimite;
    struct DOING *nextDoing;
}DOING;