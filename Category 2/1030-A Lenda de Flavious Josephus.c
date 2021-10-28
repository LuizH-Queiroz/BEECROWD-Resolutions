#include <stdio.h>
#include <stdbool.h>


extern void PreencheTrue(bool ar[], int tam);
extern int UltimoVivo(bool vivo[], int salto,  int n_pessoas);
extern int ProximoMorrer(bool vivo[], int n_pessoas, int posicao, int faltaPular);


int main(){
    int n_testes; //Número de testes
    int n_pessoas; //Quantidade de pessoas em cada teste
    int salto; //Quantos saltos terão até a próxima morte
    int i;


    scanf("%d", &n_testes);
    for (i = 1; i <= n_testes; i++)
    {
        scanf("%d %d", &n_pessoas, &salto);
        bool vivo[n_pessoas+1]; // Um índice de valor 'true' indica que a pessoa em determinada posição
                                // está viva. O array tem tamanho 'n_pessoas + 1' para que consideremos
                                // a primeira pessoa como estando no índice 1, não no índice 0.
        PreencheTrue(vivo, n_pessoas+1);

        printf("Case %d: %d\n", i, UltimoVivo(vivo, salto, n_pessoas+1));
    }


    return 0;
}


/**
 * PreencheTrue(): Atribui 'true' a todos os elementos de um array de valores booleanos.
 * 
 * Parâmetros:
 * (entrada e saida) ar[] - Array que sera editado
 * (entrada) tam - Tamanho do array (quantidade de elementos)
 * 
 * retorno: void.
*/
void PreencheTrue(bool ar[], int tam){
    int i;

    for (i = 0; i < tam; i++)
    {
        ar[i] = true;
    }
}


/**
 * UltimoVivo(): Encontra o último sobrevivente do grupo, de acordo com o array de
 *               vivos, seu tamanho e o número de pulos para cada morte.
 * 
 * Parâmetros:
 * (entrada e saída) vivo[] - Array que informa se determinada pessoa está viva
 * (entrada) salto - Quantidade de pulos necessários para definir o próximo que deve morrer
 * (entrada) n_pessoas - Quantidade de pessoas no grupo
 * 
 * Retorno: Um valor inteiro >= 1 correspondente ao índice do sobrevivente no
 *          array vivo[].
*/
int UltimoVivo(bool vivo[], int salto, int n_pessoas){
    int quantVivos = n_pessoas-1; //O valor é reduzido em um porque o índice 0 é desconsiderado

    int sobrevivente = (1 + (n_pessoas-1)) * (n_pessoas-1) / 2; /* O valor dessa variável será
    decrementado sempre que alguém morrer, e o valor que lhe será reduzido será o índice daquele
    que morreu. Dessa forma, no final sobrará apenas o valor do índice do único sobrevivente */
    
    int i = ProximoMorrer(vivo, n_pessoas, 0, salto);


    while (quantVivos > 1)
    {
        vivo[i] = false;
        sobrevivente -= i;
        quantVivos--;
        i = ProximoMorrer(vivo, n_pessoas, i, salto);
    }


    return sobrevivente;
}


/**
 * ProximoMorrer(): Procura o índice da próxima pessoa que deve morrer.
 * 
 * Parâmetros:
 * vivo[] - Array que será consultado para contagem de pulos
 * n_pessoas - Quantidade de pessoas (no array)
 * posicao - Posicao da última pessoa que morreu
 * faltaPular - Contabiliza quantos pulos ainda faltam para chegar na próxima morte
 * 
 * Retorno:
 * > 0 : Índice da próxima passeo que deve morrer
*/
int ProximoMorrer(bool vivo[], int n_pessoas, int posicao, int faltaPular){

    while (faltaPular)
    {
        if (posicao + 1 < n_pessoas){
            posicao++;
        }
        else {
            posicao = 1;
        }

        if (vivo[posicao]){
            faltaPular--;
        }
    }

    return posicao;
}