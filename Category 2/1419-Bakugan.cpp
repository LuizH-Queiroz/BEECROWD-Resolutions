#include <iostream>
#include <vector>

#define BONUS 30

using namespace std;


int SequenceIndex(vector<int> &vec);


int main(){
    int rounds;
    int mark_points, mark_index;
    int leti_points, leti_index;
    vector<int> bakugan;


    while (true)
    {
        cin >> rounds;
        if (rounds == 0) break;

        bakugan.resize(rounds);
        mark_points = leti_points = 0;

        for (auto&& it : bakugan) //Mark bakugans
        {
            cin >> it;
            mark_points += it;
        }
        mark_index = SequenceIndex(bakugan);


        for (auto&& it : bakugan) //Leti bakugans
        {
            cin >> it;
            leti_points += it;
        }
        leti_index = SequenceIndex(bakugan);


        if (mark_index != -1 && leti_index != -1)
        {
            if (mark_index < leti_index) mark_points += BONUS;
            else if (leti_index < mark_index) leti_points += BONUS;
        }
        else if (mark_index != -1) mark_points += BONUS;
        else if (leti_index != -1) leti_points += BONUS;


        if (mark_points > leti_points) cout << 'M' << endl;
        else if (leti_points > mark_points) cout << 'L' << endl;
        else cout << 'T' << endl;

        bakugan.clear();
    }



    return 0;
}


int SequenceIndex(vector<int> &vec){

    for (int i = 0; i < vec.size() - 2; i++)
    {
        if (vec[i] == vec[i+1] && vec[i+1] == vec[i+2]){
            return i;
        }
    }

    return -1;
}