typedef struct tarefa{
    int id, prioridade, dataCriacao, dataLimite, dataConclusao;
    char *descricao;
    char *pessoa;
}Tarefa;

Tarefa* novaTarefa(Tarefa **head_ref);