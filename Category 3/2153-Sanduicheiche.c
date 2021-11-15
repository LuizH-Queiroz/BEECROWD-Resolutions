#include <stdio.h>
#include <string.h>

#define MAX_STR 32 //Máximo de caracteres das strings (contando com '\n' e '\0')


extern char * Trim(char *str);


int main(){
    char str[MAX_STR];
    char ultimo_char; //Último caractere da string lida
    int pos_repetido; //Posição inicial (índice) da provável parte repetida da palavra
    int i;


    while(fgets(str, MAX_STR, stdin) != NULL)
    {
        Trim(str);

        ultimo_char = str[strlen(str)-1];
        for (i = strlen(str)-2; (i != -1) && (str[i] != ultimo_char); i--);

        if ((i != -1) && (strstr(str, &str[i+1]) != &str[i+1])) //Há uma parte repetida
        {
            if (str[i-1] == str[i]){ //Primeiro e último caractere da parte repetida são iguais
                str[i] = '\0';
            }
            else { //Primeiro e último caractere da parte repetida são diferentes
                str[i+1] = '\0';
            }
        }

        puts(str);
    }



    return 0;
}


char * Trim(char *str){
    if (str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }

    return str;
} 