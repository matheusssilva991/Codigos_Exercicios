#include "node.h"
#include <stdio.h>
#include <stdlib.h>

/*
definições da biblioteca node.c
*/
NODE* createNode(){
    NODE* p;

    p = (NODE*) malloc(sizeof(NODE));
    p->next = NULL;
    p->previous = NULL;

    return p;
}

void freeNode(NODE* p){
    free(p);
}

//---- fim das definições de node.c