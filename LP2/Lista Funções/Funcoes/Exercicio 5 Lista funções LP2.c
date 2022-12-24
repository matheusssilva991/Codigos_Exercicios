#include <stdio.h>
#include <stdlib.h>

float potenciaInt(float , int);

int main(int argc, char *argv[])
{
    float base;
    int expoente;

    printf("Digite a base e o expoente: \n");
    scanf("%f %d", &base, &expoente);
    setbuf(stdin, NULL);

    printf("%.1f elevado a %d = %.1f", base, expoente, potenciaInt(base, expoente));

	return 0;
}

float potenciaInt(float base, int expoente)
{
    int i;
    float aux = base;

    if(expoente == 0)
        return 1;

    if(expoente > 0)
        for(i = 1; i < expoente; i++)
            aux *= base;

    if(expoente < 0)
    {
        expoente *= -1;

        for(i = 1; i < expoente; i++)
            aux *= base;

        return 1 / aux;
    }

    return aux;
}
