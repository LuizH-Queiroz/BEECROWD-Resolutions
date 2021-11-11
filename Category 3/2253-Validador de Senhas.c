#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


int main(){
    char senha[50];
    bool tem_mauiscula, tem_minuscula, tem_digito;
    bool senha_valida;
    int tamanho;
    int i;


    while (scanf("%[^\n]%*c", senha) != EOF)
    {
        tem_mauiscula = tem_minuscula = tem_digito = false;
        senha_valida = true;
        tamanho = 0;

        for (i = 0; senha[i] != '\0'; i++)
        {
            if (islower(senha[i])){
                tem_minuscula = true;
            }
            else if (isupper(senha[i])){
                tem_mauiscula = true;
            }
            else if (isdigit(senha[i])){
                tem_digito = true;
            }
            else {
                senha_valida = false;
            }

            tamanho++;
        }

        if (!tem_mauiscula || !tem_minuscula || !tem_digito || tamanho < 6 || tamanho > 32){
            senha_valida = false;
        }

        if (senha_valida) {
            puts("Senha valida.");
        }
        else {
            puts("Senha invalida.");
        }
    }



    return 0;
}