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

void printToDo(List* list) {
    for(Tarefa* curr = list->primeiro; curr != NULL ; curr = curr->next) {
        printf("%d\n",curr->prioridade);
    }
    printf("\n\n\n\n\n\n\n");
}


void novaTarefa(List* list) {

    char des[NOME_BUFFER];
    printf("Faça uma breve descrição da tarefa: \n");
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
        insertSorted(list,tarefa);
    }
    list->tamanho++;
}

void insertSorted(List* list, Tarefa* tarefa) {
    
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

void taskToDoing(List* list1, List* list2) {
    
}