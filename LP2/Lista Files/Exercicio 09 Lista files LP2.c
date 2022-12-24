#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, i;
    float *v, media = 0;
    FILE *arquivo;

    arquivo = fopen("Quest8.dat", "rb");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(-1);
    }

    fread(&n, sizeof(int), 1, arquivo); /// ler o tamanho do vetor

    v = (float *) malloc(sizeof(float) * n); /// alocar o vetor

    if(v == NULL)
    {
        printf("Erro ao alocar.\n");
        exit(-1);
    }

    fread(v, sizeof(float), n, arquivo);  ///ler o vetor

    for(i = 0; i < n; i++)   ///printar o vetor
    {
        printf("%.2f ", v[i]);

        media += v[i];

    }
    media /= n;

    printf("\nMedia = %.2f\n", media);

    fclose(arquivo);
    free(v);

  return 0;
}
