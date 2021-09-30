#include <stdio.h>

int main(){
    int nTestes; //Numero de casos de teste
    int popA, popB; //População inicial das cidades
    double percentA, percentB; //Taxa de crescimento das cidades
    int contador; //Conta a quantidade de anos
    int i;


    scanf("%d", &nTestes);
    for (i = 0; i < nTestes; i++)
    {
        scanf("%d %d %lf %lf", &popA, &popB, &percentA, &percentB);

        contador = 0;
        while(popA <= popB && contador <= 100)
        {
            /* As porcentagens devem ser divididas por cem, pois 1% = 1/100,
               10% = 10/100, e assim por diante */
            popA += popA * (percentA/100); 
            popB += popB * (percentB/100);

            contador++;
        }

        if (contador <= 100){
            printf("%d anos.\n", contador);
        }
        else {
            puts("Mais de 1 seculo.");
        }
    }


    return 0;
}