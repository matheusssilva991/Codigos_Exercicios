#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float re;
	float im;
		
}TnumComp;

int main(void)
{
	TnumComp num1, num2;
	
	printf("Digite a parte real do primeiro numero:\n");
	scanf("%f", &num1.re);
	setbuf(stdin, NULL);
	
	printf("Digite a parte imaginaria do primeiro numero:\n");
	scanf("%f", &num1.im);
	setbuf(stdin, NULL);
	
	printf("Digite a parte real do segundo numero:\n");
	scanf("%f", &num2.re);
	setbuf(stdin, NULL);
	
	printf("Digite a parte imaginaria do segundo numero:\n");
	scanf("%f", &num2.im);
	setbuf(stdin, NULL);
	
	printf("Num1 + Num2 =  %.2f + %.2f\n", num1.re + num2.re, num1.im + num2.im);
	
	printf("Num1 + Num2 = %.2f + %.2f\n", num1.re - num2.re, num1.im - num2.im);
	
	return 0;
}
