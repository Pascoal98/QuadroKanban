#include "func.h"

void novaTarefa(List* list) {

    char des[NOME_BUFFER];
    printf("Faça uma breve descrição da tarefa: \n");
    fgets(des,sizeof(des),stdin);
    des[strlen(des)-1] = '\0';
    addTarefa(list,des);
}

void addTarefa(List* list, char des[]) {
    Tarefa* tarefa = malloc(sizeof(Tarefa));

    if(tarefa == NULL) {
        printf("Erro a alocar espaço para a Tarefa.\n");
        exit(1);
    }

    tarefa->id= manageId();
    printf("Introduza a prioridade: ");
    scanf("%d", &tarefa->prioridade);
    int dia,mes,ano;
    printf("Introduza a data - DD/MM/YYYY : ");
    scanf("%d/%d/%d",&dia,&mes,&ano);
    if(!getDate(dia,mes,ano)){
         printf("Data invália!Introduza uma nova data - DD/MM/YYYY : ");
        scanf("%d/%d/%d",&dia,&mes,&ano);
    }
    tarefa->dataCriacao=getDate(dia,mes,ano);
    strncpy(tarefa->descricao,des,NOME_BUFFER);

    if(list->tamanho == 0) {
        list->primeiro = tarefa;
    }
    else {
        list->ultimo->next = tarefa;
    }
    list->tamanho++;
    list->ultimo = tarefa;
}