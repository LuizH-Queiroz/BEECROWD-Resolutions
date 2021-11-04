#include <stdio.h>

#define DIMENSAO 12 //Dimensões da matriz quadrada


int main(){
    float mat[DIMENSAO][DIMENSAO]; // Matriz quadrada
    int linha;
    char operacao;
    float soma = 0;
    int i, j;


    scanf("%d\n%c", &linha, &operacao);
    for (i = 0; i < DIMENSAO; i++)
    {
        for (j = 0; j < DIMENSAO; j++)
        {
            scanf("%f", &mat[i][j]);

            if (i == linha){
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