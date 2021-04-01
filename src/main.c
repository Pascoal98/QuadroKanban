#include <stdio.h>
#include <stdlib.h>

#include "task.h"

int main() {

    TAREFA *head = NULL;
    //printScreen();
    newTask(&head,0);
    newTask(&head,0);
    newTask(&head,0);
    printList(head);
}