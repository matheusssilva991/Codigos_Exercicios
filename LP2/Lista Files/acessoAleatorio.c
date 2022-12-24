#include <stdio.h>
#include <stdlib.h>
#define N 5


int main(void)
{
    FILE *arquivo;
    int vetor[N], i;

    arquivo = fopen("AleatorioClientes.dat", "rb");

    if(arquivo == NULL)
    {
        printf("Erro ao criar o arquivo.");
        exit(-1);
    }

    for(i = 0; i < N; i++)
        vetor[i] = i + 1;

    fwrite(vetor, sizeof(int), N, arquivo);

    fread(vetor, sizeof(int), N, arquivo);

    for(i = 0; i < N; i++)
        printf("%d\n", vetor[i]);

    fclose(arquivo);

    return 0;
}


