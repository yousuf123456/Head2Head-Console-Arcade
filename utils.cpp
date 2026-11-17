#include "utils.h"

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

// To use the system("cls") command to clear the console screen
void clearScreen(){
    system("cls");
}


// To pause the program until user presses enter
void pauseScreen(){
    cout << "Press Enter to continue!";

    // When any number is taken input before the pauseScreen() function, the input buffer will have a '\n' character left in it. 
    // This line will ignore that character and wait for the user to press Enter.
    cin.ignore(1000, '\n'); 

    cin.get();
}

// To print a title with equal signs on both sides
void printHeader(const string& title, int width){
    // Calculating the number of equal signs to print on each side of the title
    int side_equals_width = (width - title.length()) / 2; 

    // Printing left side equal signs
    for (int i = 1; i <= side_equals_width; i++){
        cout << "=";
    }

    // Printing the title
    cout << " " << title << " ";

    // Printing right side equal signs
    for (int i = 1; i <= side_equals_width; i++){
        cout << "=";
    }
    
    cout << endl;
}