#include "tarefa.h"

unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

int getDate(int dia, int mes, int ano){
    int aux= concatenate(ano,mes);
    int data = concatenate(aux,dia);
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

void readDescTarefa(Tarefa* tarefa) {
    char des[NOME_BUFFER];
    printf("Faça uma breve descrição da tarefa: ");
    getchar();
    fgets(des,sizeof(des),stdin);
    des[strlen(des)-1] = '\0';
    strncpy(tarefa->descricao,des,NOME_BUFFER);
}

void setPessoaTarefa(Tarefa* tarefa) {
    printf("Quem é a pessoa responsável por esta tarefa?\n");
    char pessoa[NOME_BUFFER];
    getchar();
    fgets(pessoa,sizeof(pessoa),stdin);
    pessoa[strlen(pessoa)-1] = '\0';
    strncpy(tarefa->pessoa,pessoa,NOME_BUFFER);
}

void setStartDate(Tarefa* tarefa) {
    int dia,mes,ano;
    printf("Introduza a data de inicio da tarefa - DD/MM/YYYY : ");
    scanf("%d/%d/%d",&dia,&mes,&ano);
            
    if(!getDate(dia,mes,ano)){
        printf("Data invália!Introduza uma nova data - DD/MM/YYYY : ");
        scanf("%d/%d/%d",&dia,&mes,&ano);
    }
    tarefa->dataCriacao=getDate(dia,mes,ano);
}

void setFinishDate(Tarefa* tarefa) {
    int dia,mes,ano;
    printf("Introduza a data em que concluiu a tarefa - DD/MM/YYYY : ");
    scanf("%d/%d/%d",&dia,&mes,&ano);
            
    if(!getDate(dia,mes,ano)){
        printf("Data invália!Introduza uma nova data - DD/MM/YYYY : ");
        scanf("%d/%d/%d",&dia,&mes,&ano);
    }
    tarefa->dataConclusao=getDate(dia,mes,ano);
}

void setLimitDate(Tarefa* tarefa) {
    int dia,mes,ano;
    printf("Introduza a data limite de conclusão - DD/MM/YYYY : ");
    scanf("%d/%d/%d",&dia,&mes,&ano);
            
    if(!getDate(dia,mes,ano)){
        printf("Data invália!Introduza uma nova data - DD/MM/YYYY : ");
        scanf("%d/%d/%d",&dia,&mes,&ano);
    }
    tarefa->dataLimite=getDate(dia,mes,ano);
}