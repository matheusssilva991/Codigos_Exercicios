#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int centrox, centroy;
	int raio;
}Tesfera;

typedef struct
{
	float x;
	float y;
	Tesfera esfera;

}Tponto;

int main()
{
	Tponto ponto;
	float esq;

	printf("Digite o valor de X\n");
	scanf("%f", &ponto.x);
	setbuf(stdin, NULL);

	printf("Digite o valor de Y\n");
	scanf("%f", &ponto.y);
	setbuf(stdin, NULL);

	printf("Digite o valor de X do centro\n");
	scanf("%f", &ponto.esfera.centrox);
	setbuf(stdin, NULL);

	printf("Digite o valor de Y do centro\n");
	scanf("%f", &ponto.esfera.centroy);
	setbuf(stdin, NULL);

	printf("Digite o valor do raio\n");
	scanf("%f", &ponto.esfera.raio);
	setbuf(stdin, NULL);

	esq = (ponto.x - ponto.esfera.centrox) * (ponto.x - ponto.esfera.centrox) + (ponto.y - ponto.esfera.centroy) * 
	(ponto.y - ponto.esfera.centroy);

	if(esq < (ponto.esfera.raio * ponto.esfera.raio))
		printf("Ponto e interno a circuferencia\n");
	else
		printf("Ponto externo a  circuferencia\n");

    return 0;
}

