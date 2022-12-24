/*
    Atividade de revisão
    Cadastrar aluno e printar dados sobre a situação dos alunos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cadastro
{
    char nome[80];
    char sexo;
    char situacao[15]
}cadastro;

void lerSituacao (char *situacao, int *aproSexo, int *repSexo, int *aproTotal, int *repTotal);

int main()
{
    cadastro pessoa[80];
    int i, opcao, quantidadeAlunosMasc, quantidadeAlunosfem, aprovadosTotal, reprovadosTotal;
    int reprovadosMasc, reprovadosFem, aprovadosMasc, aprovadosFem; 

    i = quantidadeAlunosMasc = quantidadeAlunosfem = aprovadosTotal = reprovadosTotal = 0 ;
    aprovadosMasc = reprovadosMasc = aprovadosFem = reprovadosFem = 0;

    while(opcao != -1)
    {
        printf("Digite seu nome\n");
        scanf("%s", pessoa[i].nome);
        setbuf(stdin, NULL);

        printf("Digite seu sexo\t[M]  [F]\n:");
        scanf("%c", &pessoa[i].sexo);
        setbuf(stdin, NULL);

        printf("Digite a sua situacao\t[APROVADO]  [REPROVADO]\n:");
        scanf("%s", pessoa[i].situacao);
        setbuf(stdin, NULL);
        
        if(pessoa[i].sexo == 'M' || pessoa[i].sexo == 'm')
        {
            quantidadeAlunosMasc++;
            lerSituacao(pessoa[i].situacao, &aprovadosMasc, &reprovadosMasc, &aprovadosTotal, &reprovadosTotal);
        }

        else if(pessoa[i].sexo == 'F' || pessoa[i].sexo == 'f')
        {
            quantidadeAlunosfem++;
            lerSituacao(pessoa[i].situacao, &aprovadosFem, &reprovadosFem, &aprovadosTotal, &reprovadosTotal);
        }

        printf("Digite -1 para Sair ou outro numero para continuar\n");
        scanf("%d", &opcao);

        i++;
        system("cls");
    }

    system("cls");
    fflush(stdin);
    printf("Total de alunos do sexo masculino = %d\n", quantidadeAlunosMasc);
    printf("\taprovados = %d\n", aprovadosMasc);
    printf("\treprovados = %d\n\n", reprovadosMasc);
    printf("Total de alunos do sexo feminino = %d\n", quantidadeAlunosfem);
    printf("\taprovados = %d\n", aprovadosFem);
    printf("\treprovados = %d\n\n", reprovadosFem);
    printf("Total de alunos aprovados = %d\n", aprovadosTotal);
    printf("Total de alunos reprovados = %d\n", reprovadosTotal);

    return 0;
}

void lerSituacao(char *situacao, int *aproSexo, int *repSexo, int *aproTotal, int *repTotal)
{
    if(strcmp(situacao,"REPROVADO") == 0 || strcmp(situacao,"reprovado") == 0)
    {
        ++*repTotal;
        ++*repSexo;
    }
        
    else if(strcmp(situacao,"APROVADO") == 0 || strcmp(situacao,"aprovado") == 0)
    {
        ++*aproTotal;
        ++*aproSexo;
    }
}

