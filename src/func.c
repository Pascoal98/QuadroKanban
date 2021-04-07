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

void orderByPriority(Fase* head) {
    
    Fase* prev = head;
    Fase* curr = head->next;

    while(curr != NULL) {
        if(curr->tarefa->prioridade == prev->tarefa->prioridade){
            if(curr->tarefa->dataCriacao < prev->tarefa->dataCriacao) {
                prev->next = curr->next;
                curr->next = head;
                curr = prev;
            } else {
            prev = curr;
            }
        } else 
            if(curr->tarefa->prioridade < prev->tarefa->prioridade) {
                prev->next = curr->next;
                curr->next = head;
                curr = prev;
            } else {
                prev = curr;
            }
        curr = curr->next;
    }
}

void orderByName(Fase* head) {
    
    Fase* prev = head;
    Fase* curr = head->next;

    while(curr != NULL) {
        if(strcmp(curr->tarefa->pessoa,prev->tarefa->pessoa) < 0) {
            prev->next = curr->next;
            curr->next = head;
            curr = prev;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
}

void orderByDate(Fase* head) {
    
    Fase* prev = head;
    Fase* curr = head->next;

    while(curr != NULL) {
        if(curr->tarefa->dataConclusao < prev->tarefa->dataConclusao) {
            prev->next = curr->next;
            curr->next = head;
            curr = prev;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
}