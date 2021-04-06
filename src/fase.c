#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fase.h"

Fase criarLista() {

    Fase temp = (Fase)malloc(sizeof(Phase));

    if(temp != NULL) {
        temp->faseId = 0;
        temp->next = NULL;
    }
    return temp;
}

void orderByPriority(Fase head) {
    
    Fase prev = head;
    Fase curr = head->next;

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

void orderByName(Fase head) {
    
    Fase prev = head;
    Fase curr = head->next;

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

void orderByDate(Fase head) {
    
    Fase prev = head;
    Fase curr = head->next;

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