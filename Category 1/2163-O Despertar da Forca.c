#include <stdio.h>


extern int EhSabreDeLuz(int posicao_d1, int posicao_d2, int tam_d2, int mat[][tam_d2]);


int main(){
    int linhas, colunas;
    int linha_sabre, coluna_sabre;
    int i, j;


    scanf("%d %d", &linhas, &colunas);
    int mat[linhas][colunas];

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }


    linha_sabre = coluna_sabre = 0;
    int achouSabre = 0;
    for (i = 1; i < (linhas-1); i++)
    {
        for (j = 1; j < (colunas-1); j++)
        {
            if ((mat[i][j] == 42) && EhSabreDeLuz(i, j, colunas, mat)){
                linha_sabre = i + 1;
                coluna_sabre = j + 1;

                achouSabre = 1;
                break;
            }
        }

        if (achouSabre){
            break;
        }
    }


    printf("%d %d\n", linha_sabre, coluna_sabre);


    return 0;
}


int EhSabreDeLuz(int posicao_d1, int posicao_d2, int tam_d2, int mat[][tam_d2]){
    int cont_7 = 0;
    int i, j;

    for (i = posicao_d1-1; i <= posicao_d1+1; i++)
    {
        for (j = posicao_d2-1; j <= posicao_d2+1; j++)
        {
            if (mat[i][j] == 7){
                cont_7++;
            }
        }
    }

    if (cont_7 == 8){
        return 1;
    }
    else {
        return 0;
    }
}