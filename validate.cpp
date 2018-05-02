/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Function definitions for validate header
*********************************************************************/
//test
#include "validate.hpp"

/*
 * validate takes an integer for min and a max as parameters and validates if
 * the user input is integer only within the specified min and max
 */
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
