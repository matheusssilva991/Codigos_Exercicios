#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void push(char *token);
char pop();
void state_q1();
void print_stack();
int stackIsEmpty();

char stack[512];
int top = -1;
char token;
FILE *file;

int main(int argc, char const *argv[])
{
    file = fopen("entrada.txt", "r");
    char *palavra;

    if (file == NULL){
        printf("erro abrir arquivo.\n");
        exit(-1);
    }

    fscanf(file, "%s", palavra);
    rewind(file);

    push("(SXS)");
    print_stack();

    token = fgetc(file);

    //Q1
    state_q1();
    print_stack();
        
    if (top == -1)
        printf("Palavra %s aceita.\n\n", palavra);
    else{
        printf("Palavra %s nao aceita.\n\n", palavra);
        top = -1;  
    }

    return 0;
}

void state_q1(){
    if (token=='(' && stack[top]=='S') {pop(); push("(SXS)"); state_q1();}
    else if (token=='0' && stack[top]=='S') { pop(); push("0"); state_q1(); }
    else if (token=='1' && stack[top]=='S') { pop(); push("1"); state_q1(); }
    else if (token=='+' && stack[top]=='X') { pop(); push("+"); state_q1(); }
    else if (token=='-' && stack[top]=='X') { pop(); push("-"); state_q1(); }
    else if (token=='*' && stack[top]=='X') { pop(); push("*"); state_q1(); }
    else if (token=='/' && stack[top]=='X') { pop(); push("/"); state_q1(); }
    else if (token=='(' && stack[top]=='(') { pop(); token = fgetc(file); state_q1(); }
    else if (token==')' && stack[top]==')') { pop(); token = fgetc(file); state_q1(); }
    else if (token=='0' && stack[top]=='0') { pop(); token = fgetc(file); state_q1(); }
    else if (token=='1' && stack[top]=='1') { pop(); token = fgetc(file); state_q1(); }
    else if (token=='+' && stack[top]=='+') { pop(); token = fgetc(file); state_q1(); }
    else if (token=='-' && stack[top]=='-') { pop(); token = fgetc(file); state_q1(); }
    else if (token=='*' && stack[top]=='*') { pop(); token = fgetc(file); state_q1(); }
    else if (token=='/' && stack[top]=='/') { pop(); token = fgetc(file); state_q1(); }
    else if (stackIsEmpty()) return;
    else {printf("Erro 1.\n"); return; }
}

void push(char *token){
    int tam_token = strlen(token) - 1;

    for(int i = tam_token; i >= 0; i--){
        top++;
        stack[top] = token[i];
    }  
}

char pop(){
    return stack[top--];
}

void print_stack(){
    printf("STACK: ");
    for (int i = top; i >= 0; i--){
        printf("%c", stack[i]);
    }
    printf("\n");
}

int stackIsEmpty(){
    if (top == -1)
        return 1;
    else 
        return 0;
}
