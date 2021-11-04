#include <stdio.h>


int main(){
    int n_num; //Quantidade de números da lista
    int numero; //Numero lido
    int multiplo[6] = {0}; //Conta a quantidade de múltiplos na lista (todos os valores começam com 0)
    int i, j;


    scanf("%d", &n_num);

    for (i = 0; i < n_num; i++)
    {
        scanf("%d", &numero);

        for (j = 2; j <= 5; j++)
        {
            if (numero % j == 0){
                multiplo[j]++;
            }    
        }
    }

    for (i = 2; i <= 5; i++){
        printf("%d Multiplo(s) de %d\n", multiplo[i], i);
    }


    return 0;
}