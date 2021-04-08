#include "tarefa.h"

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

unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

int getDate(int dia, int mes, int ano){
    int aux= concatenate(dia,mes);
    int data =concatenate(aux,ano);
    if(ano>=minAno && ano<=maxAno){
        if(mes>=1 && mes<=12){
            if((dia>=1 && dia<=31) && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12))
               return data;
            else if((dia>=1 && dia<=30) && (mes==4 || mes==6 || mes==9 || mes==11))
                 return data;
            else if((dia>=1 && dia<=28) && (mes==2))
               return data;
            else if(dia==29 && mes==2 && (ano%400==0 ||(ano%4==0 && ano%100!=0)))
                return data;
            else
                return 0;
        }
        else{
          return 0;
        }
    }
    else{
        return 0;
    } 
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
    char des[NOME_BUFFER];
    printf("Faça uma breve descrição da tarefa: ");
    getchar();
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

    tarefa->next = NULL;
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
        insertSortedPriority(list,tarefa);
    }
    list->tamanho++;
    system("clear");
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
            printf("Quem é a pessoa responsável por esta tarefa?\n");
            char pessoa[NOME_BUFFER];
            getchar();
            fgets(pessoa,sizeof(pessoa),stdin);
            strncpy(aux->pessoa,pessoa,NOME_BUFFER);
            int dia,mes,ano;
            printf("Introduza a data limite de conclusão - DD/MM/YYYY : ");
            scanf("%d/%d/%d",&dia,&mes,&ano);
            
            if(!getDate(dia,mes,ano)){
                printf("Data invália!Introduza uma nova data - DD/MM/YYYY : ");
                scanf("%d/%d/%d",&dia,&mes,&ano);
            }
            aux->dataLimite=getDate(dia,mes,ano);
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
        printf("Para que pessoa deseja mudar?\n");
        char pessoa[NOME_BUFFER];
        getchar();
        fgets(pessoa,sizeof(pessoa),stdin);
        strncpy(curr->pessoa,pessoa,NOME_BUFFER);
        return;
    }
    prev = list->primeiro;
    while(curr != NULL) {
        if(curr->id == id) {
            printf("Para que pessoa deseja mudar?\n");
            char pessoa[NOME_BUFFER];
            getchar();
            fgets(pessoa,sizeof(pessoa),stdin);
            strncpy(curr->pessoa,pessoa,NOME_BUFFER);
            return;
        } else {
            prev->next = curr;
            curr = curr->next;
        }
    }
}