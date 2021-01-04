/*
 *  Trabalho 1 - Passos para resolver o sudoku
 *  Autor:
 *  Data:
 */
#include <stdio.h>

#define TAMANHO 9

void inicializaVetor(int v[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        v[i] = 0;
    }
}

void inicializa3Vetor(int v1[], int v2[], int v3[], int tam)
{
    inicializaVetor(v1, tam);
    inicializaVetor(v2, tam);
    inicializaVetor(v3, tam);
}

void showSudoku(int mat[][TAMANHO])
{
    int i, j;
    printf("\n +-----------+-----------+-----------+\n");
    for (i = 0; i < 9; i++)
    {
        printf(" | ");
        for (j = 0; j < 9; j++)
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

void solveGame(int mat[][TAMANHO])
{

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

    printf("Configuracao inicial do jogo:\n");
    showSudoku(solucao);

    printf("%s", "\nSolução:\n");
    solveGame(solucao);

    return 0;
}