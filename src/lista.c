#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

Lista criarLista() {

    Lista temp = (Lista)malloc(sizeof(List));

    if(temp != NULL) {
        temp->listId = 0;
        temp->next = NULL;
    }
    return temp;
}