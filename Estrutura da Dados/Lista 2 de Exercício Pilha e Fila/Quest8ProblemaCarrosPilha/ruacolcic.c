#include "ruacolcic.h"

void initializeRuaColcic(RUACOLCIC* chefe){
    chefe->quantidade = 0;
    chefe->first = NULL;
}

int isEmptyRuaColcic(RUACOLCIC* chefe){
    return (chefe->first == NULL) ? 1 : 0;
}

LINHAENTRADA* findLast(RUACOLCIC* chefe){
	LINHAENTRADA* auxLinha;

	if(isEmptyRuaColcic(chefe))
        return NULL;

	auxLinha = chefe->first;
	
	while(auxLinha->next != NULL)
		auxLinha = auxLinha->next;
	
	return auxLinha;
}


int deQueue(RUACOLCIC* chefe)
{
    int placaCarro;
    char escolha;
    LINHAENTRADA *linhaRemove;

    if(isEmptyRuaColcic(chefe))
        return -1;

    linhaRemove = chefe->first;
    escolha = linhaRemove->escolha;
    placaCarro = linhaRemove->placaCarro;

    chefe->first = linhaRemove->next;    

	chefe->quantidade--;

    freeLinha(linhaRemove);
	
    return placaCarro;
}

void toQueue(RUACOLCIC* chefe, char entrada,  int placaCarro)
{
    LINHAENTRADA* newLinha;
    LINHAENTRADA* lastLinha;
    
    lastLinha = findLast(chefe);
    
	newLinha = createEntrada();
    newLinha->placaCarro = placaCarro;
    newLinha->escolha = entrada;
    
    if(lastLinha == NULL)  
        chefe->first = newLinha;      
    else
        lastLinha->next = newLinha;

    chefe->quantidade++;
}

void printEntradas(RUACOLCIC *chefe)
{
    LINHAENTRADA *linha;

    linha = chefe->first;

    while(linha != NULL)
    {
        printf("Carro %d  vai %c\n", linha->placaCarro, linha->escolha);
        linha = linha->next;
    }

    printf("\n");
}