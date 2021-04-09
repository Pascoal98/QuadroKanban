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
        printToDo(list1);
        printf("###############TO DO###############\n");
    }
    if(list2->tamanho > 0 ){
        printDoing(list2);
        printf("###############DOING###############\n");
    }
    if(list3->tamanho > 0 ){
        printDone(list3);
        printf("###############DONE###############\n");
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

void personTasks(List* list1, List* list2) {
    printf("Qual é o nome da pessoa que deseja procurar?\n");
    char pessoa[NOME_BUFFER];
    getchar();
    fgets(pessoa,sizeof(pessoa),stdin);
    pessoa[strlen(pessoa)-1] = '\0';
    int flag1 = 0, flag2 = 0;
    for(Tarefa* curr = list1->primeiro; curr != NULL ; curr = curr->next) {
        if(strcmp(pessoa,curr->pessoa) == 0) {
            printf("Id: %d\n",curr->id);
            printf("Descrição: %s\n",curr->descricao);
            flag1 = 1;
        }
    }
    if(flag1 == 1) {
        printf("###############DOING###############\n");
    }
    for(Tarefa* curr = list2->primeiro; curr != NULL ; curr = curr->next) {
        if(strcmp(pessoa,curr->pessoa) == 0) {
            printf("Id: %d\n",curr->id);
            printf("Descrição: %s\n",curr->descricao);
            flag2 = 1;
        }
    }
    if(flag2 == 1) {
        printf("###############DONE###############\n");
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
    setPriority(tarefa);
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
        scanf("%d[^\n]",&idaux);
        Tarefa* aux = searchUntil(list1,idaux);
        printf("%d\n",aux->id);
        if(aux == NULL) {
            printf("O id que selecionou não tem tarefa no ToDo.\n");
        } else {
            setPessoaTarefa(aux);
            setLimitDate(aux);
            if(list2->tamanho == 0) {
                list2->primeiro = aux;
                deleteFromListId(list1,aux->id);
                aux->next = NULL;
            } else {
                deleteFromListId(list1,aux->id);
                insertSortedName(list2,aux);
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
    scanf("%d[^\n]",&idaux);
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
            aux->next = NULL;
        } else {
            deleteFromListId(list1,aux->id);
            insertSortedDate(list2,aux);
        }
        list1->tamanho--;
        list2->tamanho++;
        printf("Tarefa de id %d foi movida da lista Doing para Done.\n",aux->id);
    }
}

void taskToToDo(List* list1, List* list2) {
    int idaux;
    printf("Qual é o id da tarefa que pertence mover?\n");
    printDoing(list1);
    scanf("%d[^\n]",&idaux);
    Tarefa* aux = searchUntil(list1,idaux);
    printf("%d\n",aux->id);
    if(aux == NULL) {
        printf("O id da tarefa que pretende reabrir não se encontra na lista Done.\n");
    } else {
        if(list2->tamanho == 0) {
            list2->primeiro = aux;
            aux->next = NULL;
            deleteFromListId(list1,aux->id);
            aux->next = NULL;
        } else {
            deleteFromListId(list1,aux->id);
            insertSortedPriority(list2,aux);
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
                }else 
                    if(tarefa->dataCriacao == curr->dataCriacao) {
                        if(tarefa->id < curr->id) {
                            if(last == NULL) {
                                tarefa->next = list->primeiro;
                                list->primeiro = tarefa;
                                return;
                            } else {
                                tarefa->next = last->next;
                                last->next = tarefa;
                                return;
                            }
                        } else {
                            if(curr->next == NULL){
                                tarefa->next = NULL;
                                curr->next = tarefa;
                                return;
                            }
                            last = curr;
                            curr = curr->next;
                        }
                    } else {
                        if(curr->next == NULL){
                            tarefa->next = NULL;
                            curr->next = tarefa;
                            return;
                        }
                        last = curr;
                        curr = curr->next;
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
    curr = curr->next;
    prev = list->primeiro;
    while(curr != NULL) {
        if(curr->id == id) {
            prev->next = curr->next;
            return;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void changeName(List* list) {
    int idaux;
    printf("Qual é o id do nome da pessoa que pertence mudar?\n");
    printDoing(list);
    scanf("%d[^\n]",&idaux);
    changePerson(list,idaux);
}

void changePerson(List* list, int id) {

    Tarefa* curr = list->primeiro;

    if(curr == NULL) {
        return;
    }
    if(curr->id == id) {
        setPessoaTarefa(curr);
        return;
    }
    curr = curr->next;
    while(curr != NULL) {
        if(curr->id == id) {
            setPessoaTarefa(curr);
            return;
        } else {
            curr = curr->next;
        }
    }
}

int compareDates(const void *a, const void *b) {
    Tarefa *t1 = (Tarefa *)a;
    Tarefa *t2 = (Tarefa *)b;

    if(t1->dataCriacao > t2->dataCriacao) return +1;
    if(t1->dataCriacao < t2->dataCriacao) return -1;
    if(t1->dataCriacao == t2->dataCriacao) {
        if(t1->id > t2->id) return +1;
        if(t1->id < t2->id) return -1;
    }
    return 0;
}

void viewTasksCrono(List* list1, List* list2, List* list3) {

    int size = list1->tamanho + list2->tamanho + list3->tamanho;

    if(size == 0) {
        printf("Não existe tarefas nas listas!\n");
        return;
    }
    Tarefa array[size];

    Tarefa* curr = list1->primeiro;

    if(list1->tamanho > 0) {
        for(int i = 0; i < list1->tamanho; i++){
            if(curr != NULL) {
                array[i].id = curr->id;
                array[i].dataCriacao = curr->dataCriacao;
                curr = curr->next;
            }
        }
    }

    curr = list2->primeiro;
    if(list2->tamanho > 0) {
        for(int i = list1->tamanho; i < list2->tamanho+list1->tamanho; i++){
            if(curr != NULL) {
                array[i].id = curr->id;
                array[i].dataCriacao = curr->dataCriacao;
                curr = curr->next;
            }
        }
    }
    curr = list3->primeiro;
    if(list3->tamanho > 0) {
        for(int i = list1->tamanho + list2->tamanho; i < size; i++){
            if(curr != NULL) {
                array[i].id = curr->id;
                array[i].dataCriacao = curr->dataCriacao;
                curr = curr->next;
            }
        }
    }

    qsort(array,size,sizeof(Tarefa),compareDates);

    for(int j = 0; j < size; j++) {
        printf("id: %d\n", array[j].id);
        printf("Data de Criação: %d\n",array[j].dataCriacao);
    }
}
