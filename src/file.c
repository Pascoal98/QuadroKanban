#include "file.h"

int manageId() {
    FILE *fp = fopen("id.txt","r");
    int id;
    if(fp == NULL) {
        fp = fopen("id.txt","w");
        fprintf(fp,"%d",1);
        id = 1;
        fclose(fp);
        return id;
    } else {
        fscanf(fp,"%d",&id);
        fclose(fp);
        ++id;
        fp = fopen("id.txt","w");
        fprintf(fp,"%d",id);
        fclose(fp);
        return id;
    }
}