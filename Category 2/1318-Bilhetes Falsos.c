#include <stdio.h>


extern void ZeraArray(int ar[], int tam);


int main(){
    int n_originais; //Número de bilhetes originais
    int n_pessoas; //Número de pessoas na festa
    int num_bilhete; //Número do bilhete lido
    int contador; //Conta quantos bilhetes de número repetido foram achados
    int i;


    while (scanf("%d %d", &n_originais, &n_pessoas))
    {
        if (n_originais == 0){
            break;
        }

        int bilhete[n_originais+1]; //Cada índice representa o número do bilhete, e seu valor
                                    //corresponde à quantidade desse bilhete que foi entregue
        ZeraArray(bilhete, n_originais+1);
        contador = 0;

        for (i = 0; i < n_pessoas; i++)
        {
            scanf("%d", &num_bilhete);

            bilhete[num_bilhete]++;
            if (bilhete[num_bilhete] == 2){
                contador++;
            }
        }

        printf("%d\n", contador);
    }


    return 0;
}


void ZeraArray(int ar[], int tam){
    int i;

    for (i = 0; i < tam; i++)
    {
        ar[i] = 0;
    }
}