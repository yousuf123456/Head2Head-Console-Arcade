#include "utils.h"

#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

#include <cstdlib>

using namespace std;

// To use the system("cls") command to clear the console screen
void clearScreen(){   
    system("cls");
}

// To pause the program until user presses enter
void pauseScreen(){
    cout << "Press Enter to continue!";

    // Waits till the user presses enter
    cin.get();
}

// title taken as reference for fast and memory efficient execution, no unnecessary copy is made
// To print a title with equal signs on both sides
void printHeader(const string& title, int width ){
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

int readInt(const string& prompt, int min, int max){
    cout << prompt;

    int value;
    cin >> value;

    if(cin.fail() || value < min || value > max){
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ": " << endl;

        cin.clear(); // Clear the error flag on cin so that future I/O operations will work correctly
        cin.ignore(1000, '\n');

        // Recursively call the function again to ask for valid input this time
        readInt(prompt, min, max); 
    } else {
        cin.ignore(1000, '\n'); // Remove the auto newline or unwanted letters character left in the buffer after reading the integer
        cout << "You entered: " << value << endl;
        return value;
    }

    // never reached, just avoid compiler warnings
    return 0;
};

bool readYesNo(const string& prompt){
    cout << prompt;

    char value;

    cin >> value;

    if(cin.fail() || (value != 'y' && value != 'n' && value != 'Y' && value != 'N')){
        cout << "Invalid input. Please enter 'y' or 'n': " << endl;
        cin.clear();

        // To remove the bad input from the input buffer, so it does not interfere with the next input operation
        cin.ignore(1000, '\n'); 

        // Recursively call the function again to ask for valid input this time
        readYesNo(prompt); 
    } else {
        cin.ignore(1000, '\n'); 

        return (value == 'y' || value == 'Y'); // Return true for 'y' or 'Y', false for 'n' or 'N'
    }

    // never reached, just avoid compiler warnings
    return true;
}

string readWord(const string& prompt){
    cout << prompt;

    string value;

    cin >> value;

    if(cin.fail()){
        cout << "Invalid input. Please enter a valid word: " << endl;
        cin.clear();

        // To remove the bad input from the input buffer, so it does not interfere with the next input operation
        cin.ignore(1000, '\n');

        // Recursively call the function again to ask for valid input this time
        readWord(prompt); 
    } else {
        cin.ignore(1000, '\n'); 

        return value;
    }

    // never reached, just avoid compiler warnings
    return "";
}

// Returns random integer between low and high (inclusive)
int randomInt(int low, int high) {
    return low + rand() % (high - low + 1);
}

// Returns either 1 or 2
int coinToss() {
    return randomInt(1, 2);
}

// Returns today's date in DD-MM-YYYY format
string todayDate() {
    time_t now = time(0);
    tm* date = localtime(&now);

    stringstream ss;
    ss << put_time(date, "%d-%m-%Y");

    return ss.str();
}

// Returns current time in HH:MM format
string nowTime() {
    time_t now = time(0);
    tm* t = localtime(&now);

    stringstream ss;
    ss << put_time(t, "%H:%M");

    return ss.str();
}

// Wait and prompt users to pass the keyboard
void handOver(const string& toName, const string& fromName){
    clearScreen();

    cout << endl << "Pass the keyboard to " << toName << ". " << fromName << ", please look away. ";
    pauseScreen(); // Wait for them to press enter

    clearScreen();
}; 
