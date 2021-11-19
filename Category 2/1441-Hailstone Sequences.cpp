#include <iostream>

using namespace std;


int main(){
    int start;
    int num_sequence;
    int highest_num;


    while (true)
    {
        cin >> start;
        if (start == 0) break;
        highest_num = start;


        while (start != 1){
            if (start % 2 == 0) start = start / 2;
            else start = 3 * start + 1;

            if (start > highest_num) highest_num = start;
        }

        cout << highest_num << endl;
    }



    return 0;
}