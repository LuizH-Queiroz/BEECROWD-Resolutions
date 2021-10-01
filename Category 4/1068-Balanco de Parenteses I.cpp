#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main(){
    char c;
    stack<char> pilha;

    while((c = getchar()) != EOF)
    {
        if (c == '('){
            pilha.push(c);
        }
        else if (c == ')'){
            
            if (pilha.empty()){
                cout << "incorrect" << endl;

                //Como ja sabemos que eh incorreto, vamos retirar logo o resto da linha e
                //partir para a proxima
                string str;
                getline(cin, str);
            }
            else {
                pilha.pop();
            }

        }
        else if (c == '\n'){

            if (pilha.empty()){ //Nao ha um '(' sem seu correspondente ')'
                cout << "correct" << endl;
            }
            else { //Sobrou pelo menos um '(' sem um fechamento ')'
                cout << "incorrect" << endl;
                
                while(pilha.empty() == false){
                    pilha.pop();
                }
            }

        }
    }


    return 0;
}