#include <stdio.h>
#include <stdlib.h>

void if_stmt();
void stmt();
void var();
void expr();
void term();
void factor();
void logic_expr();
void Y();
void lex();
void erro();
void print_stack();

char token;
FILE *file;
char stack[512];
char top = -1;

int main(int argc, char const *argv[])
{
    file = fopen("entrada_if_stmt.txt", "r");

    if (file == NULL){
        printf("Error ao abrir o arquivo.\n");
        exit(-1);
    }

    lex();
    if_stmt();
    print_stack();

    return 0;
}

void if_stmt(){
    if (token == '('){
        lex();
        logic_expr();

        if (token == ')'){
            lex();
            stmt();
        }else
            erro();
    }else
        erro();
}

void stmt(){
    var();

    if (token == '='){
        lex();
        expr();
    }else
        erro();  
}

void var(){
    if (token == 'a' || token == 'b' || token == 'c' || token == 'd'){
        lex();
    }else
        erro();
}

void expr(){
    term();

    while(token == '+' || token == '-'){
        lex();
        term();
    }
}

void term(){
    factor();

    while(token == '*' || token == '/'){
        lex();
        factor();
    }
}

void factor(){
    if (token == 'a' || token == 'b' || token == 'c' || token == 'd')
        lex();
    else if (token == '0' || token == '1')
        lex();
    else if (token == '('){
        lex();
        expr();

        if (token == ')')
            lex();
        else
            erro();    
    }else
        erro();
}

void logic_expr(){
    if (token == 'F' || token == 'T' || token == 'p' || token == 'q')
        lex();
    else if (token == '('){
        lex();
        logic_expr();
        Y();
        logic_expr();

        if(token == ')')
            lex();
        else
            erro();
    }else
        erro();
}

void Y(){
    if(token == '&' || token == '!' || token == '<' || token == '>')
        lex();
    else
        erro();
}

void erro(){
    printf("Erro.\n");
    exit(1);
}

void lex(){
    token = fgetc(file);
    top++;
    stack[top] = token;
}

void print_stack()
{
    printf("if ");
    for(int i = 0; i < top + 1; i++)
        printf("%c ", stack[i]);
    printf("\n");
}