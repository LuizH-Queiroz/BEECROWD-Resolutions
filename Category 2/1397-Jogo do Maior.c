#include <stdio.h>

int main(){
    int rodadas; //Quantidade de rodadas
    int jogadorA, jogadorB;
    int pontA, pontB; //Pontuações dos jogadores
    int i;


    while(1)
    {
        scanf("%d", &rodadas);
        if (rodadas == 0){
            break;
        }

        pontA = pontB = 0;
        for (i = 0; i < rodadas; i++)
        {
            scanf("%d %d", &jogadorA, &jogadorB);

            if (jogadorA > jogadorB){
                pontA++;
            }
            else if (jogadorB > jogadorA){
                pontB++;
            }
        }

        printf("%d %d\n", pontA, pontB);
    }


    return 0;
}