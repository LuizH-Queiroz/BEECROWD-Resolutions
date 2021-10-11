#include <stdio.h>
#include <math.h>


int EhPrimo(int num){
    int contador = 0;
    int i;

    for (i = 1; i <= sqrt(num); i++)
    {
        if (num%i == 0){
            contador++;
            if (contador == 2){
                return 0; //O numero nao eh primo
            }
        }
    }

    return 1; //O numero eh primo
}


int main(){
    int nTestes; //Quantidade de casos de teste
    int numero; //Numero que será avaliado
    int i;


    scanf("%d", &nTestes);
    for (i = 0; i < nTestes; i++)
    {
        scanf("%d", &numero);

        if (EhPrimo(numero)){
            puts("Prime");
        }
        else {
            puts("Not Prime");
        }
    }


    return 0;
}