#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, i;
    float *v;
    FILE *arquivo;

    printf("Digite o Tamanho do Vetor:\n");
    scanf("%d", &n);
    setbuf(stdin, NULL);

    v =  (float *) malloc(n * sizeof(float));

    if(v == NULL)
    {
        printf("Erro ao alocar.\n");
        exit(-1);
    }

    arquivo = fopen("Quest8.dat", "wb");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(-1);
    }

    for(i = 0; i < n; i++)
    {
        printf("Digite %d numero:\n", i + 1);
        scanf("%f", &v[i]);
        setbuf(stdin, NULL);

        system("cls");
    }
    fwrite(&n, sizeof(int), 1, arquivo);
    fwrite(v, sizeof(float), n, arquivo);

    fclose(arquivo);
    free(v);

    return 0;
}
