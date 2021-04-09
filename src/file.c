#include "file.h"

int manageId() {
    FILE *fp = fopen("id.txt","r");
    int id;
    if(fp == NULL) {
        fp = fopen("id.txt","w");
        fprintf(fp,"%d",1);
        id = 1;
        fclose(fp);
        return id;
    } else {
        fscanf(fp,"%d",&id);
        fclose(fp);
        ++id;
        fp = fopen("id.txt","w");
        fprintf(fp,"%d",id);
        fclose(fp);
        return id;
    }
}

void saveLists(struct list* ToDo, struct list* Doing, struct list* Done) {
    FILE *fp;
    if(ToDo->tamanho > 0) {
        fp = fopen("ToDo.txt","w");
        fprintf(fp,"%d\n",ToDo->tamanho);
        for(Tarefa* curr = ToDo->primeiro; curr != NULL ; curr = curr->next) {
            fprintf(fp,"%d\n",curr->prioridade);
            fprintf(fp,"%d\n",curr->id);
            fprintf(fp,"%s",curr->descricao);
            fprintf(fp,"%d\n",curr->dataCriacao);
            fprintf(fp,"%p\n",curr->next);
        }
    }
    if(Doing->tamanho > 0) {
        fp = fopen("Doing.txt","w");
        fprintf(fp,"%d\n",Doing->tamanho);
        for(Tarefa* curr = Doing->primeiro; curr != NULL ; curr = curr->next) {
            fprintf(fp,"%d\n",curr->id);
            fprintf(fp,"%s\n",curr->pessoa);
            fprintf(fp,"%s",curr->descricao);
            fprintf(fp,"%d\n",curr->dataCriacao);
            fprintf(fp,"%d\n",curr->dataLimite);
            fprintf(fp,"%p\n",curr->next);
        }
    }
    if(Done->tamanho > 0) {
        fp = fopen("Done.txt","w");
        fprintf(fp,"%d\n",Done->tamanho);
        for(Tarefa* curr = Done->primeiro; curr != NULL ; curr = curr->next) {
            fprintf(fp,"%d\n",curr->id);
            fprintf(fp,"%s\n",curr->pessoa);
            fprintf(fp,"%s",curr->descricao);
            fprintf(fp,"%d\n",curr->dataCriacao);
            fprintf(fp,"%d\n",curr->dataLimite);
            fprintf(fp,"%d\n",curr->dataConclusao);
            fprintf(fp,"%p\n",curr->next);
        }
    }
}