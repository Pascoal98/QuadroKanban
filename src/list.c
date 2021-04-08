#include "list.h"


List* createList() {

    List* temp = malloc(sizeof(List));
    if(temp == NULL) {
        printf("Erro a alocar espaço para a Lista.\n");
        exit(1);
    }
    temp->tamanho = 0;
    temp->primeiro = NULL;
    return temp;
}

void viewBoard(List* list1, List* list2, List* list3) {
    if(list1->tamanho > 0 ) {
        printf("###############TO DO###############\n");
        printToDo(list1);
        putchar('\n');
    }
    if(list2->tamanho > 0 ){
        printf("###############DOING###############\n");
        printDoing(list2);
        putchar('\n');
    }
    if(list2->tamanho > 0 ){
        printf("###############DONE###############\n");
        printDone(list3);
        putchar('\n');
    }
}

void printToDo(List* list) {
    for(Tarefa* curr = list->primeiro; curr != NULL ; curr = curr->next) {
        printf("Prioridade: %d\n",curr->prioridade);
        printf("Id: %d\n",curr->id);
        printf("Descrição: %s\n",curr->descricao);
        printf("Data de Inico: %d\n",curr->dataCriacao);
        putchar('\n');
    }
}

void printDoing(List* list) {
    for(Tarefa* curr = list->primeiro; curr != NULL ; curr = curr->next) {
        printf("Id: %d\n",curr->id);
        printf("Nome: %s\n",curr->pessoa);
        printf("Descrição: %s\n",curr->descricao);
        printf("Data Limite: %d\n",curr->dataLimite);
        putchar('\n');
    }
}

void printDone(List* list) {
    for(Tarefa* curr = list->primeiro; curr != NULL ; curr = curr->next) {
        printf("Id: %d\n",curr->id);
        printf("Nome: %s\n",curr->pessoa);
        printf("Descrição: %s\n",curr->descricao);
        printf("Data Conclusão: %d\n",curr->dataConclusao);
        putchar('\n');
    }
}

void novaTarefa(List* list) {
    Tarefa* tarefa = malloc(sizeof(Tarefa));

    if(tarefa == NULL) {
        printf("Erro a alocar espaço para a Tarefa.\n");
        exit(1);
    }

    tarefa->next = NULL;
    tarefa->id= manageId();
    printf("Introduza a prioridade: ");
    scanf("%d", &tarefa->prioridade);
    setStartDate(tarefa);
    readDescTarefa(tarefa);
    if(list->tamanho == 0) {
        list->primeiro = tarefa;
    }
    else {
        insertSortedPriority(list,tarefa);
    }
    list->tamanho++;
    system("clear");
}

void taskToDoing(List* list1, List* list2) {
    if(list2->tamanho == MAX_SIZE) {
        printf("A lista está cheia, por favor acabe uma tarefa antes de adicionar outra.\n");
    } else {
        int idaux;
        printf("Qual é o id da tarefa que pertence mover?\n");
        printToDo(list1);
        scanf("%d",&idaux);
        Tarefa* aux = searchUntil(list1,idaux);
        printf("%d\n",aux->id);
        if(aux == NULL) {
            printf("O id que selecionou não tem tarefa no ToDo.\n");
        } else {
            setPessoaTarefa(aux);
            setLimitDate(aux);
            if(list2->tamanho == 0) {
                list2->primeiro = aux;
                aux->next = NULL;
                deleteFromListId(list1,aux->id);
            } else {
                insertSortedName(list2,aux);
                deleteFromListId(list1,aux->id);
            }
            list1->tamanho--;
            list2->tamanho++;
            printf("Tarefa de id %d foi movida da lista ToDo para Doing.\n",aux->id);
        }   
    }
}


void taskToDone(List* list1, List* list2) {
    int idaux;
    printf("Qual é o id da tarefa que pertence mover?\n");
    printDoing(list1);
    scanf("%d",&idaux);
    Tarefa* aux = searchUntil(list1,idaux);
    printf("%d\n",aux->id);
    if(aux == NULL) {
        printf("O id que selecionou não tem tarefa no Doing.\n");
    } else {
        setFinishDate(aux);
        if(list2->tamanho == 0) {
            list2->primeiro = aux;
            aux->next = NULL;
            deleteFromListId(list1,aux->id);
        } else {
            insertSortedDate(list2,aux);
            deleteFromListId(list1,aux->id);
        }
        list1->tamanho--;
        list2->tamanho++;
        printf("Tarefa de id %d foi movida da lista Doing para Done.\n",aux->id);
    }
}

