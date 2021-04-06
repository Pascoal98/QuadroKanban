#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fase.h"

Fase* criarLista(char nome[]) {

    Fase* temp = malloc(sizeof(Fase));

    if(temp == NULL) {
        printf("Erro a alocar espaço para a Lista.\n");
        exit(1);
    }
    strncpy(temp->nomeTarefa,nome,NOME_BUFFER);
    temp->next = NULL;

    return temp;
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