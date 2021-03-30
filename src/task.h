typedef struct tarefa{
    int fase = 0;  // 0 = ToDo, 1 = Doing, 2 = Done;
    int id;
    int prioridade;
    char descricao[50];
    char pessoa[20];
    int dataCriacao;
    int dataLimite;
    int dataConclusao;
    struct TAREFA *next;
}TAREFA;