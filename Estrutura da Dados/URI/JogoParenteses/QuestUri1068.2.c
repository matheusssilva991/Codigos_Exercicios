#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int verificaExpressao(char *expressao);

// Main
int main(void)
{
    char expressaoAlgebrica[1001];

    while(scanf("%1000s", expressaoAlgebrica) != EOF)
    {
        
        if(verificaExpressao(expressaoAlgebrica))
            printf("correct\n");
        else
            printf("incorrect\n");   
    }
    
    return 0;
}

int verificaExpressao(char *expressao)
{
    int quantidadeParenteses = 0;
    int tamanho = strlen(expressao);

    if(expressao[0] == ')' || expressao[tamanho - 1] == '(')
        return 0;

    for(int i = 0; i < tamanho; i++)
    {
        if(expressao[i] == '(')
            ++quantidadeParenteses;
        if(expressao[i] == ')')
            --quantidadeParenteses;
    }

    if(quantidadeParenteses == 0)
        return 1;
    else 
        return 0;       
}
