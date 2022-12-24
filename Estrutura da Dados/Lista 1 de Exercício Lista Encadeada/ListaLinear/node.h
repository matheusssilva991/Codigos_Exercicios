#if !defined(NODE_H)
#define NODE_H

typedef struct node{
    int info;
    struct node* next;
}NODE;

NODE* createNode();
void freeNode(NODE*);

#endif // NODE_H

//---- fim da biblioteca node.h
