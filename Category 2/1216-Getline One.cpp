/*
Mangojata is learning Computer Programming. She finds everything very easy, very simple. She is going
to make a small program that reads the names of your friends and the distance from his home to each of them.
Therefore, she simply want to calculate what is the average distance between her house and her friends
house (in meters). But Aristoclenes, a much more experienced programmer warned her that sometimes what
seems simple can have some details, depending on the programming language used for implementation.

Input
The input contains several test cases. Each test case is composed by two lines. The first line contains
the name of a friend of Mangojata. The second line contains an integer number that indicates the average
distance between Mangojata's house and the house of a friend.

Output
The output must be a number with one digit after the decimal point (please use a double precision variable)
indicating the average distance between Mangojata's house and the house of her friends, like the following
example.

Sample Input	Sample Output
Juca Pivara     160.7
410
Pedro Medario
12
Marta Mandua
60
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main(){
    string name; // Friend's name
    int distance_sum = 0; // Distances sum
    int num_friends = 0; // Number of friends read


    while (getline(cin, name))
    {
        int dist;

        cin >> dist;
        getchar();

        distance_sum += dist;
        num_friends++;
    }

    cout << fixed << setprecision(1) << (double) distance_sum / num_friends << endl;



    return 0;
}