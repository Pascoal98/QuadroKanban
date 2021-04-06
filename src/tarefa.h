#ifndef TAREFA_H
#define TAREFA_H

typedef struct tarefa{
    int id, prioridade, dataCriacao, dataLimite, dataConclusao;
    char *descricao;
    char *pessoa;
}Tarefa;

Tarefa* novaTarefa();

int getDate(int dia, int mes, int ano);

unsigned concatenate(unsigned x, unsigned y);

#endif