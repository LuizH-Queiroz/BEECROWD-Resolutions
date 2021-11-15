#include <stdio.h>
#include <string.h>

#define MAX_STR 9 //Tamanho máximo das strings (contando com '\n' e '\0')


int main(){
    char sheldon[MAX_STR];
    char raj[MAX_STR];
    char vencedor; //'S' para vitória de Sheldon, 'R' para Raj e 'E' para empate
    int n_testes;
    int i;


    scanf("%d%*c", &n_testes);
    for (i = 1; i <= n_testes; i++)
    {
        scanf("%s %s%*c", sheldon, raj);

        if (strcmp(sheldon, raj) == 0){
            vencedor = 'E';
        }
        else if (strcmp(sheldon, "pedra") == 0)
        {
            if ((strcmp(raj, "lagarto") == 0) || (strcmp(raj, "tesoura") == 0)) vencedor = 'S';
            else vencedor = 'R';
        }
        else if (strcmp(sheldon, "papel") == 0)
        {
            if ((strcmp(raj, "pedra") == 0) || (strcmp(raj, "Spock") == 0)) vencedor = 'S';
            else vencedor = 'R';
        }
        else if (strcmp(sheldon, "tesoura") == 0)
        {
            if ((strcmp(raj, "papel") == 0) || (strcmp(raj, "lagarto") == 0)) vencedor = 'S';
            else vencedor = 'R';
        }
        else if (strcmp(sheldon, "lagarto") == 0)
        {
            if ((strcmp(raj, "Spock") == 0) || (strcmp(raj, "papel") == 0)) vencedor = 'S';
            else vencedor = 'R';
        }
        else if (strcmp(sheldon, "Spock") == 0)
        {
            if ((strcmp(raj, "tesoura") == 0) || (strcmp(raj, "pedra") == 0)) vencedor = 'S';
            else vencedor = 'R';
        }


        printf("Caso #%d: ", i);
        switch (vencedor){
            case 'S':
                puts("Bazinga!");
                break;
            case 'R':
                puts("Raj trapaceou!");
                break;
            default:
                puts("De novo!");
                break;
        }
    }



    return 0;
}