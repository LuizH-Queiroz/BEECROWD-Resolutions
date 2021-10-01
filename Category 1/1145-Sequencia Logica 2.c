#include <stdio.h>

int main(){
    int numPorLinha, numFinal;
    int i, j; //Para os laços de repetição for


    scanf("%d %d", &numPorLinha, &numFinal);
    for (i = 1; i <= numFinal; i++)
    {
        /* Se "i" eh multiplo da quantidade de numeros por linha (numPorLinha),
           entao estamos no ultimo numero da linha */
        if (i % numPorLinha == 0){
            printf("%d\n", i);            
        }
        else {
            printf("%d ", i);
        }
    }


    return 0;
}