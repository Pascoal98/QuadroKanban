#ifndef TAREFA_H
#define TAREFA_H
#define NOME_BUFFER 256

typedef struct tarefa{
    int id, prioridade, dataCriacao, dataLimite, dataConclusao;
    char descricao[NOME_BUFFER];
    char pessoa[NOME_BUFFER];
}Tarefa;

#endif