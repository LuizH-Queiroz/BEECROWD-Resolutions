#include <stdio.h>

#define TAM_MAX 102 //Número máximo de caracteres do número (101) mais o caractere nulo (\0)


int main(){
    int testes;
    char numero[TAM_MAX];
    int contador;
    int i, j;


    scanf("%d%*c", &testes);
    for (i = 0; i < testes; i++)
    {
        scanf("%s", numero);

        contador = 0;
        for (j = 0; numero[j] != '\0'; j++)
        {
            switch(numero[j]){
                case '1':
                    contador += 2;
                    break;
                case '7':
                    contador += 3;
                    break;
                case '4':
                    contador += 4;
                    break;
                case '2':
                case '3':
                case '5':
                    contador += 5;
                    break;
                case '0':
                case '6':
                case '9':
                    contador += 6;
                    break;
                case '8':
                    contador += 7;
                    break;
            }
        }

        printf("%d leds\n", contador);
    }



    return 0;
}