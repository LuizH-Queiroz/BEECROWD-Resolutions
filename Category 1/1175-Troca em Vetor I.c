#include <stdio.h>

#define AR_SIZE 20 //Tamanho do array


int main(){
    int ar[AR_SIZE];
    int i;


    //Laço para leitura dos dados
    for (i = 0; i < AR_SIZE; i++)
    {
        scanf("%d", &ar[i]);
    }

    //Laço para troca dos valores
    int aux;
    for (i = 0; i < (AR_SIZE / 2); i++)
    {
        aux = ar[i];
        ar[i] = ar[AR_SIZE-(i+1)];
        ar[AR_SIZE-(i+1)] = aux;
    }

    //Laço para printar os valores trocados
    for (i = 0; i < AR_SIZE; i++)
    {
        printf("N[%d] = %d\n", i, ar[i]);
    }


    return 0;
}