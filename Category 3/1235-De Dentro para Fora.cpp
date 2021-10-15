#include <iostream>
#include <string>

using namespace std;


int main(){
    string str;
    int n_strings;


    cin >> n_strings;
    cin.ignore();
    for (int i = 0; i < n_strings; i++)
    {
        getline(cin, str);

        for (string::reverse_iterator it = (str.rbegin() + str.size()/2); it != str.rend(); it++)
        {
            cout << *it;
        }

        for (string::reverse_iterator it = str.rbegin(); it != (str.rbegin() + str.size()/2); it++)
        {
            cout << *it;
        }

        cout << "\n";
    }


    return 0;
}