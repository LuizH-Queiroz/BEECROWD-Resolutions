#include <iostream>

using namespace std;


extern void FillArray(int arr[], int size);
extern int Kill(int arr[], int onTrack, int steps);


int main() {
    int tests;
    int num_people, steps;
    int onTrack;

    cin >> tests;
    for (int i = 1; i <= tests; i++)
    {
        cin >> num_people >> steps;
        onTrack = 1;

        int arr[num_people+1]; // +1 because index 0 will not be used
        FillArray(arr, num_people+1); // Every index (arr[index]) will store the index of the next alive person

        // While the next person alive is the same person, there's only one left
        while(arr[onTrack] != onTrack)
        {
            // Kill someone and update person tracked (current)
            onTrack = Kill(arr, onTrack, steps);
        }

        cout << "Case " << i << ": " << onTrack << endl;
    }



    return 0;
}


void FillArray(int arr[], int size) {
    
    for (int i = 1; i < size-1; i++)
    {
        arr[i] = i + 1;
    }
    arr[size-1] = 1;
}


int Kill(int arr[], int onTrack, int steps) {
    int prevAlive, currAlive = onTrack;

    for (int i = steps-1; i > 0; i--)
    {
        prevAlive = currAlive;
        currAlive = arr[currAlive];
    }

    // Since currAlive is no more alive, we need to update the index that points to it,
    // which is arr[prevAlive]
    arr[prevAlive] = arr[currAlive];
    return arr[currAlive]; // First person alive that comes after the killed one
}