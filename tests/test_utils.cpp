
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

int main() {
    srand(time(0));
    int n;
    cout << "Test which piece? (1-8, or 0 for all added so far): ";
    cin >> n;
    // ===== paste each piece's line below this one =====

    if (n == 1 || n == 0) testF1();

    return 0;
}