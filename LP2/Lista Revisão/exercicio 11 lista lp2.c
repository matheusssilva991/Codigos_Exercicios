/*
    Exercício de Revisão
    Cadastra três notas de uma turma de N alunos e printa a média final da turma
*/

#include <stdio.h>
#include <stdlib.h>
#define QTD_NOTAS 3 //quantidade de notas

int main()
{
    int quantidadeAlunos;
    float mediaTurma[QTD_NOTAS] = {0}, mediaFinal = 0, **notasAlunos;

    printf("Digite a quantidade de alunos\n");
    scanf("%d", &quantidadeAlunos);

    notasAlunos = (float **) malloc(sizeof(float*) * quantidadeAlunos);// Cria as linhas

    for(int i = 0; i < quantidadeAlunos; i++) 
        notasAlunos[i] = (float *) malloc(sizeof(float) * QTD_NOTAS); // Cria as colunas

    for(int linhas = 0; linhas < quantidadeAlunos; linhas++) // Pegar notas dos Alunos e botar no Array
        for(int colunas = 0; colunas < QTD_NOTAS; colunas++)
        {
            printf("Digite a Credito[%d] do Aluno[%d]\n", colunas + 1, linhas + 1);
            scanf("%f", &notasAlunos[linhas][colunas]);

            system("cls");
            setbuf(stdin, NULL);
        }

	for(int linhas = 0; linhas < quantidadeAlunos; linhas++) // Printar creditos dos Alunos
        for(int colunas = 0; colunas < QTD_NOTAS; colunas++)
        	printf("Credito[%d] do Aluno[%d] = %d\n", colunas + 1, linhas + 1 , notasAlunos[linhas][colunas]);

	for(int colunas = 0; colunas < QTD_NOTAS; colunas++)  // somar notas dos alunos
        for(int linhas = 0; linhas < quantidadeAlunos; linhas++)
            mediaTurma[colunas] +=  notasAlunos[linhas][colunas];

    for(int indiceMedia = 0; indiceMedia < QTD_NOTAS; indiceMedia++)//Divide a média por Qtd_alunos e printa média crédito
    {
        mediaTurma[indiceMedia] = mediaTurma[indiceMedia] / quantidadeAlunos;
        printf("Media Turma Credito[%f] = %.1f\n", indiceMedia + 1, mediaTurma[indiceMedia]);
    }   
    
	mediaFinal = (mediaTurma[0] + mediaTurma[1]+ mediaTurma[2]) / QTD_NOTAS;
	printf("Media final da turma e %.1f\n", mediaFinal);

    return 0;
}

