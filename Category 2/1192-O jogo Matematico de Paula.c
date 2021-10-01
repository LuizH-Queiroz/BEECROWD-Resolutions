#include <stdio.h>

int main(){
    int nTestes;
    int digito_1, digito_2;
    char caractere;
    int resultado; //Resultado de cada operacao realizada em um caso de teste
    int i;


    scanf("%d", &nTestes);
    for (i = 0; i < nTestes; i++)
    {
        scanf("%d%c%d", &digito_1, &caractere, &digito_2);

        if (digito_1 == digito_2){
            resultado = digito_1 * digito_2;
        }
        else if (caractere >= 'A' && caractere <= 'Z'){
            resultado = digito_2 - digito_1;
        }
        else {
            resultado = digito_1 + digito_2;
        }

        printf("%d\n", resultado);
    }


    return 0;
}