#include <stdio.h>

int main(){
    int numTestes;
    int numPresentes, pesoMax;
    int pesoPresente; //Peso de cada presente lido
    int carregando; //Peso que esta no treno no momento
    int viagens; //Quantidade de viagens que serão necessárias
    int i, j; //Para os laços de repetição for


    scanf("%d", &numTestes);
    for (i = 0; i < numTestes; i++)
    {
        scanf("%d %d", &numPresentes, &pesoMax);

        carregando = 0;
        viagens = 0;
        for (j = 0; j < numPresentes; j++)
        {
            scanf("%d", &pesoPresente);

            carregando += pesoPresente;

            if (carregando == pesoMax){
                viagens++;
                carregando = 0;
            }
            else if (carregando > pesoMax){
                viagens++;
                carregando = pesoPresente;
            }
        }


        if (carregando > 0){
            viagens++;
        }
        printf("%d\n", viagens);
    }


    return 0;
}