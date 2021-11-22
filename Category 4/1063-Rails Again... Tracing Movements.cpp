#include <iostream>
#include <stack>
#include <queue>

using namespace std;


int main(){
    int n_wagons;
    char wagon;
    queue<char> input_train;
    queue<char> output_train;
    stack<char> dead_end;


    while (true)
    {
        cin >> n_wagons;
        cin.ignore();
        if (n_wagons == 0) break;

        for (int i = 0; i < n_wagons; i++)
        {
            cin >> wagon;
            cin.ignore();
            input_train.push(wagon);
        }
        for (int i = 0; i < n_wagons; i++)
        {
            cin >> wagon;
            cin.ignore();
            output_train.push(wagon);
        }

        while (!input_train.empty()) //If input_trainn is empty there's nothing more to insert
        {
            dead_end.push(input_train.front());
            input_train.pop();
            cout << "I";

            //While the last inserted wagon's equal to the next needed output wagon,
            //continue cleaning the structures
            while((!dead_end.empty()) && (dead_end.top() == output_train.front()))
            {
                dead_end.pop();
                output_train.pop();
                cout << "R";
            }
        }

        //If output_train is not empty, not all of the wagons could be arranged
        if (!output_train.empty()) cout << " Impossible";
        cout << endl;

        //Structures cleanup
        while(!dead_end.empty()) dead_end.pop();
        while (!output_train.empty()) output_train.pop();
    }



    return 0;
}