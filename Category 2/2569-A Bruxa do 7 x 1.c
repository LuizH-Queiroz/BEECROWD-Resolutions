#include <stdio.h>
#include <string.h>

#define MAX_NUM 6 //Tamanho máximo de um número (incluindo o '\0')


extern void RetiraSete(char *str);


int main(){
    char num_1[MAX_NUM], num_2[MAX_NUM];
    char operador;
    char resultado[10]; //Resultado da operação, que terá valor máximo 10000*10000 = 100000000 (ou 10^8)


    scanf("%s %c %s", num_1, &operador, num_2);
    RetiraSete(num_1);
    RetiraSete(num_2);

    switch (operador){
        case '+':
            sprintf(resultado, "%d", atoi(num_1) + atoi(num_2));
            break;
        case 'x':
            sprintf(resultado, "%d", atoi(num_1) * atoi(num_2));
            break;
    }

    RetiraSete(resultado);
    printf("%d\n", atoi(resultado));



    return 0;
}


void RetiraSete(char *str){
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '7'){
            str[i] = '0';
        }
    }
}