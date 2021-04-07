#include "print.h"

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
    printf("a)Criar Tarefa;\n");
    printf("b)Passar tarefa para a fase 'Doing';\n");
    printf("c)Alterar pessoa responsável numa tarefa;\n");
    printf("d)Concluir tarefa;\n");
    printf("e)Reabrir tarefa;\n");
    printf("f)Visualizar o Quadra de Kanban;\n");
    printf("g)Visualizar todas as tarefas de uma pessoa;\n");
    printf("h)Visualizar todas as tarefas ordenadas por data de criação;\n");
    printf("i)Carregar os ficheiros;\n");
    printf("j)Sair.\n");
}
