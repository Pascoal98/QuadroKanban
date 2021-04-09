#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list;

int manageId();
void loadFiles(struct list* ToDo, struct list* Doing, struct list* Done);
void saveLists(struct list* ToDo, struct list* Doing, struct list* Done);

#endif