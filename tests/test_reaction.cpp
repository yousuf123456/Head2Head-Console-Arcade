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

// RXN-4 progress display (check by eye)
void testRXN4() {
    cout << "\n=== RXN-4 ===\n";
    char combo[2][3] = { {'s','e','a'}, {'k','i','j'} };
    drawProgress("Ali", combo[0], 3, 1);     // [S] [E] [A], 1 of 3 done
    drawProgress("Sara", combo[1], 3, 2);    // [K] [I] [J], 2 of 3 done
}

// RXN-2 waiting phase and false start
void testRXN2() {
    cout << "\n=== RXN-2 ===\n";
    cout << "Test 1: press NOTHING for 3 seconds...\n";
    check("no key pressed -> 0", waitForGo(3000) == 0);

    cout << "Test 2: within 3 seconds press  a  (a Player 1 key)\n";
    check("Player 1 false start -> 1", waitForGo(3000) == 1);

    cout << "Test 3: within 3 seconds press  z  (ignored), then  k\n";
    check("Player 2 false start -> 2", waitForGo(3000) == 2);
}

// RXN-3 race phase
void testRXN3() {
    cout << "\n=== RXN-3 ===\n";
    const char combo[2][3] = { {'s','e','a'}, {'k','i','j'} };

    cout << "Test 1: type  s e a  (Ali's combo)\n";
    check("Ali finishes first -> 1", raceRound(combo, 3, "Ali", "Sara") == 1);

    cout << "Test 2: type  s w  (the wrong w resets Ali), then  k i j\n";
    check("Sara finishes first -> 2", raceRound(combo, 3, "Ali", "Sara") == 2);
}

int main() {
    srand(time(0));
    int n;
    cout << "Test which piece? (1-5, or 0 for all added so far): ";
    cin >> n;
    // ===== paste each piece's line below this one =====

    if (n == 1 || n == 0) testRXN1();
    if (n == 4 || n == 0) testRXN4();
    if (n == 2 || n == 0) testRXN2();
    if (n == 3 || n == 0) testRXN3();

    return 0;
}