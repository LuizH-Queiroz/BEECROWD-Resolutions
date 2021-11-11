#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int main(){
    int n_elementos; //Quantidade de elementos que serão lidos para o array principal
    int n_testes; //Quantidade de testes (intervalos para analisar)


    cin >> n_elementos >> n_testes;

    long long int numero[n_elementos+1]; //Array que armazenará os números (desconsideraremos o índice 0)
    for_each(numero+1, numero+(n_elementos+1), [](long long int &i){cin >> i;}); //Leitura dos números


    int inicio, final; //Início e final do intervalo que será analisado
    int k_esimo; //k-ésimo menor número que se deseja usar
    long long int gugu, dabriel; //Palpites de Gugu e Dabriel
    for (int i = 0; i < n_testes; i++)
    {
        cin >> inicio >> final >> k_esimo >> gugu >> dabriel;

        long long int intervalo[final - inicio + 2] = {0}; //Lista com os números pertencentes
                                                           //ao intervalo que analisaremos
                                                           //(desconsideraremos o índice 0)

        int indice = 1; //Próximo índice de intervalo[] que receberá um valor
        for (int j = inicio; j <= final; j++) //Atribuição dos números pertencentes ao intervalo
        {
            intervalo[indice] = numero[j];
            indice++;
        }
        sort(intervalo+1, intervalo + (final - inicio + 2)); //Ordenação do intervalo (crescente)

        //Número de vezes que o k-ésimo menor número aparece no intervalo
        int contador = count(intervalo+1, intervalo+(final - inicio + 2), intervalo[k_esimo]);

        //Definição do vencedor (ou empate)
        char vencedor;
        if (abs(contador - gugu) < abs(contador - dabriel)) vencedor = 'G';
        else if (abs(contador - gugu) > abs(contador - dabriel)) vencedor = 'D';
        else vencedor = 'E';

        cout << intervalo[k_esimo] << " " << contador << " " << vencedor << endl;
    }



    return 0;
}