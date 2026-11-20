#include <iostream>
using namespace std;

// The program prints how many sticks are left, then draws them as | marks, 10 per line.
// In: left = number of sticks remaining.  Out: nothing (it only prints).
void drawSticks(int left) {
    cout << "Sticks left: " << left << endl;
    for (int i = 1; i <= left; i++){
        cout << "| ";
        if (i % 10 == 0)
            cout << endl;

    }
    if (left % 10 != 0)
        cout << endl;
}