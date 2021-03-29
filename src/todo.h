#include "task.h"

typedef struct todo{
    
    TAREFA *todoID; //ID da tarefa overall para nao perder de vista
    TAREFA *prio; // 0-10 dependendo da prioridade da tarefa
    TAREFA *dataCriacao;

}TODO;
