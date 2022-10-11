#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void isSubsequencia(char *palavra, char *query);
void sequencia();

// Main
int main(int argc, char const *argv[])
{
    sequencia();

    return 0;
}

void sequencia()
{
    int Q, N;
    char palavra[100010];
    char query[110];

    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
    {
        scanf("%s", palavra);

        scanf("%d", &Q);

        for (int j = 0; j < Q; j++)
        {
            scanf("%s", query);

            isSubsequencia(palavra, query);
        }

    }
}

void isSubsequencia(char *palavra, char *query)
{
    char *inicio = NULL;
    char *aux = NULL;
    char *fim = &palavra[strlen(palavra) - 1];
    int isSub = 1;

    if (strlen(query) > strlen(palavra))
    {
        printf("No\n");
        return;
    }

    inicio = &palavra[0];

    while (inicio != fim)
    {
        aux = inicio;

        for (int i = 0; i < strlen(query) - 1; i++)
        {
            isSub = 1;

            if (*aux != query[i])
            {
                isSub = 0;
                break;
            }

            aux++;
        }

        if (strlen(aux) < strlen(query))
        {
            printf("No\n");
            return;
        }

        if (isSub)
        {
            printf("Yes\n");
            return;
        }

        inicio++;
    }

    printf("No\n");
}
