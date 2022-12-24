#include <stdlib.h>
#include <stdio.h>

#define AMAX 2048 //{maximum address}
#define LEVMAX 3 // {maximum depth of block nesting}
#define CXMAX 2049 // {size of code array}
#define stacksize 500

typedef enum FCT{
    LIT = 0,
    OPR = 1,
    LOD = 2,
    STO = 3,
    CAL = 4,
    INT = 5,
    JMP = 6,
    JPC = 7
}fct;

typedef struct INSTRUCTION{
    fct f;
    int l; // level
    int a; // address or argument   
}Instruction;

Instruction code[CXMAX];

int p, b, t; //{program-, base-, topstack-registers}
Instruction i; // {instruction register}
int s[stacksize]; // {datastore}
int current_instruction = 0;

int base(int l){
    int b1 = b;

    while (l > 0){
        b1 = s[b1];
        l = l - 1;
    }
    return b1;
}

void set_instruction(fct f, int level, int argument){
    code[current_instruction].f = f; code[current_instruction].l = level; code[current_instruction].a = argument;
    current_instruction+=1;
}

void printStack(int limit){
    for (int i = 0; i < limit; i++)
        printf("[%d] ", s[i]);
    printf("\n");
}

void plcode(){
    printf("start pl/0\n\n");
    t = -1, b = 0, p = 0;
    s[1] = 0; s[2] = 0; s[3] = 0;

    do{
        i = code[p]; p = p + 1;

        switch(i.f){
            case LIT:
                t = t + 1; s[t] = i.a;
                printf("LIT %d %d  | Pilha: ", i.l, i.a); printStack(10);
                break;
            case OPR:
                switch(i.a){
                    case 0: {t = b - 1; p = s[t + 3]; b = s[t + 2]; break;}
                    case 1: {s[t] = -s[t]; break;}
                    case 2: {t = t - 1; s[t] = s[t] + s[t + 1]; s[t + 1] = 0; break;}
                    case 3: {t = t - 1; s[t] = s[t] - s[t + 1]; s[t + 1] = 0; break;}
                    case 4: {t = t - 1; s[t] = s[t] * s[t + 1]; s[t + 1] = 0; break;}
                    case 5: {t = t - 1; s[t] = s[t] / s[t + 1]; s[t + 1] = 0; break;}
                    case 6: {s[t] = s[t] % 2 != 0 ? 1: 0; break;}
                    case 8: {t = t - 1; s[t] = s[t] == s[t + 1]; s[t + 1] = 0; break;}
                    case 9: {t = t - 1; s[t] = s[t] != s[t + 1]; s[t + 1] = 0; break;}
                    case 10: {t = t - 1; s[t] = s[t] < s[t + 1]; s[t + 1] = 0; break;}
                    case 11: {t = t - 1; s[t] = s[t] >= s[t + 1]; s[t + 1] = 0; break;}
                    case 12: {t = t - 1; s[t] = s[t] > s[t + 1]; s[t + 1] = 0; break;}
                    case 13: {t = t - 1; s[t] = s[t] <= s[t + 1]; s[t + 1] = 0; break;}
                    default:
                        printf("nothing");
                }
                printf("OPR %d %d  | Pilha: ", i.l, i.a); printStack(10);
                break;
            case LOD:
                t = t + 1; s[t] = s[base(i.l) + i.a]; printf("LOD %d %d  | Pilha: ", i.l, i.a); printStack(10); break; 
            case STO:
                s[base(i.l) + i.a] = s[t];t = t - 1; printf("STO %d %d  | Pilha: ", i.l, i.a); printStack(10); break;
            case CAL:
                s[t + 1] = base(i.l); s[t + 2] = b; s[t + 3] = p;
                b = t + 1; p = i.a;
                printf("CALL %d %d  | Pilha: ", i.l, i.a); printStack(10);
                break;
            case INT:
                t = t + i.a; printf("INT %d %d  | Pilha: ", i.l, i.a); printStack(10); break;
            case JMP:
                p = i.a; 
                printf("JMP %d %d  | Pilha: ", i.l, i.a); 
                printStack(10); 
                break;
            case JPC:
                if (s[t] == 0)
                    p = i.a; t = t - 1;
                printf("JPC %d %d  | Pilha: ", i.l, i.a); printStack(10);
                break;
        }

    }while(p != current_instruction);

    printf("\n\nend pl/0\n");
}

int main(){
    set_instruction(INT, 0, 5);//1
    set_instruction(LIT, 0, 0);//2
    set_instruction(STO, 0, 3);//3
    set_instruction(LIT, 0, 1);//4
    set_instruction(STO, 0, 4);//5
    set_instruction(LOD, 0, 3);//6
    set_instruction(LOD, 0, 4);//7
    set_instruction(OPR, 0, 2);//8
    set_instruction(STO, 0, 3);//9
    set_instruction(LOD, 0, 4);//10
    set_instruction(LIT, 0, 1);//11
    set_instruction(OPR, 0, 2);//12
    set_instruction(STO, 0, 4);//13
    set_instruction(LOD, 0, 4);//14
    set_instruction(LIT, 0, 100);//15
    set_instruction(OPR, 0, 12);//16
    set_instruction(JPC, 0, 5);//17
    set_instruction(LOD, 0, 3);//18

    plcode();

    return 0;
}