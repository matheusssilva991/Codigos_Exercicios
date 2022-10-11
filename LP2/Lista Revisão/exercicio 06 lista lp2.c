/*
    Exercício Revisão
    Recebe a quantidade de mochilas, isqueiros e chinelos e printa o preço total de cada
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float mochilas, isqueiros, chinelos;

    printf("Digite o total de mochilas vendidas\n");
    scanf("%f", &mochilas);

    printf("Digite o total de isqueiros vendidos\n");
    scanf("%f", &isqueiros);

    printf("Digite o total de chinelos vendidos\n");
    scanf("%f", &chinelos);

    mochilas *= 25.00;
    isqueiros *= 2.00;
    chinelos *= 7.00;

    printf("total de mochilas vendidas e %.2f\n", mochilas);
    printf("total de isqueiros vendidos e %.2f\n", isqueiros);
    printf("total de chinelos vendidos e %.2f\n", chinelos);

    return 0;
}
