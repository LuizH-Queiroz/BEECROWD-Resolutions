#include <stdio.h>


int main(){
    int tam; //Tamanho do array
    int menor; //Valor do menor número
    int posicao; //Posição do menor número
    int i;


    scanf("%d", &tam);
    int ar[tam];

    for(i = 0; i < tam; i++)
    {
        scanf("%d", &ar[i]);
    }

    menor = ar[0];
    posicao = 0;
    for (i = 1; i < tam; i++)
    {
        if (ar[i] < menor){
            menor = ar[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);


    return 0;
}