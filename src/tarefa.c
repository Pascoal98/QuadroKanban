
#include <stdio.h>
#include <stdlib.h>

#include "tarefa.h"
#include "file.h"

#define maxAno 2999
#define minAno 2000

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



Tarefa* novaTarefa(){
    Tarefa *a = (Tarefa*)malloc(sizeof(Tarefa));

    a->id= manageId();
   
    printf("Introduza a prioridade: ");
    scanf("%d", &a->prioridade);
    int dia,mes,ano;
    printf("Introduza a data - DD/MM/YYYY : ");
    scanf("%d/%d/%d",&dia,&mes,&ano);
    if(!getDate(dia,mes,ano)){
         printf("Data invália!Introduza uma nova data - DD/MM/YYYY : ");
        scanf("%d/%d/%d",&dia,&mes,&ano);
    }
    a->dataCriacao=getDate(dia,mes,ano);
    char *des = malloc(256*sizeof(char));
    getchar();
    printf("Descrição :");
    fgets(des, 256, stdin);
    a->descricao= des;

    return a; 
}
