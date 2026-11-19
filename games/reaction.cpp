#include <iostream>
#include "../utils.h"

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