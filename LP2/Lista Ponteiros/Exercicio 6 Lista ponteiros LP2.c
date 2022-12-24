#include <stdlib.h>
#include <stdio.h>
#define TAM 10

int main(void)
{
	
	float Kms[TAM] = {240.5, 300.0, 189.6, 310.6, 280.7, 216.9, 199.4, 160.3, 177.4, 192.3};
	float Lts[TAM] = {10.3, 15.6, 8.7, 14, 16.3, 15.7, 14.9, 10.7, 8.3, 8.4}, KpL[TAM];
	int i;
	
	printf("NOTACAO CONVENCIONAL SUBSCRITOS\n");
	
	for(i = 0; i <= TAM - 1; i++)
	{
		KpL[i] = Kms[i] / Lts[i];
		
		printf("KpL[%d] = %.1f\n", i, KpL[i]);				
	}
	
	printf("\nNOTACAO ARITMETICA DE PONTEIROS\n");
	
	for(i = 0; i <= TAM - 1; i++)
	{
		*(KpL + i) = *(Kms + i) / *(Lts + i);
		
		printf("*(KpL + %d) = %.1f\n", i, KpL[i]);					
	}	
		
	return 0;
}
