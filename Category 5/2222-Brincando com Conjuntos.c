#include <stdio.h>

#define MAX_VAL 60 //Valor mais alto que um conjunto pode ter


extern void ZeraArrayBi(int tam_d1, int tam_d2, int ar[][tam_d2]);
extern int QuantIntersecao(int tam, int conjunto_1[], int conjunto_2[]);
extern int QuantUniao(int tam, int conjunto_1[], int conjunto_2[]);


int main(){
    int n_instancias; //Número de instâncias de teste
    int instancia; //Instância atual
    int n_conjuntos; //Número de conjuntos em um teste
    int tam_conjunto; //Tamanho do conjunto que deve ser lido a seguir
    int valor;
    int i, j;


    scanf("%d", &n_instancias);
    for (instancia = 0; instancia < n_instancias; instancia++)
    {
        scanf("%d", &n_conjuntos);

        int conjunto[n_conjuntos][MAX_VAL+1];
        ZeraArrayBi(n_conjuntos, MAX_VAL+1, conjunto);

        //Leitura dos dados dos conjuntos
        for (i = 0; i < n_conjuntos; i++)
        {
            scanf("%d", &tam_conjunto); //Leitura do tamanho do conjunto
            for (j = 0; j < tam_conjunto; j++) //Leitura dos valores do conjunto
            {
                scanf("%d", &valor);
                conjunto[i][valor]++;
            }
        }


        int n_operacoes; //Número de operações que devem ser feitas em seguida
        int operacao; //Operacao que deve ser realizada
        int conjunto_1, conjunto_2; //Conjuntos que serão analisados
        scanf("%d", &n_operacoes);
        for (i = 0; i < n_operacoes; i++)
        {
            scanf("%d %d %d", &operacao, &conjunto_1, &conjunto_2);

            if (operacao == 1){
                printf("%d\n", QuantIntersecao(MAX_VAL+1, conjunto[conjunto_1-1], conjunto[conjunto_2-1]));
            }
            else {
                printf("%d\n", QuantUniao(MAX_VAL+1, conjunto[conjunto_1-1], conjunto[conjunto_2-1]));
            }
        }
    }


    return 0;
}


void ZeraArrayBi(int tam_d1, int tam_d2, int ar[][tam_d2]){
    int i, j;

    for (i = 0; i < tam_d1; i++)
    {
        for (j = 0; j < tam_d2; j++)
        {
            ar[i][j] = 0;
        }
    }
}


int QuantIntersecao(int tam, int conjunto_1[], int conjunto_2[]){
    int contador = 0;
    int i;

    for (i = 0; i < tam; i++)
    {
        if (conjunto_1[i] && conjunto_2[i]){
            contador++;
        }
    }

    return contador;
}


int QuantUniao(int tam, int conjunto_1[], int conjunto_2[]){
    int contador = 0;
    int i;

    for (i = 0; i < tam; i++)
    {
        if (conjunto_1[i] || conjunto_2[i]){
            contador++;
        }
    }

    return contador;
}