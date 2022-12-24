#include "node.h"

NODE *createNode()
{
    NODE *ptrNode;

    ptrNode = (NODE *) malloc(sizeof(NODE));
    ptrNode->next = NULL;

    return ptrNode;
} // Fim da função createNode

void freeNode(NODE *ptrNode)
{
    free(ptrNode);
} // Fim da função freeNode