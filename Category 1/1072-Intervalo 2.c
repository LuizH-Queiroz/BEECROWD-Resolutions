#include <stdio.h>

int main(){
    int quant;
    int num;
    int in = 0, out = 0;
    int i;

    scanf("%d", &quant);
    for (i = 0; i < quant; i++)
    {
        scanf("%d", &num);

        if (num >= 10 && num <= 20){
            in++;
        }
        else {
            out++;
        }
    }

    printf("%d in\n", in);
    printf("%d out\n", out);


    return 0;
}