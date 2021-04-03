#include <stdio.h>
#include <stdlib.h>

#include "fase.h"

Fase criarLista() {

    Fase temp = (Fase)malloc(sizeof(Fase_node));

    if(temp != NULL) {
        temp->faseId = 0;
        temp->next = NULL;
    }
    return temp;
}