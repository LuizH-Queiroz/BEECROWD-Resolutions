#include <stdio.h>


int main(){
    int n_testes;
    unsigned long long cereal; //Quantia do cereal
    int casas_tab; //Número de casas do tabuleiro que serão utilizadas
    int i, j;


    scanf("%d", &n_testes);
    for (i = 0; i < n_testes; i++)
    {
        scanf("%d", &casas_tab);
        unsigned long long tab[casas_tab]; //Tabuleiro

        tab[0] = 1;
        cereal = 1;
        for (j = 1; j < casas_tab; j++)
        {
            tab[j] = tab[j-1] * 2;
            cereal += tab[j];
        }

        cereal /= 12000; //Conversão do número de grãos para seu peso em kg

        printf("%llu kg\n", cereal);
    }


    return 0;
}