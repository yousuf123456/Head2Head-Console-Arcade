#include <string>
using namespace std;

void pauseScreen(); // Pauses the program until user presses enter
void clearScreen(); // Clears the console screen
void printHeader(const string& title, int width = 40); // Prints a title with equal signs on both sides, default width is 40

int readInt(const string& prompt, int min, int max);   // asks again until valid
bool readYesNo(const string& prompt);                  // y / n
string readWord(const string& prompt);                 // one word, no spaces

int randomInt(int low, int high);   // input range inclusive
int coinToss();                      // returns 1 or 2
string todayDate();                  // "14-11-2026"
string nowTime();                    // "09:05"