#include <stdio.h>
#include <stdlib.h>

void testeMultiplos(int , int);

int main(int argc, char *argv[])
{
    int numA, numB, op;

    while(op != -1)
    {

        printf("Digite o primeiro numero: \n");
        scanf("%d", &numA);
        setbuf(stdin, NULL);

        printf("Digite o segundo numero: \n");
        scanf("%d", &numB);
        setbuf(stdin, NULL);

        if(numB < numA)
            testeMultiplos(numB, numA);
        else
            testeMultiplos(numA, numB);

        printf("[1] Para Continuar\n[-1] Para Sair\n");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        system("cls");
    }

	return 0;
}

void testeMultiplos(int numeroA, int numeroB)
{
    if(numeroB % numeroA == 0)
        printf("Sao multiplos.\n");

    else
        printf("Nao Sao multiplos.\n");
}

