#include "file.h"


/*cria ficheiro id.txt se nao existir, a unica funçao é ir buscar o id para a tarefa, iterando sempre que for acrescentando*/
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

/*Dá load aos files, se o file nao existir cria um em branco*/

void loadFiles(struct list* ToDo, struct list* Doing, struct list* Done) {
    FILE *data;

    data = fopen("ToDo.txt","r");
    if(data == NULL) {
        data = fopen("ToDo.txt","w");
        fclose(data);
    }else {
        int nToDo;
        fscanf(data,"%d[^\n]",&nToDo);
        for(int i = 0; i < nToDo; i++) {
            int prio,id,dataCriacao;
            char des[NOME_BUFFER];
            fscanf(data,"%d[^\n]",&prio);
            fscanf(data,"%d[^\n]",&id);
            fscanf(data,"%s[^\n]",des);
            fscanf(data,"%d[^\n]",&dataCriacao);
            addToDo(ToDo,prio,id,des,dataCriacao);
        }
        fclose(data);
    }
    data = fopen("Doing.txt","r");
    if(data == NULL) {
        data = fopen("Doing.txt","w");
        fclose(data);
    }else{
        int nDoing;
        fscanf(data,"%d[^\n]",&nDoing);
        for(int i = 0; i < nDoing; i++) {
            int prio,id,dataCriacao,dataLimite;
            char des[NOME_BUFFER];
            char pessoa[NOME_BUFFER];
            fscanf(data,"%d[^\n]",&prio);
            fscanf(data,"%d[^\n]",&id);
            fscanf(data,"%s[^\n]",des);
            fscanf(data,"%d[^\n]",&dataCriacao);
            fscanf(data,"%s[^\n]",pessoa);
            fscanf(data,"%d[^\n]",&dataLimite);
            addDoing(Doing,prio,id,des,dataCriacao,pessoa,dataLimite);
        }
        fclose(data);
    }
    data = fopen("Done.txt","r");
    if(data == NULL) {
        data = fopen("Done.txt","w");
        fclose(data);
    }else {
        int nDone;
        fscanf(data,"%d[^\n]",&nDone);
        for(int i = 0; i < nDone; i++) {
            int prio,id,dataCriacao,dataLimite,dataConclusao;
            char des[NOME_BUFFER];
            char pessoa[NOME_BUFFER];
            fscanf(data,"%d[^\n]",&prio);
            fscanf(data,"%d[^\n]",&id);
            fscanf(data,"%s[^\n]",des);
            fscanf(data,"%d[^\n]",&dataCriacao);
            fscanf(data,"%s[^\n]",pessoa);
            fscanf(data,"%d[^\n]",&dataLimite);
            fscanf(data,"%d[^\n]",&dataConclusao);
            addDone(Done,prio,id,des,dataCriacao,pessoa,dataLimite,dataConclusao);
        }
        fclose(data);
    }
}

/*Guarda as listas num ficheiro txt, só cria se existir elementos nas listas*/

void saveLists(struct list* ToDo, struct list* Doing, struct list* Done) {
    FILE *fp;
    if(ToDo->tamanho > 0) {
        fp = fopen("ToDo.txt","w");
        fprintf(fp,"%d\n",ToDo->tamanho);
        for(Tarefa* curr = ToDo->primeiro; curr != NULL ; curr = curr->next) {
            fprintf(fp,"%d\n",curr->prioridade);
            fprintf(fp,"%d\n",curr->id);
            fprintf(fp,"%s\n",curr->descricao);
            fprintf(fp,"%d\n",curr->dataCriacao);
        }
        fclose(fp);
    }
    if(Doing->tamanho > 0) {
        fp = fopen("Doing.txt","w");
        fprintf(fp,"%d\n",Doing->tamanho);
        for(Tarefa* curr = Doing->primeiro; curr != NULL ; curr = curr->next) {
            fprintf(fp,"%d\n",curr->prioridade);
            fprintf(fp,"%d\n",curr->id);
            fprintf(fp,"%s\n",curr->descricao);
            fprintf(fp,"%d\n",curr->dataCriacao);
            fprintf(fp,"%s\n",curr->pessoa);
            fprintf(fp,"%d\n",curr->dataLimite);
        }
        fclose(fp);
    }
    if(Done->tamanho > 0) {
        fp = fopen("Done.txt","w");
        fprintf(fp,"%d\n",Done->tamanho);
        for(Tarefa* curr = Done->primeiro; curr != NULL ; curr = curr->next) {
            fprintf(fp,"%d\n",curr->prioridade);
            fprintf(fp,"%d\n",curr->id);
            fprintf(fp,"%s\n",curr->descricao);
            fprintf(fp,"%d\n",curr->dataCriacao);
            fprintf(fp,"%s\n",curr->pessoa);
            fprintf(fp,"%d\n",curr->dataLimite);
            fprintf(fp,"%d\n",curr->dataConclusao);
        }
        fclose(fp);
    }
}