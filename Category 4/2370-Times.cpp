#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool ComparaNome(pair<int, string> a, pair<int, string> b);


int main(){
    int n_alunos;
    int n_times;
    int i;
    vector< pair<int, string> > aluno;
    vector< vector<pair<int, string>> > time;


    cin >> n_alunos >> n_times;
    aluno.resize(n_alunos);
    time.resize(n_times);
    for (auto&& it : aluno)
    {
        cin.ignore();
        cin >> it.second >> it.first;
    }

    sort(aluno.begin(), aluno.end());
    reverse(aluno.begin(), aluno.end());

    i = 0;
    while (!aluno.empty())
    {
        time[i].push_back(aluno.front());
        aluno.erase(aluno.begin());

        if (i == n_times - 1) i = 0;
        else i++;
    }


    for (i = 0; i < n_times; i++)
    {
        sort(time[i].begin(), time[i].end(), ComparaNome);
    }


    for (i = 0; i < n_times; i++)
    {
        cout << "Time " << i + 1 << endl;
        for_each(time[i].begin(), time[i].end(), [](pair<int, string> p){cout << p.second << endl;});
        cout << endl;
    }



    return 0;
}


bool ComparaNome(pair<int, string> a, pair<int, string> b){
    return a.second < b.second;
}