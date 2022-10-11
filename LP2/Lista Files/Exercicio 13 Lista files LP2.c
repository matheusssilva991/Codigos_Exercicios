#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    long int matricula;
    char nome[30];
    float cr;

}Taluno;

void mostra(int , FILE *);

int main()
{
    FILE *arquivo;
    int op;

    arquivo = fopen("Quest12.dat", "rb");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir.\n");
        exit(-1);
    }

    while(1)
    {
        printf("[1]Alunos com CR > 7\n[2]Alunos com 5 < CR < 7\n[3]Alunos com CR < 5\n[4]Sair\n");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        if(op == 4)
            break;

        mostra(op, arquivo);

        system("cls");
    }

    fclose(arquivo);

    return 0;
}

void mostra(int op, FILE *arquivo)
{
    Taluno aluno;

    rewind(arquivo);

    switch(op)
    {
        case 1:

            fread(&aluno, sizeof(Taluno), 1, arquivo);

            while(!feof(arquivo))
            {
                if(aluno.cr >= 7)
                    printf("Matricula: %ld\nNome: %s\nCR: %.2f\n\n", aluno.matricula, aluno.nome, aluno.cr);

                fread(&aluno, sizeof(Taluno), 1, arquivo);
            }
            break;

        case 2:

            fread(&aluno, sizeof(Taluno), 1, arquivo);

            while(!feof(arquivo))
            {
                if(aluno.cr >= 5 && aluno.cr < 7)
                    printf("Matricula: %ld\nNome: %s\nCR: %.2f\n\n", aluno.matricula, aluno.nome, aluno.cr);

                fread(&aluno, sizeof(Taluno), 1, arquivo);
            }
            break;

        case 3:

            fread(&aluno, sizeof(Taluno), 1, arquivo);

            while(!feof(arquivo))
            {
                if(aluno.cr < 5)
                    printf("Matricula: %ld\nNome: %s\nCR: %.2f\n\n", aluno.matricula, aluno.nome, aluno.cr);

                fread(&aluno, sizeof(Taluno), 1, arquivo);
            }
            break;

    }

    system("pause");

    return;
}
