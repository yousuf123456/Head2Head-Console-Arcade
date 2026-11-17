#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Player {
    string name;
    string pin;
    int points = 0, wins = 0, draws = 0, losses = 0;
    bool isGuest = false;
};

struct Match {
    string date, time, p1, p2, game, winner;   // winner = a username or "draw"
};

// Files paths (kept constant so they are not mistakenly changed in the code)
const string PLAYERS_FILE = "data/players.txt"; 
const string MATCHES_FILE = "data/matches.txt";
const string ADMIN_FILE = "data/admin.txt";
const string WORDS_FILE = "data/words.txt";
const string HANGMAN_WORDS_FILE = "data/hangman_words.txt";


// Game points (kept constant so they are not mistakenly changed in the code)
const int WIN_POINTS = 3, DRAW_POINTS = 1; 


// Game names (kept constant so they are not mistakenly changed in the code)
const string GAME_TIC_TAC_TOE = "Tic-Tac-Toe";
const string GAME_HANGMAN = "Hangman";
const string GAME_NIM = "Nim Sticks";
const string GAME_WORDLE = "Wordle";
const string GAME_GREEDY = "Greedy Roll";
const string GAME_REACTION_DUEL = "Reaction Duel";