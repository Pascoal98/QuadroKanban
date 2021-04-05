#include <stdio.h>
#include <stdlib.h>

#include "fase.h"

void printBanner() {
    printf("   *******                           **                 **   **                    **  \n");
    printf("  **/////**                         /**                /**  **                    /**                      \n");
    printf(" **     //**  **   **  ******       /** ******  ****** /** **    ******   ******* /**       ******   *******\n"); 
    printf("/**      /** /**  /** //////**   ******//**//* **////**/****    //////** //**///**/******  //////** //**///**\n"); 
    printf("/**    **/** /**  /**  *******  **///** /** / /**   /**/**/**    *******  /**  /**/**///**  *******  /**  /**\n"); 
    printf("//**  // **  /**  /** **////** /**  /** /**   /**   /**/**//**  **////**  /**  /**/**  /** **////**  /**  /**\n");
    printf(" //******* **//******//********//******/***   //****** /** //**//******** ***  /**/****** //******** ***  /**\n");
    printf("  /////// //  //////  ////////  ////// ///     //////  //   //  //////// ///   // /////    //////// ///   //\n");

    printf("\n");
    printf("1)Inserir tarefa.\n");
    printf("2)Sair.\n");

    
    }


int manageId() {
    FILE *f = fopen("id.txt","r");
    int id;
    if(f == NULL) {
        f = fopen("id.txt","w");
        fprintf(f,"%d",1);
        id = 1;
        fclose(f);
        return id;
    } else {
        fscanf(f,"%d",&id);
        return id;
    }
}

int main() {
    Tarefa **nova= NULL;
    printBanner();
   
    int op;
    scanf("%d", &op);

    switch (op){
    case 1:
     novaTarefa(nova);
        break;
    default:
        printf("Bye!\n");
        break;
    }

    Fase ToDo = criarLista();
    Fase Doing = criarLista();
    Fase Done = criarLista();

    ToDo->nomeTarefa = "ToDo";
    Doing->nomeTarefa = "Doing";
    Done->nomeTarefa = "Done";

    return 0;
}
