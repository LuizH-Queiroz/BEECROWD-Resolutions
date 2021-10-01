#include <iostream>
#include <queue>

using namespace std;


int main(){
    queue<int> cartas;
    int nCartas;

    while(true)
    {
        cin >> nCartas;
        if (nCartas == 0){
            break;
        }

        //Por conta do restante do laco while, apenas um elemento da fila
        //pode ter sobrado
        if (cartas.empty() == false){
            cartas.pop();
        }        

        for (int i = 1; i <= nCartas; i++)
        {
            cartas.push(i);
        }

        cout << "Discarded cards: ";
        while(cartas.size() > 2)
        {
            cout << cartas.front() << ", ";
            cartas.pop();
            cartas.push(cartas.front());
            cartas.pop();
        }
        cout << cartas.front() << endl; //Ultima carta descartada
        cartas.pop(); //Descartando a penultima carta restante do conjunto


        cout << "Remaining card: " << cartas.front() << endl;
    }


    return 0;
}