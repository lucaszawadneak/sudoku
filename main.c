/*
 *  Trabalho 1 - Passos para resolver o sudoku
 *  Autor: Lucas Cassilha Zawadneak
 *  Data: Janeiro 2021
 */
#include <stdio.h>
#include <string.h>

#define TAMANHO 9

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

int *invalidInColumn(int mat[][TAMANHO], int pos)
{
    int i, value, k;
    static int invalid[10];

    for (value = 1; value <= TAMANHO; value++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            if (value == mat[i][pos])
            {
                // printf("Valores coluna %i: ", pos);
                for (k = 0; 0 == 0; k++)
                {
                    if (invalid[k] == '\0')
                    {
                        invalid[k + 1] = '\0';
                        invalid[k] = value;
                        // printf("%i ", value);
                        break;
                    }
                }
                // printf("\n");
                break;
            }
        }
    }

    return invalid;
}

int *invalidInLine(int mat[][TAMANHO], int pos)
{
    int i, value, k;
    static int invalid[10];

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
                        break;
                    }
                }
                break;
            }
        }
    }

    return invalid;
}

int *invalidInGroup(int mat[][TAMANHO], int groupLine, int groupCol)
{
    int i, j, k, value;
    static int invalid[10];
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
                            // printf("%i ", value);
                            break;
                        }
                    }
                }
            }
        }
    }

    return invalid;
}

void findMatch(int mat[][TAMANHO], int line, int col)
{
    int i, j, lineMatches, colMatches;
    static int possibleNumbers[10];
    int *lineInvalid;
    int *columnInvalid;
    int *groupInvalid;

    int groupLine = (line) / 3;
    int groupCol = (col) / 3;

    lineInvalid = invalidInLine(mat, line);
    columnInvalid = invalidInColumn(mat, col);
    groupInvalid = invalidInGroup(mat, groupLine, groupCol);

    int valid = 1, value;
    for (j = 1; j <= TAMANHO; j++)
    {
        valid = 0;
        for (i = 0; i < TAMANHO; i++)
        {
            // printf("%i %i %i - %i\n", *(lineInvalid + i), *(columnInvalid + i), *(groupInvalid + i), j);
            if (*(lineInvalid + i) == j || *(columnInvalid + i) == j || *(groupInvalid + i) == j)
            {
                // printf("%i ", j);
                valid = 1;
                continue;
            }
        }
        // printf("%i ", valid);
        if (valid == 0)
        {
            printf("%i ", j);
        }
    }
}

int solveGame(int mat[][TAMANHO])
{
    int line, col, value;
    // [LINHA,COLUNA];
    // GROUP = QUADRADOS MENORES DO SUDOKU (DE 1 a 9)
    for (line = 1; line <= TAMANHO; line++)
    {
        for (col = 1; col <= TAMANHO; col++)
        {
            // printf("%i\n", mat[line][col]);
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

    findMatch(solucao, 3, 3);

    // printf("Configuracao inicial do jogo:\n");
    showSudoku(solucao);

    // printf("%s", "\nSolução:\n");
    // solveGame(solucao);

    return 0;
}