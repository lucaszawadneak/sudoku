/*
 *  Trabalho 1 - Passos para resolver o sudoku
 *  Autor:
 *  Data:
 */
#include <stdio.h>
#include <string.h>

#define TAMANHO 9
#define POSSIVEIS [ 1, 2, 3, 4, 5, 6, 7, 8, 9 ]

// void inicializaVetor(int v[], int tam)
// {
//     int i;
//     for (i = 0; i < tam; i++)
//     {
//         v[i] = 0;
//     }
// }

// void inicializa3Vetor(int v1[], int v2[], int v3[], int tam)
// {
//     inicializaVetor(v1, tam);
//     inicializaVetor(v2, tam);
//     inicializaVetor(v3, tam);
// }

void showSudoku(int mat[][TAMANHO])
{
    int i, j;
    printf("\n +-----------+-----------+-----------+\n");
    for (i = 0; i < TAMANHO; i++)
    {
        printf(" | ");
        for (j = 0; j < TAMANHO; j++)
        {
            if (mat[i][j] > 0)
            {
                printf(" %1d ", mat[i][j]);
            }
            else
            {
                printf(" _ ");
            }
            if (j == 2 || j == 5 || j == 8)
            {
                printf(" | ");
            }
        }
        if (i % 3 == 2)
        { // mesma coisa que i%3 == 0
            printf("\n +-----------+-----------+-----------+\n");
        }
        else
            printf("\n");
    }
}

void invalidInColumn(int mat[][TAMANHO], int pos)
{
    int i, value, k;
    int invalid[9];

    for (value = 1; value <= TAMANHO; value++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            if (value == mat[i][pos])
            {
                for (k = 0; 0 == 0; k++)
                {
                    if (invalid[k] == '\0')
                    {
                        invalid[k + 1] = '\0';
                        invalid[k] = value;
                        break;
                    }
                }
                break;
            }
        }
    }
}

void invalidInLine(int mat[][TAMANHO], int pos)
{
    int i, value, k;
    int invalid[9];

    for (value = 1; value <= TAMANHO; value++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            if (value == mat[pos][i])
            {
                for (k = 0; 0 == 0; k++)
                {
                    if (invalid[k] == '\0')
                    {
                        invalid[k + 1] = '\0';
                        invalid[k] = value;
                        printf("%i - ", invalid[k]);
                        break;
                    }
                }
                break;
            }
        }
    }
}

void invalidInGroup(int mat[][TAMANHO], int groupLine, int groupCol)
{
    int i, j, k, value;
    int invalid[9];
    int linePosition = groupLine * 3;
    int columnPosition = groupCol * 3;

    for (value = 1; value <= TAMANHO; value++)
    {
        for (i = linePosition; i <= linePosition + 2; i++)
        {
            for (j = columnPosition; j <= columnPosition + 2; j++)
            {
                // printf("%i - ", mat[i][j]);
                if (mat[i][j] == value)
                {
                    for (k = 0; 0 == 0; k++)
                    {
                        if (invalid[k] == '\0')
                        {
                            invalid[k + 1] = '\0';
                            invalid[k] = value;
                            printf("%i - ", invalid[k]);
                            break;
                        }
                    }
                }
            }
        }
    }
}

int findMatch(int mat[][TAMANHO], int line, int col, int groupLine, int groupCol)
{
    int lineMatches, colMatches, groupMatches;

    return 0;
}

int solveGame(int mat[][TAMANHO])
{
    int line, col, groupLine, groupCol, value;
    // [LINHA,COLUNA];
    // GROUP = QUADRADOS MENORES DO SUDOKU (DE 1 a 9)
    for (line = 1; line <= TAMANHO; line++)
    {
        groupLine = (line - 1) / 3;
        for (col = 1; col <= TAMANHO; col++)
        {
            // printf("%i\n", mat[line][col]);
            // groupCol = (col - 1) / 3;
            // mat[line][col] = findMatch(mat, line, col, groupLine, groupCol);
        }
    }

    showSudoku(mat);
}

int main()
{
    int jogoInicial[9][9] = {{9, 4, 0, 1, 0, 2, 0, 5, 8},
                             {6, 0, 0, 0, 5, 0, 0, 0, 4},
                             {0, 0, 2, 4, 0, 3, 1, 0, 0},
                             {0, 2, 0, 0, 0, 0, 0, 6, 0},
                             {5, 0, 8, 0, 2, 0, 4, 0, 1},
                             {0, 6, 0, 0, 0, 0, 0, 8, 0},
                             {0, 0, 1, 6, 0, 8, 7, 0, 0},
                             {7, 0, 0, 0, 4, 0, 0, 0, 3},
                             {4, 3, 0, 5, 0, 9, 0, 1, 2}};
    int solucao[9][9];
    int linha[9], coluna[9], grupo[9], i, j;

    // copia os valores de jogoInicial para solucao
    memcpy(solucao, jogoInicial, sizeof(int) * 81);

    // printf("Configuracao inicial do jogo:\n");
    showSudoku(solucao);

    invalidInGroup(solucao, 0, 0);
    // printf("%s", "\nSolução:\n");
    // solveGame(solucao);

    return 0;
}