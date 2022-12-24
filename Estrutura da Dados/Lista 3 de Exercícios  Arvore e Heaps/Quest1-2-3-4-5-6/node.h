#if !defined(NODE_H)
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype{
	int info;
	struct nodetype *left;
	struct nodetype *right;
	struct nodetype *father;
}Node;

Node * makeTree(int ); // cria um novo nó
void setRight(Node *, int); // cria um novo nó Direito se ele for null
void setLeft(Node *, int); // cria um novo nó Esquerdo se ele for null
void setFather(Node *, Node *); // Registra o pai se ele não foi comprar cigarro
int info(Node *);
Node *left(Node *); // retorna o filho esquerdo
Node *right(Node *); // retorna o filho direito
Node *father(Node *); // retorna o pai
int isLeft(Node *); 
int isRight(Node *);
Node * brother(Node *); // retorna o irmão
int leafCount(Node *); // conta as folhas
int nodeCount(Node *); // conta os nós não folhas
void addno(Node *, int );
int getDepth(Node *);
int isBinarySearchTree(Node *);
void inOrder(Node *);
void preOrder(Node *);
void postOrder(Node *);
int isHeap(Node *);
int isMinHeap(Node *);
int isMaxHeap(Node *);

#endif // NO
