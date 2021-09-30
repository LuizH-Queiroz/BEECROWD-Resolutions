#include <stdio.h>
#include <math.h>

int main(){
    int nTestes; //Quantidade de casos de teste
    int numero; //Numero que será avaliado
    int achouDivisor;
    int i, j;


    scanf("%d", &nTestes);
    for (i = 0; i < nTestes; i++)
    {
        scanf("%d", &numero);

        if (numero == 1){
            puts("Not Prime");
            continue;
        }

        achouDivisor = 0;
        for (j = 2; j <= sqrt(numero); j++)
        {
            if (numero % j == 0){
                achouDivisor = 1;
                break;
            }
        }

        if (achouDivisor){
            puts("Not Prime");
        }
        else {
            puts("Prime");
        }
    }


    return 0;
}