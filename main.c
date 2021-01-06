/*
 *  Trabalho 1 - Passos para resolver o sudoku
 *  Autor: Lucas Cassilha Zawadneak
 *  Data: Janeiro 2021
 */
#include <stdio.h>
#include <string.h>

#define TAMANHO 9

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

int findMatch(int mat[][TAMANHO], int line, int col)
{
    int i, j, lineMatches, colMatches, matchNumber = 0;
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
                break;
            }
        }
        // printf("%i ", valid);
        if (valid == 0)
        {
            matchNumber++;
            printf("%i ", j);
        }
    }
    printf("\n");
    return matchNumber;
}

void findNotMatch(int mat[][TAMANHO], int line, int col)
{
    int i, j, lineMatches, colMatches;
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
        valid = 1;
        for (i = 0; i < TAMANHO; i++)
        {
            // printf("%i %i %i - %i\n", *(lineInvalid + i), *(columnInvalid + i), *(groupInvalid + i), j);
            if (*(lineInvalid + i) == j || *(columnInvalid + i) == j || *(groupInvalid + i) == j)
            {
                // printf("%i ", j);
                valid = 0;
                break;
            }
        }
        // printf("%i ", valid);
        if (valid == 0)
        {
            printf("%i ", j);
        }
    }
    printf("\n");
}

void printReverse(int array[9])
{
    int i, j, valid;
    printf("Valores válidos:\n");
    for (j = 1; j <= 9; j++)
    {
        valid = 0;
        for (i = 0; i < 9; i++)
        {
            // printf("%i %i\n", i, j);
            if (j == array[i])
            {
                valid = 1;
                break;
            }
        }
        if (valid == 0)
        {
            printf("%i ", j);
        }
    }
    printf("\n");
}

void print(int array[9])
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if (array[i] != '\0' && array[i] != 0)
        {
            printf("%i ", array[i]);
        }
    }
}

void sudokuMenu(int mat[][TAMANHO])
{
    int question = 0, line, column, *aux;

    printf("\nEscolha uma opção:\n");
    printf("1. Quais valores faltam na linha X?\n");
    printf("2. Quais valores faltam na coluna Y?\n");
    printf("3. Quais valores faltam no grupo Z?\n");
    printf("4. Quais valores determinada célula pode conter?\n");
    printf("5. Quais valores determinada célula não pode conter?\n");

    while (question == 0)
    {
        scanf("%i", &question);
        if (question > 5 || question < 1)
        {
            question = 0;
            printf("Valor inválido!\n");
        }
    }

    switch (question)
    {
    case 1:
        printf("Linha:\n");
        scanf("%i", &line);
        if (line < 1 || line > 9)
        {
            printf("Valor inválido!\n");
            sudokuMenu(mat);
            break;
        }
        aux = invalidInLine(mat, line - 1);
        printReverse(aux);
        break;
    case 2:
        printf("Coluna:\n");
        scanf("%i", &column);
        if (column < 1 || column > 9)
        {
            printf("Valor inválido!\n");
            sudokuMenu(mat);
            break;
        }
        aux = invalidInColumn(mat, column - 1);
        printReverse(aux);
        break;
    case 3:
        printf("Linha:\n");
        scanf("%i", &line);
        if (line < 1 || line > 9)
        {
            printf("Valor inválido!\n");
            sudokuMenu(mat);
            break;
        }
        printf("Coluna:\n");
        scanf("%i", &column);
        if (column < 1 || column > 9)
        {
            printf("Valor inválido!\n");
            sudokuMenu(mat);
            break;
        }
        aux = invalidInGroup(mat, (line - 1) / 3, (column - 1) / 3);
        printReverse(aux);
        break;
    case 4:
        printf("Linha:\n");
        scanf("%i", &line);
        printf("Coluna:\n");
        scanf("%i", &column);
        printf("Valores possíveis (%ix%i):\n", line, column);
        aux = findMatch(mat, line - 1, column - 1);
        printf("Número de possíveis: %i\n", aux);
        break;
    case 5:
        printf("Linha:\n");
        scanf("%i", &line);
        printf("Coluna:\n");
        scanf("%i", &column);
        printf("Valores não possíveis (%ix%i):\n", line, column);
        findNotMatch(mat, line - 1, column - 1);
        break;
        break;
    default:
        break;
    }
}

int main()
{
    int question = 0;
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
    int value;

    memcpy(solucao, jogoInicial, sizeof(int) * 81);

    printf("Configuracao inicial do jogo:\n");
    showSudoku(solucao);

    sudokuMenu(solucao);

    return 0;
}