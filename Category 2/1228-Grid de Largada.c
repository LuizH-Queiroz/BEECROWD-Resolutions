#include <stdio.h>


extern int MinUltrapassagens(int, int *, int *);
extern PosicaoEmArray(int *, int, int);


int main(){
    int n_comp; //Numero de competidores em cada caso de teste
    int i;


    while (scanf("%d", &n_comp) != EOF)
    {
        int largada[n_comp];
        int chegada[n_comp];


        for (i = 0; i < n_comp; i++){
            scanf("%d", &largada[i]);
        }
        for (i = 0; i < n_comp; i++){
            scanf("%d", &chegada[i]);
        }


        printf("%d\n", MinUltrapassagens(n_comp, largada, chegada));
    }


    return 0;
}


/**
 * MinUltrapassagens(): Calcula e retorna a quantidade minima de ultrapassagens
 *                      em uma corrida, comparando os grids de largada e de
 *                      chegada.
 * 
 * Parametros:
 * (entrada) n_comp - Quantidade de competidores
 * (entrada e saida) largada[] - Posicoes do grid de largada
 * (entrada) chegada[] - Posicoes da chegada
 * 
 * Retorno: Quantidade minima de ultrapassagens necessarias (valor >= 0)
*/
int MinUltrapassagens(int n_comp, int largada[], int chegada[]){
    int contador = 0; //Conta o número de ultrapassagens
    int aux;
    int i, j;


    int posicao; //Posição do competidor no array de chegada
    for (i = n_comp-2; i >= 0; i--)
    {
        posicao = PosicaoEmArray(chegada, largada[i], n_comp);

        if (posicao > i){

            aux = chegada[posicao];
            for (j = i; j < posicao; j++){
                largada[j] = largada[j+1];
                contador++;
            }
            largada[j] = aux;

            i = n_comp-1; //Para voltar à posição final (ultimo elemento do array de largada),
                            //considerando que "i" ainda sera decrementado no laço for
        }
    }


    return contador;
}


/**
 * PosicaoEmArray(): Encontra a posicao de determinado elemento dentro do array.
 * 
 * Parametros:
 * (entrada) ar[] - Array em que o elemento sera procurado
 * (entrada) procurado - Elemento procurado
 * (entrada) tamArray - Quantidade de elementos do array
 * 
 * Retorno:
 * >= 0 : Se o elemento for encontrado
 * -1 : Se o elemento nao for encontrado 
*/
int PosicaoEmArray(int ar[], int procurado, int tamArray){
    int i;

    for (i = 0; i < tamArray; i++)
    {
        if (ar[i] == procurado){
            return i;
        }
    }

    return -1;
}