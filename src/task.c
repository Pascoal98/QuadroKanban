#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"

int idCounter = 0; // contador ID global

//struct TAREFA *current = NULL;

void printList(TAREFA *head_ref) {
    TAREFA *temp = head_ref;

    while(temp != NULL) {
        printf("id = %d \nfase = %d \nprioridade = %d \n",temp->id , temp->fase, temp->prioridade);
        temp = temp->next;
    }
}

TAREFA *newTaskID(TAREFA **head_ref,int fase) {

    TAREFA *a = (TAREFA*)malloc(sizeof(TAREFA));
    if(a == NULL)
        fprintf(stderr, "Can't allocate memory for the task\n");
    
    int prioridade;
    scanf("%d",&prioridade);

    a->fase = fase;
    a->id = idCounter;
    idCounter++;
    a->prioridade = prioridade;
    a->next = NULL;
    //printf("%d %d %d\n",a->fase,a->id,a->prioridade);

    if(*head_ref == NULL) {
        *head_ref = a;
    } else {
        TAREFA *lastTask = *head_ref;

        while(lastTask->next != NULL) 
            lastTask = lastTask->next;
        lastTask->next = a;
    }

    return a;
}


/*
int orderByDate(const void *a, const void *b) {
    Tarefa *data1 = (Tarefa *)a;
    Tarefa *data2 = (Tarefa *)b;

    if(data1->dataConclusao > data2->dataConclusao) return +1;
    if(data1->dataConclusao == data2->dataConclusao) {
        if(data1->prioridade > data2->prioridade) return -1;
        else return +1;
    }
    return -1;
}

int orderByName(const void *a, const void *b) {
    Tarefa *name1 = (Tarefa *)a;
    Tarefa *name2 = (Tarefa *)b;

    if(strcmp(name1->pessoa,name2->pessoa) > 0) return -1;
    if(strcmp(name1->pessoa,name2->pessoa) == 0) {
        if(name1->prioridade > name2->prioridade) return -1;
        else return +1;
    }
    return +1;
}

int orderByPriority(const void *a, const void *b) {
    Tarefa *priority1 = (Tarefa *)a;
    Tarefa *priority2 = (Tarefa *)b;

    if(priority1->prioridade > priority2->prioridade) return -1;
    if(priority1->prioridade == priority2->prioridade) {
        if(priority1->id > priority2->id) return -1;
        else return +1;
    }
    return +1;
}
*/
void printScreen() {
    printf("#  #   ####     #     #    ####     ####    #     #\n");
    printf("# #    #  #     ##    #    #   #    #  #    ##    #\n");
    printf("##     #  #     # #   #    #  #     #  #    # #   #\n");
    printf("#      ####     #  #  #    ###      ####    #  #  #\n");
    printf("##     #  #     #   # #    #  #     #  #    #   # #\n");
    printf("# #    #  #     #    ##    #   #    #  #    #    ##\n");
    printf("#  #   #  #     #     #    ####     #  #    #     #\n");
    printf("\n");
    printf("1)Ver Quadro.\n");
    printf("2)Inserir Dados.\n");
    printf("3)Quit.\n");
}