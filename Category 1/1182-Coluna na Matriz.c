#include <stdio.h>

#define DIMENSAO 12 //Dimensões da matriz


int main(){
    float mat[DIMENSAO][DIMENSAO];
    int coluna;
    char operacao;
    float soma = 0;
    int i, j;


    scanf("%d\n%c", &coluna, &operacao);
    for (i = 0; i < DIMENSAO; i++)
    {
        for (j = 0; j < DIMENSAO; j++)
        {
            scanf("%f", &mat[i][j]);

            if (j == coluna){
                soma += mat[i][j];
            }
        }
    }


    if (operacao == 'S'){
        printf("%.1f\n", soma);
    }
    else {
        printf("%.1f\n", soma / DIMENSAO);
    }


    return 0;
}