#include "task.h"

typedef struct todo{
    
    int *todoID; //ID da tarefa overall para nao perder de vista
    int *prio; // 0-10 dependendo da prioridade da tarefa
    int*dataCriacao;
    struct TODO *nextTodo;
}TODO;
