#include <stdio.h>


extern int QuantNaoTrocam(int *, int);


int main(){
    int casos_teste;
    int n_alunos; //Quantidade de alunos na fila
    int i, j;


    scanf("%d", &casos_teste);
    for (i = 0; i < casos_teste; i++)
    {
        scanf("%d", &n_alunos);
        int fila[n_alunos];

        for (j = 0; j < n_alunos; j++)
        {
            scanf("%d", &fila[j]);
        }

        printf("%d\n", QuantNaoTrocam(fila, n_alunos));
    }


    return 0;
}



int QuantNaoTrocam(int fila[], int quantElem){
    int filaOrganizada[quantElem]; //Fila que sera organizada de forma decrescente das notas
    int i;

    for (i = 0; i < quantElem; i++)
    {
        filaOrganizada[i] = fila[i];
    }

    //Organizacao do array filaOrganizada[] pelo metodo da bolha
    int trocou = 1;
    int aux;
    while (trocou)
    {
        trocou = 0;

        for (i = 0; i < quantElem-1; i++)
        {
            if (filaOrganizada[i] < filaOrganizada[i+1]){
                aux = filaOrganizada[i];
                filaOrganizada[i] = filaOrganizada[i+1];
                filaOrganizada[i+1] = aux;

                trocou = 1;
            }
        }
    }

    //Comparacao dos arrays fila[] e filaOrdenada[]
    int naoTrocaram = 0;
    for (i = 0; i < quantElem; i++)
    {
        if (filaOrganizada[i] == fila[i])
        {
            naoTrocaram++;
        }
    }

    return naoTrocaram;
}