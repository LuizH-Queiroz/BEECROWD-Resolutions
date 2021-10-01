#include <stdio.h>

int main(){
    int tempo, velocidade; //Tempo da viagem e velocidade media
    int dist; //Distacia percorrida
    float gasto; //Gasto de combustivel

    scanf("%d %d", &tempo, &velocidade);
    
    dist = tempo * velocidade;
    gasto = (float) dist / 12;
    
    printf("%.3f\n", gasto);


    return 0;
}