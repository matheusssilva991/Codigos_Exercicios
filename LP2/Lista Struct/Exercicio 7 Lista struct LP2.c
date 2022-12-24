#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *val;
	int n;
	int max;
	int min;
	float media;
		
}Tseq;	
	
int main()
{
	int i;
	Tseq seq;

	printf("Digite a quantidade de elementos da sequencia\n");
	scanf("%d", &seq.n);
	setbuf(stdin, NULL);
	
	seq.val = (int *) malloc(seq.n * sizeof(int));
	
	if(seq.val == NULL)
		exit(-1);
		
	for(i = 0, seq.media = 0; i < seq.n; i++)
	{
		printf("Digite o valor [%d]:\n", i);
		scanf("%d", &seq.val[i]);
		setbuf(stdin, NULL);
		
		seq.media += seq.val[i];	
	}
	
	seq.media /= seq.n;
	
	for(i = 0, seq.max = seq.val[i], seq.max = seq.val[i]; i < seq.n; i++)
	{
		if(seq.val[i] > seq.max)
			seq.max = seq.val[i];	
		else
			if(seq.val[i] < seq.max)
				seq.min = seq.val[i];		
	}
	
	printf("Valor Maximo: %d\n", seq.max);
	printf("Valor Minimo: %d\n", seq.min);
	printf("Media: %.2f\n", seq.media);
	
	free(seq.val);	

    return 0;
}

