#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void lex();
void expr();
void term();
void factor();

void printa_producoes();
void registra_producao(char *);
void registra_token();
int is_decimal();

char token;
FILE *file;
char *decimais = "0123456789";
char *lista_producoes[512], *lista_tokens[512];
char palavra[512];
int index_producoes = -1, index_tokens = -1;

int main(int argc, char const *argv[])
{
    file = fopen("entrada.txt", "r");

	fscanf(file, "%s", palavra);
	rewind(file);
	
	lex();
	expr();

	if (index_tokens == strlen(palavra))
		printf("Programa aceito.\n");
	else
		printf("Programa nao foi aceito.\n");
		
	printa_producoes();
	printf("Palavra: %s\t", palavra);
	printa_tokens();

    fclose(file);
    return 0;
}

void lex(){
	token = fgetc(file);
	registra_token();	
}

void expr(){
	registra_producao("expr");

	term();
	while (token=='+' || token=='-'){
		lex(); 
		term();
	}
}

void term(){
	registra_producao("term");

	factor();
	while (token=='*' || token=='/'){
		lex();
		factor();
	}//end-while
}//end-term

void factor(){
	registra_producao("factor");

	if (token=='x' || token=='y' || token=='z' || is_decimal())
        lex();	
	else if (token=='('){ 
		lex();
		expr();
		if (token==')')
			lex();
		else{
			printf("Programa nao foi aceito.\n");
			printa_producoes();
			printa_tokens();
			printf("Error Sintatico 1.\n");
			exit(1);
		}     
	}
	else{
		printf("Programa nao foi aceito.\n");
		printa_producoes();
		printa_tokens();
		printf("Error Sintatico 2.\n");
		exit(2);
	}     
}//end-factor

void registra_producao(char *producao){
	index_producoes++;
	lista_producoes[index_producoes] = producao;
}
void registra_token(){
	++index_tokens;
	lista_tokens[index_tokens] = token;
}

void printa_producoes(){
	printf("Producoes: ");
	for (int i = 0; i < index_producoes + 1; i++)
		printf("%s ", lista_producoes[i]);
	printf("\n");
}

void printa_tokens(){
	printf("Tokens: ");
	for (int i = 0; i < index_tokens + 1; i++)
		printf("%c", lista_tokens[i]);
	printf("\n");
}

int is_decimal(){
    for(int i = 0; i < 10; i++)
        if (token == decimais[i])
            return 1;
    return 0; 
}