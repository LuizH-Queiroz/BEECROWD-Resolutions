#include <stdio.h>
#include <string.h>

#define TOTAL_POMEKONS 151
#define MAX_NOME 1001 //Tamanho máximo do nome de um pomekon (incluindo o '\0')


extern void StrsVazias(int tam_d1, int tam_d2, char str[][tam_d2]);


int main(){
    int n_capturados; //Quantidade de pomekons capturados
    char lista[TOTAL_POMEKONS][MAX_NOME]; //Lista de pomekons capturados (sem repetição de pomekons)
    char pomekon[MAX_NOME]; //Pomekon lido
    int contador; //Conta a quantidade de pomekons capturados que não são repetidos
    int i, j;


    StrsVazias(TOTAL_POMEKONS, MAX_NOME, lista);

    contador = 0;
    scanf("%d%*c", &n_capturados);
    for (i = 0; i < n_capturados; i++)
    {
        scanf("%s", pomekon);

        for (j = 0; j < TOTAL_POMEKONS; j++)
        {
            if (lista[j][0] == '\0'){ //Pomekon ainda não está na lista
                strcpy(lista[j], pomekon);
                contador++;
                break;
            }
            else if (strcmp(lista[j], pomekon) == 0){ //Pomekon já está na lista
                break;
            }
        }
    }

    printf("Falta(m) %d pomekon(s).\n", TOTAL_POMEKONS - contador);



    return 0;
}


void StrsVazias(int tam_d1, int tam_d2, char str[][tam_d2]){
    int i;

    for (i = 0; i < tam_d1; i++)
    {
        str[i][0] = '\0';
    }
}