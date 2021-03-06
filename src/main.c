#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "list.h"
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
    printf("a)Criar Tarefa;\n");
    printf("b)Passar tarefa para a fase 'Doing';\n");
    printf("c)Alterar pessoa responsável numa tarefa;\n");
    printf("d)Concluir tarefa;\n");
    printf("e)Reabrir tarefa;\n");
    printf("f)Visualizar o Quadra de Kanban;\n");
    printf("g)Visualizar todas as tarefas de uma pessoa;\n");
    printf("h)Visualizar todas as tarefas ordenadas por data de criação;\n");
    printf("i)Carregar os ficheiros;\n");
    printf("j)Guardar progresso.\n");
    printf("k)Guardar e Sair.\n");
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
        scanf("%c[^\n]",&opcao);

        switch (opcao) {
        case 'a':
        case 'A':
            system("clear");
            novaTarefa(ToDo);
            break;
        case 'b':
        case 'B':
            system("clear");
            taskToDoing(ToDo,Doing);
            break;
        case 'c':
        case 'C':
            system("clear");           
            changeName(Doing);
            break;
        case 'd':
        case 'D':
            system("clear");
            taskToDone(Doing,Done);
            break;
        case 'e':
        case 'E':
            system("clear");
            
            taskToToDo(Done,ToDo);
            break;
        case 'f':
        case 'F':
            system("clear");
            viewBoard(ToDo,Doing,Done);
            break;
        case 'g':
        case 'G':
            system("clear");   
            personTasks(Doing,Done);
            break;
        case 'h':
        case 'H':
            system("clear");
            viewTasksCrono(ToDo,Doing,Done);
            break;
        case 'i':
        case 'I':
            system("clear");
            loadFiles(ToDo,Doing,Done);
            break;

        case 'j':
        case 'J':
            system("clear");
            saveLists(ToDo,Doing,Done);
            break;
        case 'k':
        case 'K':
            system("clear");
            printf("Guardando listas...\n");
            saveLists(ToDo,Doing,Done);
            printf("Saindo do programa...\n");
            loopMenu = 0;
            break;
        }
    }

    return 0;
}
