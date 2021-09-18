#include <stdio.h>

int main(){
    int num;
    int maior, pos;
    int i;

    scanf("%d", &num);
    maior = num;
    pos = 1;
    for (i = 2; i <= 100; i++)
    {
        scanf("%d", &num);

        if (num > maior){
            maior = num;
            pos = i;
        }
    }

    printf("%d\n", maior);
    printf("%d\n", pos);



    return 0;
}