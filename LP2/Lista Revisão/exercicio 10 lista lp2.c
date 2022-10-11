/*
    Exercício de Revisão
    Recebe um valor e retorna a quantidades de notas de 50, 20, 10 e 1
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor, notas50, notas20, notas10, notas1, aux;

    printf("Digite o valor: ");
    scanf("%d", &valor);

    notas50 = valor / 50;
    aux = valor % 50;
    notas20 = aux / 20;
    aux = aux % 20;
    notas10 = aux / 10;
    notas1 = aux % 10;

    printf("Notas50 = %d\n", notas50);
    printf("Notas20 = %d\n", notas20);
    printf("Notas10 = %d\n", notas10);
    printf("Notas1 = %d\n", notas1);

    return 0;
}
