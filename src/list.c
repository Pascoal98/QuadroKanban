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

void printList(List* list) {
    for(Tarefa* curr = list->primeiro; curr != NULL ; curr = curr->next) {
        printf("Prioridade: %d\n",curr->prioridade);
        printf("Id: %d\n",curr->id);
        printf("Descrição: %s\n",curr->descricao);
    }
}

void printIds(List* list) {
    for(Tarefa* curr = list->primeiro; curr != NULL ; curr = curr->next) {
        printf("Id: %d\n",curr->id);
        printf("Descrição: %s\n",curr->descricao);
        printf("---------------------------------\n");
    }
}

void printNames(List* list) {
    for(Tarefa* curr = list->primeiro; curr != NULL ; curr = curr->next) {
        printf("Id: %d\n",curr->id);
        printf("Nome: %s\n",curr->pessoa);
        printf("---------------------------------\n");
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
        printIds(list1);
        scanf("%d",&idaux);
        Tarefa* aux = searchUntil(list1,idaux);
        if(aux == NULL) {
            printf("O id que selecionou não tem tarefa no ToDo.\n");
            exit(1);
        } else {
            setPessoaTarefa(aux);
            setLimitDate(aux);
            if(list2->tamanho == 0) {
                list2->primeiro = aux;
            }
            else {
                insertSortedName(list2,aux);
            }
            deleteFromListId(list1,aux->id);
            list1->tamanho--;
            list2->tamanho++;
        }   
    }
    printf("Tarefa foi movida da lista ToDo para Doing.\n");
}

void taskToDone(List* list1, List* list2) {
    int idaux;
    printf("Qual é o id da tarefa que pertence mover?\n");
    printIds(list1);
    scanf("%d",&idaux);
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
        } else {
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
    printNames(list);
    scanf("%d",&idaux);
    change(list,idaux);
}

void change(List* list, int id) {

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