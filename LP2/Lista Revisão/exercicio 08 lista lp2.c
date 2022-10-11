/*
    Exercício revisão
    Recebe o tempo em segundos e retorna no formato, horas, minutos e segundos
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tempo, segundos, horas, minutos, aux;

    printf("Digite o tempo em segundos\n");
    scanf("%d", &tempo);

    horas = tempo / 3600;
    aux = tempo % 3600;
    minutos = aux / 60;
    segundos =  aux % 60;

    printf("%d : %d : %d \n", horas, minutos, segundos);

    return 0;
}
