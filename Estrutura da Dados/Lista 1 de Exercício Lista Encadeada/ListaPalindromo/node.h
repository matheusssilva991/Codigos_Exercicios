#if !defined(NODE_H)
#define NODE_H

typedef struct node{
    char letra;
    struct node *next;
    struct node *previous;
}NODE;

NODE* createNode();
void freeNode(NODE*);

#endif // NODE_H

//---- fim da biblioteca node.h