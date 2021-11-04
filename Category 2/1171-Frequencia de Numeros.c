#include <stdio.h>

#define MAX_NUM 2000 //Maior quantidade de números diferentes que pode aparecer


int main(){
    int aparicoes[MAX_NUM+1] = {0}; //Cada indice representa um numero diferente, e o valor do array
                                    //nesse índice é a quantidade de vezes que ele apareceu
    int valor; //Número lido
    int n_num; //Quantidade de números que serão lidos
    int i;


    scanf("%d", &n_num);
    for (i = 0; i < n_num; i++)
    {
        scanf("%d", &valor);
        aparicoes[valor]++;
    }

    for (i = 0; i < (MAX_NUM+1); i++)
    {
        if (aparicoes[i] != 0){
            printf("%d aparece %d vez(es)\n", i, aparicoes[i]);
        }
    }


    return 0;
}