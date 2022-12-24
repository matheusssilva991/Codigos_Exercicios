/*
    Exercício de revisão
    Calcular diâmetro, circuferência e área dado o raio
*/

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main()
{
    float raio, diametro, area, circuferencia;

    scanf("%f", &raio);

    diametro = raio * 2;
    circuferencia = diametro * PI;
    area = pow(raio, 2) * PI;

    printf("Diametro: %.1f\nCircuferencia: %.1f\nArea: %.1f\n", diametro, circuferencia, area);

    return 0;
}
