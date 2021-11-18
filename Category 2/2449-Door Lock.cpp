#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(){
    int num_pins;
    int height;
    int counter;


    cin >> num_pins >> height;
    vector<int> pin(num_pins);

    for (auto&& it : pin)
    {
        cin >> it;
        it = it - height;
    }

    counter = 0;
    for (int i = 0; i < num_pins-1; i++)
    {
        counter += abs(pin[i]);
        pin[i+1] -= pin[i];
        pin[i] = 0;
    }
    cout << counter << endl;


    return 0;
}