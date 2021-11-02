#include <iostream>
#include <cmath>

using namespace std;


int IndiceCasa(int casa[], int tam, int numeroCasa);


int main(){
    int n_casas;
    int n_encomendas;


    cin >> n_casas >> n_encomendas;

    int casa[n_casas];

    for (int i = 0; i < n_casas; i++)
    {
        cin >> casa[i];
    }


    int ultimaCasa = 0;
    int novaCasa;
    int indice;
    int contador = 0;
    for (int i = 0; i < n_encomendas; i++)
    {
        cin >> novaCasa;

        indice = IndiceCasa(casa, n_casas, novaCasa);
        contador += abs(ultimaCasa - indice);
        ultimaCasa = indice;
    }
    cout << contador << endl;



    return 0;
}


int IndiceCasa(int casa[], int tam, int numeroCasa){
    int inicio = 0;
    int meio;
    int fim = tam - 1;

    while (inicio <= fim)
    {
        meio = (inicio + fim)/2;

        if (casa[meio] == numeroCasa) return meio;
        else if (casa[meio] < numeroCasa) inicio = meio + 1;
        else if (casa[meio] > numeroCasa) fim = meio - 1;
    }
}