#include <stdio.h>

#define MAX_FAT 100 //Número máximo de fatoriais que podem ser armazenados no array de fatoriais


int main(){
    int fatorial[MAX_FAT] = {0}; //Array em que cada índice corresponde a seu fatorial.
                                 //Exemplos:
                                 //fatorial[0] = fatorial[1] = 1! = 1
                                 //fatorial[2] = 2! = 2
                                 //fatorial[3] = 3! = 6
                                 //fatorial[4] = 4! = 24
    int numero;
    int indice;


    scanf("%d", &numero);

    indice = 0;
    fatorial[0] = 1;
    while(fatorial[indice] < numero/2)
    {
        indice++;
        fatorial[indice] = fatorial[indice-1] * indice;
    }


    int contador = 0;
    int soma = 0;
    for (indice; indice >= 0; indice--)
    {
        while (soma + fatorial[indice] <= numero){
            soma += fatorial[indice];
            contador++;
        }
    }
    printf("%d\n", contador);


    return 0;
}