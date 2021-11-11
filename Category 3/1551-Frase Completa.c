#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_CARACT 1000 //Máximo de caracteres em uma linha
#define TAM_ALF 26 //Quantidade de letras no alfabeto


int main(){
    char frase[MAX_CARACT+1]; //+1 para incluir o '\0'
    int n_frases;
    int contador; //Conta a quantidade de letras do alfabeto presentes na frase
    int i, j;


    scanf("%d%*c", &n_frases);
    for (i = 0; i < n_frases; i++)
    {
        scanf("%[^\n]%*c", frase);

        bool tem_letra[TAM_ALF] = {false}; //Cada índice representa uma letra do alfabeto, e o valor
                                           //(true ou false) indica se a letra está ou não na frase,
                                           //sendo tem_letra[0] a letra 'a' e tem_letra[TAM_ALF-1] a letra 'z'

        for (j = 0; frase[j] != '\0'; j++)
        {
            if (isalpha(frase[j])){
                tem_letra[tolower(frase[j]) - 'a'] = true;
            }
        }

        contador = 0;
        for (j = 0; j < TAM_ALF; j++)
        {
            if (tem_letra[j]) contador++;
        }

        if (contador == TAM_ALF) puts("frase completa");
        else if (contador >= TAM_ALF/2) puts("frase quase completa");
        else puts("frase mal elaborada");
    }



    return 0;
}