#include "list.h"

/*
definições da biblioteca list.c
*/
void initialize(LIST* ptrLista){
    ptrLista->qt = 0;
    ptrLista->first = NULL;
}

int isEmpty(LIST* ptrLista){
    return (ptrLista->first == NULL) ? 1 : 0;
}

void insertFirst(LIST* ptrLista, int value){
    NODE* nodeAux;

    nodeAux = createNode();

    //não está genérico
    nodeAux->info = value;

    nodeAux->next = ptrLista->first;

    ptrLista->first = nodeAux;

    ptrLista->qt++;
}

int deleteFirst(LIST* ptrLista){
    NODE* nodeAux;
    int value;

    if(isEmpty(ptrLista)){
        printf("\n\nERRO: LISTA VAZIA!!\n\n");
        return 0;
    }

    nodeAux = ptrLista->first;

    ptrLista->first = nodeAux->next;

    value = nodeAux->info;
    freeNode(nodeAux);

    return value;
}

int onthelistIterativa(LIST* ptrLista, NODE* ptrNode)
{
    NODE *nodeAux;

    nodeAux = ptrLista->first;

    while(nodeAux->next != NULL)
    {
        if(nodeAux->info == ptrNode->info)
            return 1;

        nodeAux = nodeAux->next;
    }
    return 0;
} 

int onthelistRecursiva(LIST* ptrLista, NODE* ptrNode)
{
    LIST listAux;

    listAux.first = ptrLista->first; 

    if(listAux.first->info == ptrNode->info) // Verifica se é o node procurado
        return 1;

    if(listAux.first->next == NULL) // Condição de parada, verifica se o próximo node é igual a NULL
        return 0;
    else
    {
        listAux.first = ptrLista->first->next; // faz aux.first apontar para o próximo node da lista

        onthelistRecursiva(&listAux, ptrNode); // faz chamada recursiva da função
    }   
}

void insertAfter(LIST* ptrLista, NODE* ptrNode, int value)
{
    if(ptrNode == NULL || !onthelistRecursiva(ptrLista,ptrNode))
    {
        printf("parametro *NODE* invalido!");
        exit(-1);
    }
    NODE* q;
    q = createNode(); 
    q->info = value;
    
    q->next = ptrNode->next; 
    ptrNode->next = q;  

    ptrLista->qt++;
}

int deleteAfter(LIST* ptrLista, NODE* ptrNode){
    NODE* nodeAux;
    int aux;
    if((ptrNode==NULL)||(ptrNode->next==NULL) || !onthelistRecursiva(ptrLista,ptrNode)){
        printf("Erro: impossivel remover");
        exit(1);
    }
    nodeAux = ptrNode->next;
    aux = nodeAux->info;
    ptrNode->next = nodeAux->next;

    ptrLista->qt--;
    freeNode(nodeAux);

    return aux;
}

NODE* findLast(LIST* ptrLista){
	NODE* auxNode;

	if(isEmpty(ptrLista)){
        printf("\n\nERRO: LISTA VAZIA\n\n");
        exit (-1);
    }
	auxNode = ptrLista->first;
	
	while(auxNode->next != NULL)
		auxNode = auxNode->next;
	
	return auxNode;
}

void insertLast(LIST* ptrLista, int value){
    NODE* newNode;
    NODE* last;
    
    last = findLast(ptrLista);
    
	newNode = createNode();
    newNode->info = value;
    
    last->next = newNode;
    ptrLista->qt++;
}

int deleteLast(LIST* ptrLista){
    NODE* last;
    NODE* temp;
    int info;
    
    last = findLast(ptrLista);
    
	temp = ptrLista->first;
	
	if(temp == last)
		ptrLista->first = NULL;
	else
		while(temp->next != last)
			temp = temp->next;
    
    info = last->info;
    
    temp->next = NULL;
    
    freeNode(last);
	
	ptrLista->qt--;
	
    return info;
}