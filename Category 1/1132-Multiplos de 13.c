#include <stdio.h>

int main(){
    int num1, num2;
    int menor, maior;
    int soma = 0;
    int i;

    scanf("%d %d", &num1, &num2);
    if (num1 > num2){
        maior = num1;
        menor = num2;
    }
    else {
        maior = num2;
        menor = num1;
    }

    for (i = menor; i <= maior; i++)
    {
        if (i % 13 != 0){
            soma += i;
        }
    }

    printf("%d\n", soma);



    return 0;
}