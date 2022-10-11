#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "pilha.h"

int main(){

    PILHA pilha;
    char *expressao = "{[(5 × 7)/5] × 4 - [(5 × 7) × 2]} /(3 × 6)";

    initialize(&pilha);

    colocaExpressao(&pilha, expressao);
    verificaExpressao(&pilha);
    limpaExpressao(&pilha);

	return 0;
}