#include <stdlib.h>
#include <stdio.h>

// Estruturas 
typedef struct element{
    int info;
    struct element* next;
}ELEMENT;

typedef struct fila{
    int size;
    ELEMENT* first;
}FILA;
//Fim Estruturas

//Protótipos
ELEMENT* createElement();
void freeElement(ELEMENT*);

void initialize(FILA*);
int isEmpty(FILA*);
int deQueue(FILA*);
void toQueue(FILA*, int);
ELEMENT* findLast(FILA* ptrLista);
void printLista(FILA *);

int operacao(int, int);
int jogoEsperto(int , int );
// Fim Protótipos

//Main
int main(int argc, char const *argv[])
{
    unsigned int N, M;

    scanf("%u %u", &N, &M);

    printf("%d\n", jogoEsperto(N, M));
    
    return 0;
}

//Funções
ELEMENT* createElement(){
    ELEMENT* p;

    p = (ELEMENT*) malloc(sizeof(ELEMENT));
    p->next = NULL;

    return p;
}

void freeElement(ELEMENT* p){
    free(p);
}

void initialize(FILA* ptrLista){
    ptrLista->size = 0;
    ptrLista->first = NULL;
}

int isEmpty(FILA* ptrLista){
    return (ptrLista->first == NULL) ? 1 : 0;
}

ELEMENT* findLast(FILA* ptrLista){
	ELEMENT* auxElement;

	if(isEmpty(ptrLista))
        return NULL;

	auxElement = ptrLista->first;
	
	while(auxElement->next != NULL)
		auxElement = auxElement->next;
	
	return auxElement;
}


int deQueue(FILA* ptrLista)
{
    int info;
    ELEMENT *elementRemove;

    if(isEmpty(ptrLista))
        return -1;

    elementRemove = ptrLista->first;
    info = elementRemove->info;

    ptrLista->first = elementRemove->next;    

	ptrLista->size--;

    freeElement(elementRemove);
	
    return info;
}

void toQueue(FILA* ptrLista, int newInfo)
{
    ELEMENT* newElement;
    ELEMENT* lastElement;
    
    lastElement = findLast(ptrLista);
    
	newElement = createElement();
    newElement->info = newInfo;
    
    if(lastElement == NULL)
    {
        lastElement = newElement;
        ptrLista->first = lastElement;
    }      
    else
        lastElement->next = newElement;

    ptrLista->size++;
}

void printLista(FILA *ptrLista)
{
    ELEMENT *aux;

    aux = ptrLista->first;

    while(aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->next;
    }

    printf("\n");
}

int operacao(int op, int N)
{
    switch(op)
    {
        case 0:
            return N * 2;
        case 1:
            return N * 3;
        case 2:
            return N / 2;
        case 3:
            return N / 3;
        case 4:
            return N + 7;
        case 5:
            return N - 7;
    }
}

int jogoEsperto(int N, int M)
{
    FILA *valoresN;
    int quantidadeOperacoes = 0;
    ELEMENT *aux;
    int tamanhoFila;
    int guardaValor;

    if(N == M)
        return 0;

    valoresN = (FILA *) malloc(sizeof(FILA));

    initialize(valoresN);

    toQueue(valoresN, N);

    while(1)
    {
        aux = valoresN->first;
	    tamanhoFila = valoresN->size;

        for(int i = 0; i < tamanhoFila; ++i)
        {
            for(int j = 0; j < 6; ++j)
		    {
			    guardaValor = operacao(j, aux->info);

                if(guardaValor == N || guardaValor < 0)
                    continue;

			    if(guardaValor == M)
			    {
				    ++quantidadeOperacoes;
				    return quantidadeOperacoes;
			    }

			    toQueue(valoresN, guardaValor);	
		    }

		    deQueue(valoresN);  
            aux = valoresN->first;
        }
        ++quantidadeOperacoes;
    }

    return quantidadeOperacoes;
}