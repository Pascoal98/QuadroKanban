#include <stdio.h>
#include <stdlib.h>

#include "fase.h"
#include "tarefa.h"
#include "file.h"

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
    
    criarLista("ToDo");
    criarLista("Doing");
    criarLista("Done");

    int loopMenu = 1;
    while(loopMenu) {
        printBanner();
        printOptions();
        manageId();
        manageId();
        manageId();
        loopMenu = 0;
    }

    return 0;
}
