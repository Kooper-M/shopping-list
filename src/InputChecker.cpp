#include "InputChecker.h"
#include <print>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

double InputChecker::getDoubleInput(const std::string& prompt) {
    double input;
    print("{}", prompt);

    while(!(cin >> input) || (cin.peek() != '\n')) {
        print("Invalid Input, please try again: ");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return input;
}

int InputChecker::getIntInput(const string& prompt) {
    int input;
    print("{}", prompt);

    while(!(cin >> input) || (cin.peek() != '\n'))  {
        print("Invalid Input, please try again: ");
        cin.clear();
        cin.ignore(
            numeric_limits<streamsize>::max(), '\n');
    } 
    return input;
}

string InputChecker::getStringInput(const string& prompt) {
    string input;
    print ("{}", prompt);
    getline(cin >> ws, input);
    return input;
}