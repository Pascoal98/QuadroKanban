#include <stdio.h>
#include <stdlib.h>

#include "task.h"

int main() {

    TAREFA *head = NULL;
    //printScreen();
    newTaskID(&head,0);
    newTaskID(&head,0);
    newTaskID(&head,0);
    printList(head);
}