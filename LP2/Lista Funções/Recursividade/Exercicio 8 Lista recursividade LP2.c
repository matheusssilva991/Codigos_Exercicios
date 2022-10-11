#include <stdlib.h>
#include <stdio.h>

void binRec(int );

int main()
{
	int decimal;

	printf("Digite o decimal: \n");
	scanf("%d", &decimal);
	setbuf(stdin, NULL);

	binRec(decimal);	

	return 0;
}

void binRec(int dec)
{
	if(dec / 2 == 1 || dec / 2 == 0)
    {
        printf("%d", dec / 2);
    }
	else
        binRec(dec / 2);

	printf("%d", dec % 2);
}
