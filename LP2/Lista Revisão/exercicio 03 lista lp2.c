/*
    Exercício de Revisão
    Printar dobro, triplo, metade e triplo da metade de um número
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero;

    printf("Digite o numero: \n");
    scanf("%f", &numero);

    printf("Dobro = %.1f\nTriplo = %.1f\nMetade = %.1f\nTriplo da metade = %1.f\n", 
    numero * 2, numero * 3, numero / 2, (numero / 2) * 3 );

    return 0;
}
