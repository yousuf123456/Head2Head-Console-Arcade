
// tests/test_utils.cpp 
#include "../common.h"
#include "../utils.h"
#include "check.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdio>

// ===== test functions: paste each piece's test function below this line =====

void testF1() {
    cout << "\n=== F-1 ===\n";
    Player p;
    check("a new Player starts with 0 points", p.points == 0);
    check("a new Player starts with 0 wins, draws, losses", p.wins == 0 && p.draws == 0 && p.losses == 0);
    check("a new Player is not a guest", p.isGuest == false);

    p.name = "ali";
    p.wins++;
    check("fields can be set and changed", p.name == "ali" && p.wins == 1);

    Match m;
    m.p1 = "ali";
    m.p2 = "sara";
    m.winner = "draw";
    check("a Match holds both players and the winner", m.p1 == "ali" && m.p2 == "sara" && m.winner == "draw");

    check("a win is worth 3 points", WIN_POINTS == 3);
    check("a draw is worth 1 point", DRAW_POINTS == 1);
    check("players file path", PLAYERS_FILE == "data/players.txt");
    check("matches file path", MATCHES_FILE == "data/matches.txt");
}

void testF2() {
    cout << "\n=== F-2 ===\n";
    printHeader("LOBBY");
    printHeader("HEAD-TO-HEAD HISTORY");
    printHeader("A VERY LONG TITLE THAT FILLS THE LINE");

    int n;
    cout << "Type any number and press Enter: ";
    cin >> n;
    pauseScreen();          // must WAIT here until you press Enter again
    clearScreen();
    cout << "The screen was cleared. Test finished.\n";
}

void testF3() {
    cout << "\n=== F-3 ===\n";
    // Type: abc   then  -5   then  99   then  0   then  2
    // Each wrong answer must be refused; only 2 is accepted.
    int n = readInt("Pick 1-4: ", 1, 4);
    check("readInt returned 2 after refusing the wrong inputs", n == 2);

    // Type: maybe   then   Y
    check("readYesNo accepts capital Y as yes", readYesNo("Continue? (y/n): ") == true);

    // Type: n
    check("readYesNo returns false for n", readYesNo("Again? (y/n): ") == false);

    // Type: ali
    check("readWord returns the typed word", readWord("Your name: ") == "ali");
}

void testF4() {
    cout << "\n=== F-4 ===\n";

    bool inRange = true;
    bool seen[7] = {false};          // seen[1]..seen[6]
    for (int i = 0; i < 1000; i++) {
        int r = randomInt(1, 6);
        if (r < 1 || r > 6) inRange = false;
        else seen[r] = true;
    }
    check("randomInt(1, 6) never leaves 1-6", inRange);
    check("randomInt(1, 6) produced every value", seen[1] && seen[2] && seen[3] && seen[4] && seen[5] && seen[6]);

    int toss = coinToss();
    check("coinToss gives 1 or 2", toss == 1 || toss == 2);

    check("date has the form dd-mm-yyyy (10 characters)", todayDate().size() == 10);
    check("time has the form hh:mm (5 characters)", nowTime().size() == 5);
    cout << "Today: " << todayDate() << " " << nowTime() << "\n";
}

// F-5 hand-over screen (check by eye)
void testF5() {
    cout << "\n=== F-5 ===\n";
    // Type: 4
    int secret = readInt("ALI, type your secret pick (1-6): ", 1, 6);
    handOver("SARA", "ALI");     // press Enter when asked
    cout << "If you can still see ALI's secret pick above, the screen was not cleared.\n";
    cout << "(The pick was " << secret << ")\n";
}

int main() {
    srand(time(0));
    int n;
    cout << "Test which piece? (1-8, or 0 for all added so far): ";
    cin >> n;
    // ===== paste each piece's line below this one =====

    if (n == 1 || n == 0) testF1();
    if (n == 2 || n == 0) testF2();
    if (n == 3 || n == 0) testF3();
    if (n == 4 || n == 0) testF4();
    if (n == 5 || n == 0) testF5();


    return 0;
}