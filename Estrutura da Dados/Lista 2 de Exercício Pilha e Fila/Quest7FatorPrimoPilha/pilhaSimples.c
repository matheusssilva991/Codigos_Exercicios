#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "pilha.h"

/* A Escolha do TDA de pilhas foi porque os fatores primos seriam acessados da mesma extremidade em que foram colocados,
assim manteria a ordem de fatoração proposta do exercício
*/

int main(){

    int numero = 3960;

    printf("numero %d\n", numero);
    fatoresPrimos(numero);
    
	return 0;
}