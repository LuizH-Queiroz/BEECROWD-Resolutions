#include <stdio.h>


int main(){
    int contador; // Conta a quantidade de abertura de parênteses '(' na frase, e é
                  // avaliado e/ou decrementado sempre que um fechamento de parênteses
                  // ')' é encontrado
    char caractere;


    contador = 0;
    while ((caractere = getchar()) != EOF)
    {
        if (caractere == '('){ //Abertura de parênteses

            contador++;

        }
        else if (caractere == ')'){ //Fechamento de parênteses

            if (contador > 0){ //Há parênteses que ainda não foram fechados (pelo menos um)
                contador--;
            }
            else { //Não há parênteses para serem fechados (contador == 0)
                puts("incorrect");

                while ((caractere = getchar()) != '\n'); //Leitura do restante da linha de teste
            }

        }
        else if (caractere == '\n'){ //Final de uma linha de teste

            if (contador == 0){ //Todos os parênteses abertos foram fechados
                puts("correct");
            }
            else { //Há pelo menos um parêntese que não foi fechado (contador > 0)
                puts("incorrect");
                contador = 0;
            }

        }
    }


    return 0;
}