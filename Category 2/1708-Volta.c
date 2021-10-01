#include <stdio.h>

int main(){
    int lider, retardatario;
    int volta = 1;
    int dif = 0;

    scanf("%d %d", &lider, &retardatario);
    while(dif < lider)
    {
        dif += retardatario - lider;
        volta++;
    }

    printf("%d\n", volta);


    return 0;
}