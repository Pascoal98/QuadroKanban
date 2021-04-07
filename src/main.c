#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"


void printBanner() {
    printf("   *******                           **                 **   **                    **  \n");
    printf("  **/////**                         /**                /**  **                    /**                      \n");
    printf(" **     //**  **   **  ******       /** ******  ****** /** **    ******   ******* /**       ******   *******\n"); 
    printf("/**      /** /**  /** //////**   ******//**//* **////**/****    //////** //**///**/******  //////** //**///**\n"); 
    printf("/**    **/** /**  /**  *******  **///** /** / /**   /**/**/**    *******  /**  /**/**///**  *******  /**  /**\n"); 
    printf("//**  // **  /**  /** **////** /**  /** /**   /**   /**/**//**  **////**  /**  /**/**  /** **////**  /**  /**\n");
    printf(" //******* **//******//********//******/***   //****** /** //**//******** ***  /**/****** //******** ***  /**\n");
    printf("  /////// //  //////  ////////  ////// ///     //////  //   //  //////// ///   // /////    //////// ///   //\n");
    }

void printOptions() {
    printf("\nOpçôes: \n");
    printf("1)Criar Tarefa;\n");
    printf("2)Passar tarefa para a fase 'Doing';\n");
    printf("3)Alterar pessoa responsável numa tarefa;\n");
    printf("4)Concluir tarefa;\n");
    printf("5)Reabrir tarefa;\n");
    printf("6)Visualizar o Quadra de Kanban;\n");
    printf("7)Visualizar todas as tarefas de uma pessoa;\n");
    printf("8)Visualizar todas as tarefas ordenadas por data de criação;\n");
    printf("9)Sair.\n");
}


int main() {
    
    List* ToDo = createList();
    List* Doing = createList();
    List* Done = createList();



    int loopMenu = 1;
    char opcao;
    while(loopMenu) {

        printBanner();
        printOptions();
        scanf("%c",&opcao);

        switch (opcao) {
        case 'a':
            novaTarefa(ToDo);
            break;
        case 'b':
            printf("Saindo do programa...\n");
            loopMenu = 0;
            break;
        }
    }

    return 0;
}
