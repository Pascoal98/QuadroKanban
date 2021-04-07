#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "tarefa.h"
#define NOME_BUFFER 256


void novaTarefa(List* list);
void addTarefa(List* list, char des[]);
#endif