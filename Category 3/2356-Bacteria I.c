#include <stdio.h>
#include <string.h>

#define MAX_STR 102 //Tamanho máximo das strings (considerando o '\n' e o '\0')


extern char * Trim(char *str);


int main(){
    char dna[MAX_STR];
    char resistencia[MAX_STR];


    while (fgets(dna, MAX_STR, stdin) != NULL)
    {
        fgets(resistencia, MAX_STR, stdin);
        Trim(dna);
        Trim(resistencia);

        if (strstr(dna, resistencia) != NULL) puts("Resistente");
        else puts("Nao resistente");
    }



    return 0;
}


char * Trim(char *str){
    if (str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }

    return str;
}