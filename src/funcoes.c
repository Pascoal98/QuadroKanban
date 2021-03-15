#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoes.h"

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