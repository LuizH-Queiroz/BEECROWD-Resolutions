#include <stdio.h>

int main(){
    int nLinhas;
    int coluna_1, coluna_2, coluna_3;
    int i;


    scanf("%d", &nLinhas);
    nLinhas *= 2;
    coluna_1 = coluna_2 = coluna_3 = 1;
    for (i = 1; i <= nLinhas; i++)
    {
        printf("%d %d %d\n", coluna_1, coluna_2, coluna_3);

        if (i % 2 == 1){ //Linha de numero impar
            coluna_2++;
            coluna_3++;
        }
        else { //Linha de numero par
            coluna_1++;
            coluna_2 += i;
            coluna_3 = coluna_1 * coluna_2;
        }
    }


    return 0;
}