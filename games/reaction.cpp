#include <iostream>

#include "../utils.h"

#include <conio.h>
#include <chrono>
#include <thread>
#include <cctype>

#include "games.h"


const int NUMBER_OF_POSSIBLE_KEYS = 6;
const char KEYS[2][6] = { {'q','w','e','a','s','d'},     // row 0 = Player 1
{'u','i','o','j','k','l'} };   // row 1 = Player 2


// To generate different key combinations to press for each player
void makeCombos(char combo[2][3], int length) {
    for(int i = 0; i < length; i++){
        int random_index = randomInt(0, NUMBER_OF_POSSIBLE_KEYS - 1);

        combo[0][i] = KEYS[0][random_index];
        combo[1][i] = KEYS[1][random_index];
    }

}

// To check the pressed key if of ehich player
// Return 1 (if key is of player 1)
// Returns 2 (if key is of player 2)
// Returns 0 (if the key not belongs to any player)

int keyOwner(char key) {
    // Outer loop for the rows (players)
    for(int i = 0; i < size(KEYS); i++){

        // Inner loop for the keys of each player
        for(int j = 0; j < size(KEYS[i]); j++){
            // i = 0 for player 1, i = 1 for player 2, so we return i + 1
            if(key == KEYS[i][j]) return i + 1; 
        }
    }
    
    return 0;
}


// To show how many keys have they pressed right and how many keys are left to press
void drawProgress(const string& name, const char combo[], int length, int progress) {

    cout << name << "\t";

    for (int j = 0; j < length;  j++){
        // Converting the lowercase letters to uppercase letters for better visibility
        // toupper returns ASCII value of the uppercase letter, so we need to convert it back to char
        cout << "[" << char(toupper(combo[j])) << "] ";
    }

    cout << "\t done " << progress << "/" << length << endl;
}


// Calculate the elapsed time in ms from the starting time
int elapsedTimeInMs(chrono::steady_clock::time_point start) {
    return chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count();
}


// Waits for the round to start
int waitForGo(int waitMs) {
    // To clear any previous pressed key value from the buffer, so it doesn't affect the current round
    // cin.ignore() is also used, but it blocks program till a key is pressed then clears it from the buffer 
    while(_kbhit()) _getch(); 

    auto start = chrono::steady_clock::now();

    while (elapsedTimeInMs(start) < waitMs) {
        if (_kbhit()) {
            // tolower function returns the ASCII equivalent value of the charecter
            char key = char(tolower(_getch()));
            int owner = keyOwner(key);

            // Means if not zero, then it is either 1 or 2,
            // which means the key belongs to one of the players, so we return from the function
            if(owner) return owner;
        }

        // Pauses the loop for 5ms to avoid running loop millions of time in few seconds.
        this_thread::sleep_for(chrono::milliseconds(5));
    }

    return 0;
}

// Starts a race round, returns the winner player (1 or 2)
int raceRound(const char combo[2][3], int length, const string& p1, const string& p2) {
    int p1_progress = 0;
    int p2_progress = 0;

    drawProgress(p1, combo[0], length, p1_progress);
    drawProgress(p2, combo[1], length, p2_progress);

    // loop: read a key, whose?  right next key -> +1, wrong -> 0
    //       redraw; finished? return that player
    while(true){
        if(p1_progress == length) return 1;
        if(p2_progress == length) return 2;

        if(_kbhit()){
            char key = char(tolower(_getch()));

            int key_owner = keyOwner(key);

            if(key_owner == 1) {
                bool is_right_key_pressed = key == combo[0][p1_progress];

                if (is_right_key_pressed) p1_progress++;
                else p1_progress = 0;

                clearScreen();
                drawProgress(p1, combo[0], length, p1_progress);
                drawProgress(p2, combo[1], length, p2_progress);
            }

            if (key_owner == 2) {
                bool is_right_key_pressed = key == combo[1][p2_progress];

                if (is_right_key_pressed) p2_progress++;
                else p2_progress = 0;

                clearScreen();
                drawProgress(p1, combo[0], length, p1_progress);
                drawProgress(p2, combo[1], length, p2_progress);
            }
        }
    }

}