#include <stdio.h>
#include <stdlib.h>

float potenciaRec(float , int );
float potenciaNeg(float , int );

int main()
{
    float (*p[2])(float , int ) = {potenciaRec, potenciaNeg};
	float base = 5;
	int expoente = 2;

    if(expoente < 0)
        printf("%.1f elevado a %d : = %.2f", base, expoente, 1 / p[1](base, expoente));
    else
        printf("%.1f elevado a %d : = %.2f", base, expoente, p[0](base, expoente));

	return 0;
}

float potenciaRec(float n, int exp)
{
    if(exp == 0)
        return 1;

    else
        return n * potenciaRec(n, exp - 1);
}

float potenciaNeg(float n, int exp)
{
    if(exp < 0)
        exp *= - 1;

    if(exp == 0)
        return 1;
    else
        return n * potenciaRec(n, exp - 1);
}
