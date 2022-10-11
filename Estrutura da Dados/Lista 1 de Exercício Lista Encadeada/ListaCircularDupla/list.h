#if !defined(LIST_H)
#define LIST_H

#include "node.h"
#include <stdio.h>

typedef struct list
{
    int sizeList;
    NODE *first;
}LIST;

int initialize(LIST *);
int isEmpty(LIST*);
void insertFirst(LIST*, int);
int deleteFirst(LIST*);
int onthelist(LIST*, NODE*);
void insertAfter(LIST* l, NODE*, int);
int deleteAfter(LIST*, NODE*);
NODE* findLast(LIST*);
void insertLast(LIST*, int);
int deleteLast(LIST*);

#endif // LIST_H
