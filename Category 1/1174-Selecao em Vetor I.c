#include <stdio.h>

#define AR_SIZE 100 //Tamanho do array


int main(){
    float ar[AR_SIZE];
    int i;


    for (i = 0; i < AR_SIZE; i++)
    {
        scanf("%f", &ar[i]);

        if (ar[i] <= 10){
            printf("A[%d] = %.1f\n", i, ar[i]);
        }
    }


    return 0;
}