// tests/check.h  -  shared helper used by every test file
#pragma once
#include <iostream>
#include <string>
using namespace std;

// Prints PASS or FAIL for one check.
// "inline" lets a function live inside a .h file that several files include.
inline void check(const string& what, bool ok) {
    cout << (ok ? "PASS  " : "FAIL  ") << what << "\n";
}