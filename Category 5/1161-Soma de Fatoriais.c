#include <stdio.h>


unsigned long long Fatorial(int num){
    unsigned long long fatorial = 1;
    int i;

    for (i = num; i >= 2; i--)
    {
        fatorial *= i;
    }

    return fatorial;
}


int main(){
    int num_1, num_2;


    while(scanf("%d %d", &num_1, &num_2) != EOF)
    {
        printf("%llu\n", Fatorial(num_1) + Fatorial(num_2));    
    }


    return 0;
}