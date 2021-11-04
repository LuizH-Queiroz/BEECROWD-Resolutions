#include <stdio.h>

#define MAX_PERGUNTA 100 //Valor máximo de uma pergunta


int main(){
    int perguntas; //Número de perguntas que devem ser lidas a seguir
    int frequente; //Quantidade mínima de repetições para que uma pergunta seja frequente
    int numero; //Numero da pergunta realizada
    int contador; //Conta quantos números serão adicionados como "frequentes"
    int i;


    while (scanf("%d %d", &perguntas, &frequente))
    {
        if (perguntas == 0){
            break;
        }
     
        int repeticoes[MAX_PERGUNTA+1] = {0}; //Cada índice representa uma pergunta, e armazena
                                              //a quantidade de vezes que foi repetida
        contador = 0;

        for (i = 0; i < perguntas; i++)
        {
            scanf("%d", &numero);

            repeticoes[numero]++;
            if (repeticoes[numero] == frequente){
                contador++;
            }
        }

        printf("%d\n", contador);
    }


    return 0;
}