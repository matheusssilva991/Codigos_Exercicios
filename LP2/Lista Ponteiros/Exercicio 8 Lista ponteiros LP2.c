#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
	int *ptr, n, *ptrb, i;

	printf("Digite o tamanho do vetor\n");
	scanf("%d", &n);

	ptr = (int *) malloc(n * sizeof(int));
	ptrb = (int *) calloc(n, sizeof(int));

	srand(time(NULL));

	printf("\n");

	for(i = 0; i < n; i++)
	{
		ptr[i] = 0 + rand() % n;
		ptrb[ptr[i]]++;

		printf("%d, ", ptr[i]);
	}

	printf("\n\n");

	for(i = 0; i < n; i++)
	{
		if(ptrb[i] > 1)
			printf("%d se repete %d vezes\n", i, ptrb[i]);
		else if(ptrb[i] == 1)
			printf("%d nao se repete\n", i);
	}

	free(ptr);
	free(ptrb);

	return 0;
}
