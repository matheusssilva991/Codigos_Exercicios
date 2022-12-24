#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	float x;
	float y;
}Tponto;

int main(void)
{
	Tponto ponto;

	do{
		printf("Digite a coordenada de X:\n");
		scanf("%f", &ponto.x);
		setbuf(stdin, NULL);

		printf("Digite a coordenada de Y:\n");
		scanf("%f", &ponto.y);
		setbuf(stdin, NULL);

		if(ponto.x > 0)
			if(ponto.y > 0)
				printf("Quadrante 1\n");
			else
				if(ponto.y == 0)
					printf("Ponto sobre os eixos\n");
				else
					printf("Quadrante 4\n");
		else
			if(ponto.x == 0)
				printf("Ponto sobre os eixos\n");
			else
				if(ponto.y > 0)
					printf("Quadrante 2\n");
				else
					printf("Quadrante 3\n");

		printf("\n\n");

	}while(ponto.x != 0 && ponto.y != 0);

	return 0;
}
