/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Function definitions for validate header
*********************************************************************/

#include "validate.hpp"

int validate(int min, int max) {            //function validates the users input, limits input to integer only and a specified max/min value
    int intChoice;
    cin >> intChoice;

    while (cin.fail() || cin.peek() != '\n' || intChoice < min || intChoice > max) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, re-enter integer: ";
        cin >> intChoice;
    }
    return intChoice;
}
