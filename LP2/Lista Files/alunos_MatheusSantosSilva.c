#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct
{
    long int matricula;
    float nota;

}Taluno;

void escreve();
void lerEscreve(FILE *);

int main()
{

    FILE *arquivoAleatorio;

    arquivoAleatorio = fopen("ArquivoAleatorio.dat", "wb");

    if(arquivoAleatorio == NULL)
    {
        printf("erro ao abrir.\n");
        exit(-1);

    }

    escreve();
    lerEscreve(arquivoAleatorio);

    fclose(arquivoAleatorio);

    return 0;
}

void escreve()
{

    FILE *arquivo;
    Taluno aluno;
    int i;

    arquivo = fopen("arquivoSequencial.txt", "w");

    if(arquivo == NULL)
    {
        printf("erro ao abrir.\n");
        exit(-1);

    }


    srand(time(NULL));

    for(i = 0; i < 30; i++)
    {
        aluno.matricula = rand() % 32767;
        aluno.nota = rand() % 11;

        fprintf(arquivo, "%ld   %.2f\n", aluno.matricula, aluno.nota);
    }

    fclose(arquivo);

}

void lerEscreve(FILE *arqAleatorio)
{
    int tamanho = 0, i = 0;
    Taluno *aluno, aux = {0, 0}, guarda = {0, 0};
    float media = 0;
    FILE *arquivo;

    arquivo = fopen("arquivoSequencial.txt", "r");

    if(arquivo == NULL)
    {
        printf("erro ao abrir.\n");
        exit(-1);

    }

    rewind(arquivo);

    fscanf(arquivo, "%ld %f", &aux.matricula, &aux.nota);

    guarda = aux;

    while(!feof(arquivo))
    {
        tamanho++;
        media += aux.nota;

        if(guarda.nota < aux.nota)
            guarda = aux;

        fscanf(arquivo, "%ld %f", &aux.matricula, &aux.nota);
    }

    media /= tamanho;

    printf("Media = %.2f\n", media);
    printf("Maior nota: %.2f\nMatricula: %ld\n", guarda.nota, guarda.matricula);

    aluno = (Taluno *) malloc(sizeof(Taluno) * tamanho);

    if(aluno == NULL)
    {
        printf("Erro");
        return;
    }

    rewind(arquivo);

    fscanf(arquivo, "%ld %f", &aux.matricula, &aux.nota);
    aluno[i] = aux;

    while(!feof(arquivo))
    {
        i++;

        fscanf(arquivo, "%ld %f", &aux.matricula, &aux.nota);

        aluno[i] = aux;
    }

    fwrite(aluno, sizeof(Taluno), tamanho, arqAleatorio);

    free(aluno);

    fclose(arquivo);

}
