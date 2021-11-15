#include <stdio.h>
#include <string.h>

#define MAX_STR 23 //Tamanho máximo das strings (contando com '\n' e '\0')


extern char * Trim(char *str);


int main(){
    char str[MAX_STR];
    int n_palavras;
    int i;


    scanf("%d%*c", &n_palavras);
    for (i = 0; i < n_palavras; i++)
    {
        scanf("%s", str);
        Trim(str);

        if (strlen(str) == 3)
        {
            if (strstr(str, "UR") == str) strcpy(str, "URI");
            else if (strstr(str, "OB") == str) strcpy(str, "OBI");
        }

        printf(str);
        if (i != n_palavras-1) printf(" ");
        else printf("\n");
    }



    return 0;
}


char * Trim(char *str){
    if (str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }

    return str;
}