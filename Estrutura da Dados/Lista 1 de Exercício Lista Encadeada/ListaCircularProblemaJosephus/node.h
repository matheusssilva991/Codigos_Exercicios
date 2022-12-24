#if !defined(NODE_H)
#define NODE_H

#include <malloc.h>

typedef struct node
{
    char *nome;
    struct node *next;
}NODE;

NODE * createNode();
void freeNode(NODE *ptrNode);

#endif // NODE_H