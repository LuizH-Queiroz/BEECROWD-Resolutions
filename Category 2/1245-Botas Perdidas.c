#include <stdio.h>

#define N_TAMANHOS 31 //Quantidade de diferentes possíveis números (tamanhos) das botas


extern void ZeraArray(int ar[], int tam);


int main(){
    int n_botas; //Número de botas individuais entregues
    int direito[N_TAMANHOS];
    int esquerdo[N_TAMANHOS];
    int tam_bota; //Tamanho da bota lida
    char lado_bota; //Lado da bota lida (esquerdo ou direito)
    int n_paresCorretos; //Número de pares corretos que podem ser formados
    int i;

    /* Considerando um índice 'i' qualquer, o valor de 'direito[i]' ou de 'esquerdo[i]'
    representa quantas botas do tamanho 'i+30' que foram entregues, sendo botas do lado direito
    no primeiro array e botas do lado esquerdo no segundo array. Vale lembrar que como são
    31 tamanhos diferentes, os índices dos arrays vão de 0 a 30  */

    while (scanf("%d", &n_botas) != EOF)
    {
        ZeraArray(direito, N_TAMANHOS);
        ZeraArray(esquerdo, N_TAMANHOS);
        n_paresCorretos = 0;

        for (i = 0; i < n_botas; i++)
        {
            scanf("%d %c", &tam_bota, &lado_bota);

            if (lado_bota == 'D'){
                direito[tam_bota-30]++;
            }
            else {
                esquerdo[tam_bota-30]++;
            }
        }


        for (i = 0; i < N_TAMANHOS; i++)
        {
            if (direito[i] < esquerdo[i]){
                n_paresCorretos += direito[i];
            }
            else {
                n_paresCorretos += esquerdo[i];
            }
        }

        printf("%d\n", n_paresCorretos);
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