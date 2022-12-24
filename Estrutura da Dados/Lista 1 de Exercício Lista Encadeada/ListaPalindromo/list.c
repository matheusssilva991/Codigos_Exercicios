#include "list.h"

void initialize(LIST *ptrLista)
{
    ptrLista->first = NULL;
    ptrLista->sizeList = 0;
}

int isEmpty(LIST *ptrLista)
{
    return ptrLista->first == NULL ? 1 : 0;
}

NODE *findLast(LIST *ptrLista)
{
    NODE* nodeAux;
	if(isEmpty(ptrLista)){
        printf("\n\nERRO: LISTA VAZIA\n\n");
        exit (-1);
    }
    
	nodeAux = ptrLista->first;
	
	while(nodeAux->next != NULL)
		nodeAux = nodeAux->next;
	
	return nodeAux;
}

int onthelist(LIST* ptrList, NODE* ptrNode)
{
    LIST listaAux;

    listaAux.first = ptrList->first; 

    if(listaAux.first->letra == ptrNode->letra) // Verifica se é o node procurado
        return 1;

    if(listaAux.first == NULL) // Condição de parada, verifica se o próximo node é igual a NULL
        return 0;
    
    listaAux.first = ptrList->first->next; // faz aux.first apontar para o próximo node da lista

    onthelist(&listaAux, ptrNode); // faz chamada recursiva da função
       
} // fim da função onthelist

void insertFirst(LIST *ptrLista, char auxLetra)
{
    NODE *nodeAux;

    nodeAux = createNode();

    nodeAux->next = ptrLista->first; // nodeAux->next aponta para o (antigo)primeiro elemento da lista
    nodeAux->letra = auxLetra; //seta nodeAux

    if(!isEmpty(ptrLista)) // verifica se a lista não ta vazia, se ela tiver vazia, nodeAux->next seria NULL e causaria erro no code.
        nodeAux->next->previous = nodeAux; // faz o ponteiro previous do (antigo) primeiro apontar para o (novo)primeiro

    ptrLista->first = nodeAux; // faz a lista apontar para o (novo)primeiro
    ptrLista->sizeList++;  
}

char deleteFirst(LIST* ptrLista){
    NODE* nodeAux;
    char auxLetra;

    if(isEmpty(ptrLista)){
        printf("\n\nERRO: LISTA VAZIA!!\n\n");
        return 0;
    }

    nodeAux = ptrLista->first; // faz nodeAux apontar para o primeiro elemento da lista

    ptrLista->first = nodeAux->next; // faz a lista apontar para o segundo elemento.
    ptrLista->first->previous = NULL; // coloca o ponteiro previous do primeiro elemento da lista apontar para NULL

    auxLetra = nodeAux->letra; // guarda a letra do nó que vai ser excluido
    freeNode(nodeAux); // libera o nó

    return auxLetra;
}

void insertAfter(LIST* ptrLista, NODE* currentNode, char letraAux)
{
    NODE *newNode;

    if(currentNode == NULL || !onthelist(ptrLista, currentNode))
    {
        printf("Erro, lista vazia.\n");
        exit(-1);
    }

    // criação do novo nó
    newNode = createNode();
    newNode->letra = letraAux;
    // fim da criação do nó
 
    newNode->next = currentNode->next; // o novo nó vai apontar para o proximo nó

    if(currentNode->next != NULL)
        currentNode->next->previous = newNode;
    
    currentNode->next = newNode; // nó atual aponta para o novo nó
    newNode->previous = currentNode;  // o ponteiro para o nó anterior vai apontar para o atual

    ptrLista->sizeList++;
}

char deleteAfter(LIST *ptrList, NODE *currentNode)
{
    if(currentNode == NULL || currentNode->next == NULL || !onthelist(ptrList, currentNode))
    {
        printf("Erro, impossivel deletar.\n");
        exit(-1);
    }

    NODE *nodeAux;
    char letraAux;

    nodeAux = currentNode->next;
    letraAux = nodeAux->letra;

    currentNode->next = nodeAux->next;
    currentNode->next->previous = currentNode;

    free(nodeAux);

    ptrList->sizeList--;

    return letraAux;
} // fim da função deleteAfter

void insertLast(LIST* ptrLista, char letraAux)
{
    NODE *newNode;
    NODE *last;

    last = findLast(ptrLista);

    newNode = createNode();
    newNode->letra = letraAux;

    last->next = newNode;
    newNode->previous = last;

    ptrLista->sizeList++;  
}

char deleteLast(LIST* ptrLista){
    NODE* last;
    NODE* temp;
    char letraAux;
    
    if(isEmpty(ptrLista))
    {
        printf("lista vazia, erro.\n");
        exit(-1);
    }

    last = findLast(ptrLista); 
	temp = ptrLista->first;
	
	if(temp == last)
		ptrLista->first = NULL;
	else
		while(temp->next != last)
			temp = temp->next;
    
    letraAux = last->letra;
    
    temp->next = NULL;
    
    freeNode(last);
	
	ptrLista->sizeList--;
	
    return letraAux;
}

int ehPalindromoIterativa(LIST *ptrLista)
{
    NODE *ptrFirstNode;
    NODE *ptrLastNode;

    if(isEmpty(ptrLista) || ptrLista->sizeList == 1)
        return 0;

    ptrFirstNode = ptrLista->first;
    ptrLastNode = findLast(ptrLista);

    for(int i = 0; i < ptrLista->sizeList / 2; i++)
    {
        if(ptrFirstNode->letra != ptrLastNode->letra)
            return 0;

        ptrFirstNode = ptrFirstNode->next;
        ptrLastNode = ptrLastNode->previous;
    }
    
    return 1;
}

int ehPalindromoRecursiva(LIST *ptrLista, NODE *ptrFirstNode, NODE *ptrLastNode)
{  
    if(isEmpty(ptrLista) || ptrLista->sizeList == 1)
        return 0;

    else if(ptrFirstNode == NULL && ptrLastNode == NULL)
        return 1;

    else if(ptrFirstNode->letra != ptrLastNode->letra)
        return 0;

    ptrFirstNode = ptrFirstNode->next;
    ptrLastNode = ptrLastNode->previous;

    return ehPalindromoRecursiva(ptrLista, ptrFirstNode, ptrLastNode);
}