void insertSortedPriority(List* list, Tarefa* tarefa) {
    
    Tarefa* curr = list->primeiro;
    Tarefa* last = NULL;

    while(curr != NULL) {
        if(tarefa->prioridade > curr->prioridade){
            if(last == NULL){
                tarefa->next = list->primeiro;
                list->primeiro = tarefa;
                return;
            } else {
                tarefa->next = last->next;
                last->next = tarefa;
                return;
            }
        }else 
        if(tarefa->prioridade == curr->prioridade) {
            if(tarefa->dataCriacao < curr->dataCriacao) {
                if(last == NULL) {
                    tarefa->next = list->primeiro;
                    list->primeiro = tarefa;
                    return;
                } else {
                    tarefa->next = last->next;
                    last->next = tarefa;
                    return;
                }
            } 
        }else 
            if(curr->next == NULL){
                tarefa->next = NULL;
                curr->next = tarefa;
                return;
        }else {
            last = curr;
            curr = curr->next;
        }
    }
}

void insertSortedName(List* list, Tarefa* tarefa) {
    
    Tarefa* curr = list->primeiro;
    Tarefa* last = NULL;

    while(curr != NULL) {
        if(strcmp(tarefa->pessoa,curr->pessoa) < 0){
            if(last == NULL){
                tarefa->next = list->primeiro;
                list->primeiro = tarefa;
                return;
            } else {
                tarefa->next = last->next;
                last->next = tarefa;
                return;
            }
        }else 
        if(strcmp(tarefa->pessoa,curr->pessoa) == 0) {
            if(tarefa->dataCriacao < curr->dataCriacao) {
                if(last == NULL) {
                    tarefa->next = list->primeiro;
                    list->primeiro = tarefa;
                    return;
                } else {
                    tarefa->next = last->next;
                    last->next = tarefa;
                    return;
                }
            }
        }else 
            if(curr->next == NULL){
                tarefa->next = NULL;
                curr->next = tarefa;
                return;
        } else {
            last = curr;
            curr = curr->next;
        }
    }
}

void insertSortedDate(List* list, Tarefa* tarefa) {
    
    Tarefa* curr = list->primeiro;
    Tarefa* last = NULL;

    while(curr != NULL) {
        if(tarefa->dataConclusao < curr->dataConclusao){
            if(last == NULL){
                tarefa->next = list->primeiro;
                list->primeiro = tarefa;
                return;
            } else {
                tarefa->next = last->next;
                last->next = tarefa;
                return;
            }
        }else 
        if(tarefa->dataConclusao == curr->dataConclusao) {
            if(tarefa->dataCriacao < curr->dataCriacao) {
                if(last == NULL) {
                    tarefa->next = list->primeiro;
                    list->primeiro = tarefa;
                    return;
                } else {
                    tarefa->next = last->next;
                    last->next = tarefa;
                    return;
                }
            }
        }else 
            if(curr->next == NULL){
                tarefa->next = NULL;
                curr->next = tarefa;
                return;
        } else {
            last = curr;
            curr = curr->next;
        }
    }
}

Tarefa* searchUntil(List* list, int id) {
        
    Tarefa* curr = list->primeiro;
    
    while(curr != NULL) {
        if(curr->id == id) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void deleteFromListId(List* list, int id) {
        
    Tarefa* curr = list->primeiro;
    Tarefa* prev;

    if(curr == NULL) {
        return;
    }
    if(curr->id == id) {
        list->primeiro = curr->next;
        return;
    }
    prev = list->primeiro;
    while(curr != NULL) {
        if(curr->id == id) {
            prev->next = curr->next;
            return;
        } else {
            prev->next = curr;
            curr = curr->next;
        }
    }
}

void changeName(List* list) {
    int idaux;
    printf("Qual é o id do nome da pessoa que pertence mudar?\n");
    printDoing(list);
    scanf("%d",&idaux);
    changePerson(list,idaux);
}

void changePerson(List* list, int id) {

    Tarefa* curr = list->primeiro;
    Tarefa* prev;

    if(curr == NULL) {
        return;
    }
    if(curr->id == id) {
        setPessoaTarefa(curr);
        return;
    }
    prev = list->primeiro;
    while(curr != NULL) {
        if(curr->id == id) {
            setPessoaTarefa(curr);
            return;
        } else {
            prev->next = curr;
            curr = curr->next;
        }
    }
}