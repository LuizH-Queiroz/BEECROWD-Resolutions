#include <iostream>
#include <stack>

using namespace std;


void LimparStack(stack<char> *pilha){

    while(!pilha->empty()){
        pilha->pop();
    }
}


int main(){
    int nTestes;
    stack<char> diamantes;
    char caractere;
    int contador;


    cin >> nTestes;
    cin.ignore();
    for (int i = 0; i < nTestes; i++)
    {
        contador = 0;
        while((caractere = getchar()) != '\n')
        {
            if (caractere == '<'){
                diamantes.push(caractere);
            }
            else if (caractere == '>' && !diamantes.empty()) {                
                diamantes.pop();
                contador++;
            }
        }

        cout << contador << endl;
        LimparStack(&diamantes);
    }


    return 0;
}