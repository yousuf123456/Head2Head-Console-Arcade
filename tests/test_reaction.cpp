// tests/test_reaction.cpp  -  all Reaction Duel tests (RXN-1 to RXN-5)
#include "../utils.h"
#include "../games/games.h"
#include "check.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Functions from the code being tested that are not in any .h file.
// Declaring them here lets the tests call them.
void makeCombos(char combo[2][3], int length);    // from games/reaction.cpp
int keyOwner(char key);
int waitForGo(int waitMs);    // from games/reaction.cpp
int raceRound(const char combo[2][3], int length, const string& p1, const string& p2);   // from games/reaction.cpp
void drawProgress(const string& name, const char combo[], int length, int progress);   // from games/reaction.cpp

// ===== test functions: paste each piece's test function below this line =====

// A copy of the key table, so the test can check the combos against it
const char TEST_KEYS[2][6] = { {'q','w','e','a','s','d'}, {'u','i','o','j','k','l'} };

// Column of a key in one row of TEST_KEYS, or -1 if it is not there
int columnOf(char key, int row) {
    for (int c = 0; c < 6; c++)
        if (TEST_KEYS[row][c] == key) return c;
    return -1;
}

// RXN-1 key table and combos
void testRXN1() {
    cout << "\n=== RXN-1 ===\n";
    check("'a' belongs to Player 1", keyOwner('a') == 1);
    check("'q' belongs to Player 1", keyOwner('q') == 1);
    check("'k' belongs to Player 2", keyOwner('k') == 2);
    check("'l' belongs to Player 2", keyOwner('l') == 2);
    check("'z' belongs to nobody", keyOwner('z') == 0);

    bool ownKeys = true, sameColumns = true;
    for (int t = 0; t < 100; t++) {
        char combo[2][3];
        makeCombos(combo, 3);
        for (int i = 0; i < 3; i++) {
            int c1 = columnOf(combo[0][i], 0);
            int c2 = columnOf(combo[1][i], 1);
            if (c1 == -1 || c2 == -1) ownKeys = false;
            if (c1 != c2) sameColumns = false;
        }
    }
    check("combos only use each player's own keys", ownKeys);
    check("both combos always use the same columns", sameColumns);
}

int main() {
    srand(time(0));
    int n;
    cout << "Test which piece? (1-5, or 0 for all added so far): ";
    cin >> n;
    // ===== paste each piece's line below this one =====

    if (n == 1 || n == 0) testRXN1();
    
    return 0;
}