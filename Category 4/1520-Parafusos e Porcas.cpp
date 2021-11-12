#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int MenorIndiceNumero(vector<int> &vec, int procurado);
int MaiorIndiceNumero(vector<int> &vec, int procurado);


int main(){
    int caixas; //Quantidade de caixas que serão lidas
    pair<int, int> intervalo; //Intervalo dos parafusos que cada caixa possui
    vector<int> parafuso; //Vector que armazena os parafusos
    pair<int, int> encontrado; //Menor e maior índices do parafuso que se deseja encontrar
    int procurado; //Parafuso procurado


    while (cin >> caixas)
    {
        for (int i = 0; i < caixas; i++)
        {
            cin >> intervalo.first >> intervalo.second;

            for (int j = intervalo.first; j <= intervalo.second; j++)
            {
                parafuso.push_back(j);
            }
        }
        sort(parafuso.begin(), parafuso.end());

        cin >> procurado;

        encontrado.first = MenorIndiceNumero(parafuso, procurado);
        encontrado.second = MaiorIndiceNumero(parafuso, procurado);

        if (encontrado.first != -1) {
            cout << procurado << " found from " << encontrado.first << " to " << encontrado.second << endl;
        }
        else {
            cout << procurado << " not found" << endl;
        }

        parafuso.clear(); //Limpeza do vector
    }



    return 0;
}


/**
 * MenorIndiceNumero(): Usa busca binária para encontrar o menor índice em que um determinado
 *                      número está no vector.
 * 
 * Parâmetros:
 * &vec - vector com os números
 * procurado - Número procurado
 * 
 * Retorno:
 * >= 0 :: Menor índice em que "procurado" está (caso seja encontrado)
 * -1 :: Caso o número não seja encontrado
 * 
 * Nota: Pelo fato de usar busca binária, essa função presume que o vector
 *       está ordenado (de forma crescente).
*/
int MenorIndiceNumero(vector<int> &vec, int procurado){
    int inicio = 0;
    int fim = vec.size() - 1;
    int meio;
    int menor_indice = -1;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (vec[meio] == procurado){
            menor_indice = meio;
            fim = meio - 1;
        }
        else if (vec[meio] < procurado) inicio = meio + 1;
        else if (vec[meio] > procurado) fim = meio - 1;
    }


    return menor_indice;
}


/**
 * MaiorIndiceNumero(): Usa busca binária para encontrar o maior índice em que um determinado
 *                      número está no vector.
 * 
 * Parâmetros:
 * &vec - vector com os números
 * procurado - Número procurado
 * 
 * Retorno:
 * >= 0 :: Maior índice em que "procurado" está (caso seja encontrado)
 * -1 :: Caso o número não seja encontrado
 * 
 * Nota: Pelo fato de usar busca binária, essa função presume que o vector
 *       está ordenado (de forma crescente).
*/
int MaiorIndiceNumero(vector<int> &vec, int procurado){
    int inicio = 0;
    int fim = vec.size() - 1;
    int meio;
    int maior_indice = -1;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (vec[meio] == procurado){
            maior_indice = meio;
            inicio = meio + 1;
        }
        else if (vec[meio] < procurado) inicio = meio + 1;
        else if (vec[meio] > procurado) fim = meio - 1;
    }


    return maior_indice;
}