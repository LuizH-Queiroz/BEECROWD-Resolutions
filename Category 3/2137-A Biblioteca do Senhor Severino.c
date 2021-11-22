#include <stdio.h>
#include <string.h>

#define TAM_CODIGO 5 //Tamanho dos códigos dos livros (incluindo o '\0')


extern void OrgazinaPorCodigo(int n_livros, int tam_codigo, char livro[][tam_codigo]);


int main(){
    int n_livros;
    int i;


    while (scanf("%d", &n_livros) != EOF)
    {
        char livro[n_livros][TAM_CODIGO];

        for (i = 0; i < n_livros; i++)
        {
            scanf("%s", &livro[i]);
        }

        OrgazinaPorCodigo(n_livros, TAM_CODIGO, livro);

        for (i = 0; i < n_livros; i++)
        {
            printf("%s\n", livro[i]);
        }
    }



    return 0;
}


void OrgazinaPorCodigo(int n_livros, int tam_codigo, char livro[][tam_codigo]){
    int trocou;
    char aux[tam_codigo];
    int i;


    do {
        trocou = 0;

        for (i = 0; i < n_livros-1; i++)
        {
            if (strcmp(livro[i], livro[i+1]) > 0){
                strcpy(aux, livro[i]);
                strcpy(livro[i], livro[i+1]);
                strcpy(livro[i+1], aux);

                trocou = 1;
            }
        }

    }while(trocou); 
}