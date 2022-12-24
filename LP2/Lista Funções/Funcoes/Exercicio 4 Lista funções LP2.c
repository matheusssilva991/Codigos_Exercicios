#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float compHipotenusa(float, float);

int main(int argc, char *argv[])
{
    float catetoA, catetoB, hipotenusa;

    printf("Digite o comprimento dos catetos: \n");
    scanf("%f %f", &catetoA, &catetoB);
    setbuf(stdin, NULL);

    hipotenusa = compHipotenusa(catetoA, catetoB);

    printf("Comprimento da Hipotenusa: %.2f\n", hipotenusa);

	return 0;
}

float compHipotenusa(float catA, float catB)
{
    float hipo, aux;

    hipo = sqrt(pow(catA, 2) + pow(catB, 2));

    return hipo;

}
