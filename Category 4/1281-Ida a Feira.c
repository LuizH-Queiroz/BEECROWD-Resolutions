#include <stdio.h>
#include <string.h>

#define STR_PROD 51 //Tamanho máximo do nome de um produto (incluindo o '\0')


int main(){
    int idas_feira; //Quantidade de idas à feira
    int prod_disponiveis; //Quantidade de produtos disponíveis
    int n_compras; //Quantidade de diferentes produtos que serão comprados a cada ida à feira
    double custo_total; //Custo total de uma ida à feira
    int i, j, k;


    scanf("%d", &idas_feira);
    for (i = 0; i < idas_feira; i++)
    {
        custo_total = 0;

        scanf("%d%*c", &prod_disponiveis);
        char produto[prod_disponiveis][STR_PROD]; //Array que armazena os nomes dos produtos
        double preco[prod_disponiveis]; //Array que armazena os preços dos produtos
        
        for (j = 0; j < prod_disponiveis; j++)
        {
            scanf("%s %lf%*c", produto[j], &preco[j]);
        }


        /* Processamento das compras */
        scanf("%d%*c", &n_compras);
        char compra[STR_PROD]; //Produto que será comprado
        int quantidade; //Quantidade que será comprada do produto

        for (j = 0; j < n_compras; j++)
        {
            scanf("%s %d%*c", compra, &quantidade);

            for (k = 0; k < prod_disponiveis; k++)
            {
                if (strcmp(compra, produto[k]) == 0){
                    custo_total += preco[k] * quantidade;
                    break;
                }
            }
        }

        printf("R$ %.2lf\n", custo_total);
    }



    return 0;
}