#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nome[20];
	int win;
	int lose;
	int emp;
	int yellow;
	int red;
	int favor;
	int contra;
	int saldo;
	int pts;
	int fp;

}Tequipe;

int main()
{
	Tequipe *equipe, aux, *pdef, *patk, *pfp;
	int i, n, j;

	printf("Digite o numero de equipes:\n");
	scanf("%d", &n);
	setbuf(stdin, NULL);

	equipe = (Tequipe *) malloc(n * sizeof(Tequipe));

	if(equipe == NULL)
		exit(-1);

	for(i = 0; i < n; i++)  // usuario digitar as informa��es
	{
		printf("Digite o nome da Equipe[%d]:\n", i + 1);
		gets(equipe[i].nome);
		setbuf(stdin, NULL);

		printf("Digite a quantidade de vitorias da Equipe[%d]:\n", i + 1);
		scanf("%d", &equipe[i].win);
		setbuf(stdin, NULL);

		printf("Digite a quantidade de derrotas da Equipe[%d]:\n", i + 1);
		scanf("%d", &equipe[i].lose);
		setbuf(stdin, NULL);

		printf("Digite a quantidade de empates da Equipe[%d]:\n", i + 1);
		scanf("%d", &equipe[i].emp);
		setbuf(stdin, NULL);

		printf("Digite a quantidade de cartoes amarelo da Equipe[%d]:\n", i + 1);
		scanf("%d", &equipe[i].yellow);
		setbuf(stdin, NULL);

		printf("Digite a quantidade de cartoes vermelho da Equipe[%d]:\n", i + 1);
		scanf("%d", &equipe[i].red);
		setbuf(stdin, NULL);

		printf("Digite a quantidade de gols a favor da Equipe[%d]:\n", i + 1);
		scanf("%d", &equipe[i].favor);
		setbuf(stdin, NULL);

		printf("Digite a quantidade de gols contra da Equipe[%d]:\n", i + 1);
		scanf("%d", &equipe[i].contra);
		setbuf(stdin, NULL);

		equipe[i].saldo = equipe[i].favor - equipe[i].contra;
		equipe[i].pts = equipe[i].win * 3 + equipe[i].emp;
        equipe[i].fp = equipe[i].red * 2 + equipe[i].yellow;

		system("cls");
	}

	for(i = 1; i < n; i ++)  // organizar as equipes em ordem de pontos
		for(j = 0; j < n - 1; j++)
		{
			if(equipe[j].pts < equipe[j + 1].pts)
			{
				aux = equipe[j];
				equipe[j] = equipe[j + 1];
				equipe[j + 1] = aux;
			}
		}

	for(i = 0, pdef = &equipe[i], patk = &equipe[i], pfp = &equipe[i]; i < n; i++) // verificar time com melhor ataque e defesa e fairplay
    {
        if(equipe[i].contra < pdef -> contra)
            pdef = &equipe[i];

        if(equipe[i].favor > patk -> favor)
            patk = &equipe[i];

        if(equipe[i].fp < pfp -> fp)
            pfp = &equipe[i];
    }

    printf("Equipe Vencedora: %s\n", equipe[0].nome);
	printf("Equipe com melhor ataque: %s\n", patk -> nome);
	printf("Equipe com melhor defesa: %s\n", pdef -> nome);
    printf("Equipe Fair Play: %s\n\n", pfp -> nome);

    printf("PLACAR\n");
	printf("%s|%10s|%10s|%10s|%10s|%10s|%10s|%10s|%10s|%10s|\n", "Nome", "JG", "JE", "JP", "CA", "CV", "GF", "GC", "SC", "Pontos");

	for(i = 0; i < n; i++)
		printf("%s|%10d|%10d|%10d|%10d|%10d|%10d|%10d|%10d|%10d|\n", equipe[i].nome, equipe[i].win, equipe[i].emp, equipe[i].lose, equipe[i].yellow, equipe[i].red, equipe[i].favor, equipe[i].contra, equipe[i].saldo, equipe[i].pts);

	free(equipe);

    return 0;
}

