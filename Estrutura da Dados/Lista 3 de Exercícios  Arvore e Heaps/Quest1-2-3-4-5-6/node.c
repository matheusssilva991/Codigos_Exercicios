#include "node.h"

Node * makeTree(int info)
{
    Node *node;

    node = (Node *) malloc(sizeof(Node));

    if(node == NULL)
    {
        printf("Node nao alocado.\n");
        return NULL;
    }

    node->father = NULL;
    node->left = NULL;
    node->right = NULL;
    node->info = info;

    return node;
}

void setRight(Node *ptrNode, int info)
{
    if(ptrNode == NULL)
        return;

    ptrNode->right = makeTree(info);
    ptrNode->right->father = ptrNode;
}

void setLeft(Node *ptrNode, int info)
{
    if(ptrNode == NULL)
        return;

    ptrNode->left = makeTree(info);
    ptrNode->left->father = ptrNode;
}

void setFather(Node *ptrFather, Node *ptrNode)
{
    ptrNode->father = ptrFather;
}

int info(Node *ptrNode)
{
    return ptrNode->info;
}

Node *left(Node *ptrNode)
{
    return ptrNode->left;
}

Node *right(Node *ptrNode)
{
    return ptrNode->right;
}

Node *father(Node *ptrNode)
{
    return ptrNode->father;
}

int isLeft(Node *ptrNode)
{
    Node *p = father(ptrNode);

    if(p == NULL)
        return 0;

    if(left(p) == ptrNode)
        return 1;

    return 0;
}

int isRight(Node *ptrNode)
{
    Node *p = father(ptrNode);

    if(p == NULL)
        return 0;

    if(right(p) == ptrNode)
        return 1;

    return 0;
}

Node * brother(Node *ptrNode)
{
    Node *p = father(ptrNode);

    if(isRight(ptrNode))
        return left(p);
    else
        return right(p);
}

int leafCount(Node *ptrNode)
{
    if(ptrNode == NULL)
        return 0;

    if(right(ptrNode) == NULL && left(ptrNode) == NULL)
        return 1;

    else
        return  leafCount(left(ptrNode)) +  leafCount(right(ptrNode));
}

int nodeCount(Node *ptrNode)
{
    if(ptrNode == NULL)
        return 0;

    if(right(ptrNode) == NULL && left(ptrNode) == NULL)
        return 0;

    else
        return 1 + nodeCount(left(ptrNode)) + nodeCount(right(ptrNode));
}

void addno(Node *ptrNode, int info)
{
    if(ptrNode == NULL)
    {
        ptrNode = makeTree(info);
        return;
    }

    if (info > ptrNode->info)
    {
        if(ptrNode->right == NULL)
        {
            ptrNode->right = makeTree(info);
            return;
        }
           
        addno(ptrNode->right, info);
    }
    else
    {
        if(ptrNode->left == NULL)
        {
            ptrNode->left = makeTree(info);
            return;
        }
        addno(ptrNode->left, info);
    }
}

int getDepth(Node *ptrNode)
{
    if(ptrNode == NULL)
        return -1;
    else
        return getDepth(left(ptrNode)) >  getDepth(right(ptrNode)) ? 1 + getDepth(left(ptrNode)): 1 +  getDepth(right(ptrNode));
}

int isBinarySearchTree(Node *ptrNode)
{
    if(ptrNode == NULL)
        return 0;

    if(right(ptrNode) == NULL && left(ptrNode) == NULL) // verifica se é uma folha
        return 1;

    if(left(ptrNode) == NULL) // verifica se o filho esquerdo existe
    {
        if (ptrNode->info > right(ptrNode)->info) // verifica se o filho direito é menor que o pai
            return 0;

        return isBinarySearchTree(right(ptrNode));
    }

    else if(right(ptrNode) == NULL)
    {
        if(ptrNode->info < left(ptrNode)->info)
            return 0;

        return isBinarySearchTree(left(ptrNode));
    } 

    else if(ptrNode->info < left(ptrNode)->info || ptrNode->info > right(ptrNode)->info)
        return 0;
    else
        return isBinarySearchTree(left(ptrNode)) && isBinarySearchTree(right(ptrNode));
}

void inOrder(Node *ptrNode)
{
    if(ptrNode == NULL)
        return;
    
    inOrder(left(ptrNode));
    printf("%d ", ptrNode->info);
    inOrder(right(ptrNode));
}

void preOrder(Node *ptrNode)
{
    if(ptrNode == NULL)
        return;

    printf("%d ", ptrNode->info);
    preOrder(left(ptrNode));
    preOrder(right(ptrNode));
}

void postOrder(Node *ptrNode)
{
    if(ptrNode == NULL)
        return;

    postOrder(left(ptrNode));
    postOrder(right(ptrNode));
    printf("%d ", ptrNode->info);
}

int isHeap(Node *ptrNode)
{
    if(ptrNode == NULL)
        return 0;

    if(right(ptrNode) == NULL && left(ptrNode) == NULL) // verifica se é uma folha
        return 0;

    if(isMinHeap(ptrNode))
        return -1;
    else if(isMaxHeap(ptrNode))
        return 1;
    else   
        return 0;
}

int isMinHeap(Node *ptrNode)
{
    if(ptrNode == NULL)
        return 0;

    if(right(ptrNode) == NULL && left(ptrNode) == NULL) 
        return 1;

    if(left(ptrNode) == NULL) 
    {
        if (ptrNode->info > right(ptrNode)->info)
            return 0;

        return isMinHeap(right(ptrNode));
    }

    else if(right(ptrNode) == NULL)
    {
        if(ptrNode->info > left(ptrNode)->info)
            return 0;

        return isMinHeap(left(ptrNode));
    } 

    else if(ptrNode->info > right(ptrNode)->info || ptrNode->info > left(ptrNode)->info)
        return 0;

    else
        return isMinHeap(left(ptrNode)) && isMinHeap(right(ptrNode));
}

int isMaxHeap(Node *ptrNode)
{
    if(ptrNode == NULL)
        return 0;

    if(right(ptrNode) == NULL && left(ptrNode) == NULL) // verifica se é uma folha
        return 1;

    if(left(ptrNode) == NULL) 
    {
        if (ptrNode->info < right(ptrNode)->info)
            return 0;

        return isMaxHeap(right(ptrNode));
    }

    else if(right(ptrNode) == NULL)
    {
        if(ptrNode->info < left(ptrNode)->info)
            return 0;

        return isMaxHeap(left(ptrNode));
    } 

    else if(ptrNode->info < right(ptrNode)->info || ptrNode->info < left(ptrNode)->info)
        return 0;

    else
        return isMaxHeap(left(ptrNode)) && isMaxHeap(right(ptrNode));
}