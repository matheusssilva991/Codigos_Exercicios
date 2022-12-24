#include <stdlib.h>
#include <stdio.h>

int **alocaMatriz(int **matriz, int linhaMatriz, int colunaMatriz);
void **printaMatriz(int **matriz, int linhaMatriz, int colunaMatriz);
void **liberaMatriz(int **matriz, int linhaMatriz);
void **preencheMatriz(int **matriz, int linhaMatriz, int colunaMatriz);

int main(void)
{
	int linhaMatrizA, colunaMatrizA, linhaMatrizB, colunaMatrizB; // Dimensões das matrizes
	int **ptrMatrizA, **ptrMatrizB, **ptrMatrizC; // Ponteiros para alocar as matrizes
	int i, j, k, aux;

	printf("Digite as dimensoes da primeira matriz =  \n");
	scanf("%d %d", &linhaMatrizA, &colunaMatrizA);
	setbuf(stdin, NULL);

	printf("\n\n");

	printf("Digite as dimensoes da segunda matriz = \n");
	scanf("%d %d", &linhaMatrizB, &colunaMatrizB);
	setbuf(stdin, NULL);

	printf("\n\n");

	if(colunaMatrizA != linhaMatrizB) // testar se as dimensoes sao passiveis para multiplicar
		exit(-1);

	// Chama a função alocaMatriz e Aloca as 3 Matrizes
	ptrMatrizA = alocaMatriz(ptrMatrizA, linhaMatrizA, colunaMatrizA);
	ptrMatrizB = alocaMatriz(ptrMatrizB, linhaMatrizB, colunaMatrizB);
	ptrMatrizC = alocaMatriz(ptrMatrizC, linhaMatrizA, colunaMatrizB);

	//chama a função preencheMatriz para Preencher as matrizes
	preencheMatriz(ptrMatrizA, linhaMatrizA, colunaMatrizA);
	preencheMatriz(ptrMatrizB, linhaMatrizB, colunaMatrizB);

	printf("Matriz A\n");
	printaMatriz(ptrMatrizA, linhaMatrizA, colunaMatrizA);
	printf("Matriz B\n");
	printaMatriz(ptrMatrizB, linhaMatrizB, colunaMatrizB);

    for(k = 0; k < linhaMatrizA; k++) // faz a multiplicacao dos matrizes
        for(i = 0; i < colunaMatrizB; i++)
            for(j = 0; j < linhaMatrizB; j++)
            {
                ptrMatrizC[k][i] += ptrMatrizA[k][j] * ptrMatrizB[j][i];
            }

	printf("Matriz Resultante\n\n");

	printaMatriz(ptrMatrizC, linhaMatrizA, colunaMatrizB);

	liberaMatriz(ptrMatrizA, linhaMatrizA);
	liberaMatriz(ptrMatrizB, linhaMatrizB);
	liberaMatriz(ptrMatrizC, linhaMatrizA); 

	return 0;
}

int **alocaMatriz(int **matriz, int linhaMatriz, int colunaMatriz)
{
	matriz = (int **) malloc(linhaMatriz * sizeof(int *)); // aloca as linhas da matriz

	if(matriz == NULL) //verifica se foi alocado corretamente
		exit(-1);

	for(int i = 0; i < linhaMatriz; i++)
	{
		matriz[i] = (int *) calloc(colunaMatriz, sizeof(int)); // Aloca as colunas da matriz

		if(matriz[i] == NULL) //verifica se foi alocado corretamente
			exit(-1);
	}

	return matriz;
}

void **printaMatriz(int **matriz, int linhaMatriz, int colunaMatriz)
{
	for(int i = 0; i < linhaMatriz; i++)
    {
		for(int j = 0; j < colunaMatriz; j++)
           printf("[%d]", matriz[i][j]);
        printf("\n");
    }
	printf("\n\n");
}

void **liberaMatriz(int **matriz, int linhaMatriz)
{
    int i;

    for(i = 0; i < linhaMatriz; i++)
        free(matriz[i]);

    free(matriz);
}

void **preencheMatriz(int **matriz, int linhaMatriz, int colunaMatriz)
{
	int aux;

	for(int i = 0; i < linhaMatriz; i++) // pega valores para a primeira matriz
		for(int j = 0; j < colunaMatriz; j++)
		{
			printf("Digite o termo [%d][%d] da Matriz = \n", i + 1, j + 1);
			scanf("%d", &aux);

			matriz[i][j] = aux;

			setbuf(stdin, NULL);
			system("cls");
		}
}