#if !defined(NODE_H)
#define NODE_H

#include <malloc.h>

typedef struct node
{
    int dado;
    struct node *next;
    struct node *previous;
}NODE;

NODE * createNode();
void freeNode(NODE *ptrNode);

#endif // NODE_H
