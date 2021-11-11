#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_RISADA 50 //Máximo de caracteres de uma risada


extern bool EhVogal(char caractere);


int main(){
    char risada[MAX_RISADA];
    char caractere; //Caractere lido
    int finalRisada = 0; //Primeiro índice do array risada[] que não é um caractere lido


    while ((caractere = getchar()) != '\n') //Leitura até o final da linha
    {
        if (EhVogal(caractere)){
            risada[finalRisada] = caractere;
            finalRisada++;
        }
    }


    bool risada_engracada = true;
    int inicioRisada = 0;
    finalRisada--;
    while (inicioRisada < finalRisada)
    {
        if (risada[inicioRisada] != risada[finalRisada]){
            risada_engracada = false;
            break;
        }

        inicioRisada++;
        finalRisada--;
    }

    if (risada_engracada) puts("S");
    else puts("N");



    return 0;
}


bool EhVogal(char caractere){
    char vogal[] = "aeiou";
    int i;
    
    for (i = 0; vogal[i] != '\0'; i++)
    {
        if (caractere == vogal[i]){
            return true;
        }
    }

    return false;
}