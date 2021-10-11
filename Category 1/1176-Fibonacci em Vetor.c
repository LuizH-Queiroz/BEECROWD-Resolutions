#include <stdio.h>


unsigned long long ElementoFib(int indice){

    if (indice == 0){
        return 0;
    }

    unsigned long long termo_atual = 1;
    unsigned long long termo_1, termo_2 = 0;
    int i;

    for (i = 1; i < indice; i++)
    {
        termo_1 = termo_2;
        termo_2 = termo_atual;
        termo_atual = termo_1 + termo_2;
    }

    return termo_atual;
}


int main(){
    int nTestes;
    int indiceElemento; //Indice do elemento na sequencia de Fib
    int i;


    scanf("%d", &nTestes);
    for (i = 0; i < nTestes; i++)
    {
        scanf("%d", &indiceElemento);

        printf("Fib(%d) = %llu\n", indiceElemento, ElementoFib(indiceElemento));
    }


    return 0;
}