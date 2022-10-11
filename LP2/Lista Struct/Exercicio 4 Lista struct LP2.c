#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float x;
	float y;	
}Tponto;

int main()
{
	Tponto ponto[3];
	int i;
	
	for(i = 0; i < 3; i++)
	{
		printf("Digite o X%d:\n", i);
		scanf("%f", &ponto[i].x);
		setbuf(stdin, NULL);
		
		printf("Digite o Y%d:\n", i);
		scanf("%f", &ponto[i].y);
		setbuf(stdin, NULL);
		
		system("cls");
	}
	
	if(ponto[0].x == ponto[1].x || ponto[0].x == ponto[2].x || ponto[1].x == ponto[2].x)
		if(ponto[0].y == ponto[1].y || ponto[0].y == ponto[2].y || ponto[1].y == ponto[2].y)
			printf("Formam um Triangulo Retangulo\n");
		else
			printf("Nao Formam um Triangulo Retangulo\n");	
    return 0;
}

