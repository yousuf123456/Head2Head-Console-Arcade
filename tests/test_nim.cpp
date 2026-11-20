// tests/test_nim.cpp  -  all Nim tests (NIM-1 to NIM-3)
#include "../utils.h"
#include "../games/games.h"
#include "check.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Functions from the code being tested that are not in any .h file.
// Declaring them here lets the tests call them.
void drawSticks(int left);     // from games/nim.cpp
int readTake(int left, const string& name);    // from games/nim.cpp

// ===== test functions: paste each piece's test function below this line =====
// NIM-1 draw the sticks (check by eye)
void testNIM1() {
    cout << "\n=== NIM-1 ===\n";
    drawSticks(21);
    drawSticks(10);
    drawSticks(1);
    drawSticks(0);
}

int main() {
    srand(time(0));
    int n;
    cout << "Test which piece? (1-3, or 0 for all added so far): ";
    cin >> n;
    // ===== paste each piece's line below this one =====
    if (n == 1 || n == 0) testNIM1();
    return 0;
}