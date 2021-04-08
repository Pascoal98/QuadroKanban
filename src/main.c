#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tarefa.h"
#include "file.h"
#include "print.h"

int main() {
    
    List* ToDo = createList();
    List* Doing = createList();
    //List* Done = createList();



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
            printList(ToDo);
            //taskToDone(Doing,Done);
            break;
        case 'e':
        case 'E':
            printNames(Doing);
            //taskToToDo(Done,ToDo);
            break;
        case 'f':
        case 'F':
            //viewBoard(ToDo,Doing,Done);
            break;
        case 'g':
        case 'G':
            //personTasks(Doing,Done);
            break;
        case 'h':
        case 'H':
            //viewTasksCrono();
            break;
        case 'i':
        case 'I':
            //loadFiles(ToDo,Doing,Done);
            break;
        case 'j':
        case 'J':
            printf("Saindo do programa...\n");
            loopMenu = 0;
            break;
        }
    }

    return 0;
}
