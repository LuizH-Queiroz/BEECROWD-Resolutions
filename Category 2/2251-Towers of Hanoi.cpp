/*
The puzzle Towers of Hanoi is very old and known, consisting of a set of N disks of different sizes
and three vertical pins, in which the disks can be fitted.


Each pin may contain a stack with any number of disks, since each disk is not placed above
the other smaller sized disc. The initial configuration consists of all disks on pin 1. The aim of
the puzzle is to move all disks to one of the other pins, always obeying the restriction not put a disc
on another smaller.

An algorithm to solve this problem is the following.

procedure Hanoi(N, Orig, Dest, Temp)

   if N = 1 so

      move the smaller disc Orig pin for pin Dest;

   if no

      Hanoi(N-1, Orig, Temp, Dest);

      moving the Nth lower disc Src Dest pin for pin;

      Hanoi(N-1, Temp, Dest, Orig);

   end-if

end

Your task is to write a program to determine how many moves to change a disk from a pin to
the other will be executed by the above algorithm to solve the puzzle.

Input
The input has multiple test sets. Each test set consists of a single line containing a
single integer N (0 ≤ N ≤ 30), indicating the number of disks. The end of input is indicated by N = 0.

Output
For each test set, your program must write three lines in the output. The first line should contain
a test set identifier in the format "Teste n", where n is sequentially numbered from 1. The second line
should contain the number of movements that are performed by the given algorithm to solve the problem of
Torres Hanoi with N disks. The third line should be left blank. The spelling shown in Example output below
should be followed strictly.
*/

#include <iostream>

using namespace std;


int Hanoi(int n) {
    static int moves[31] = {0};

    if (n == 0) return 0;
    else if (moves[n] > 0) return moves[n];

    moves[n] += Hanoi(n-1); // Move n-1 disks from origin pin to auxiliary pin
    moves[n]++; // Move the last disk from origin pin to the destination pin
    moves[n] += Hanoi(n-1); // Move all the n-1 disks from auxiliary pin to the destination pin

    return moves[n];
}


int main() {
    int disks;
    int test = 1;


    while(true)
    {
        cin >> disks;
        if (disks == 0) break;

        cout << "Teste " << test++ << endl;
        cout << Hanoi(disks) << endl; // It can also be done using the formula: (int) pow(2, disks) - 1,
                                      // but I decided to use a recursive funtion
        cout << endl;
    }


    return 0;
}