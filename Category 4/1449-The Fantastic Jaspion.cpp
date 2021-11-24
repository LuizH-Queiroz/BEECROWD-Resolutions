#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(){
    int instances;
    int num_words, song_lines;
    map<string, string> translate;
    string word, meaning;


    cin >> instances;
    for (int i = 0; i < instances; i++)
    {
        cin >> num_words >> song_lines;
        cin.ignore();

        for (int j = 0; j < num_words; j++)
        {
            getline(cin, word);
            getline(cin, meaning);

            translate[word] = meaning;
        }

        for (int j = 0; j < song_lines; j++)
        {
            while(true)
            {
                cin >> word;

                if (translate[word] == ""){
                    cout << word;
                }
                else cout << translate[word];


                if (cin.get() == '\n'){
                    cout << endl;
                    break;
                }
                else cout << " ";
            }
        }
        cout << endl;


        translate.clear();
    }



    return 0;
}