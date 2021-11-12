#include <iostream>

using namespace std;


unsigned long long Fibonacci(int posicao, int &chamadas){
    chamadas++;
    
    if (posicao == 0){
        return 0;
    }
    else if (posicao == 1){
        return 1;
    }

    return Fibonacci(posicao-1, chamadas) + Fibonacci(posicao-2, chamadas);
}


int main(){
    int n_testes; //Quantidade de testes
    int posicao; //Posicao da sequência que se deve calcular
    unsigned long long fib; //Número da sequência na posição dada
    int chamadas; //Quantas chamadas recursivas foram feitas


    cin >> n_testes;
    for (int i = 0; i < n_testes; i++)
    {
        cin >> posicao;
        
        chamadas = -1; //Para desconsiderar a primeira incrementação
        fib = Fibonacci(posicao, chamadas);

        cout << "fib(" << posicao << ") = " << chamadas << " calls = " << fib << endl;
    }



    return 0;
}