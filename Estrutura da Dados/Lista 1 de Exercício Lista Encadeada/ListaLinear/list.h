#if !defined(LIST_H)
#define LIST_H

#include "node.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct list_c{
    int qt;
    NODE* first;
}LIST;

void initialize(LIST*);
int isEmpty(LIST*);
void insertFirst(LIST*, int);
int deleteFirst(LIST*);
void insertAfter(LIST*, NODE*, int);
int deleteAfter(LIST*, NODE*);
NODE* findLast(LIST*);
void insertLast(LIST*, int);
int deleteLast(LIST*);
int onthelistRecursiva(LIST*, NODE*);
int onthelistIterativa(LIST*, NODE*);

#endif // LIST_H
