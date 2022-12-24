/*  
    Exercício Revisão
    Cadastra pontos adquiridos por uma equipe e printa o total de pontos
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct EQUIPE
{
  char nome[20];
  int derrotas;
  int empates;
  int vitorias;
}Equipe;

int main ()
{
    Equipe equipe;

    printf("Digite o nome da equipe\n");

    gets(equipe.nome);

    printf("Digite as vitorias\n");
    scanf("%d", &equipe.vitorias);

    printf("Digite os empates\n");
    scanf("%d", &equipe.empates);

    printf("Digite as derrotas\n");
    scanf("%d", &equipe.derrotas);

    equipe.vitorias *= 3;
    equipe.vitorias += equipe.empates;
    equipe.vitorias -= (equipe.derrotas * 3);

    printf("Total de pontos e = %d\n", equipe.vitorias);

    return 0;
}

