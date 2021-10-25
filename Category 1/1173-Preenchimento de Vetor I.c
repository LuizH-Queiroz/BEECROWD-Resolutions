#include <stdio.h>

#define AR_SIZE 10 //Tamanho do array


int main(){
    int ar[AR_SIZE];
    int i;


    scanf("%d", &ar[0]);
    printf("N[0] = %d\n", ar[0]);

    for (i = 1; i < AR_SIZE; i++)
    {
        ar[i] = ar[i-1] * 2;

        printf("N[%d] = %d\n", i, ar[i]);
    }


    return 0;
}