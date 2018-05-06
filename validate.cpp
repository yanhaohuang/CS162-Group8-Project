/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Function definitions for validate header
*********************************************************************/
//test
#include "validate.hpp"

using std::string;
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

/*
 * YesOrNoInput is input validation to determine if the choice is yes or no (Y/N).
 */
bool YesOrNoInput()
{
    string str = "";
    char letter = ' ';
    bool cont = true;
    cin.ignore();
    while (cont) {
        cout << "Enter Y for Yes or N for No" << endl;
        getline(cin, str);
        std::stringstream ss(str); //enter Y or N
        if (ss >> letter && !(ss >> str) && (letter == 'Y' || letter == 'y' || letter == 'N' || letter == 'n')) {
            if (letter == 'y' || letter == 'Y') { //if choice is yes
                cout << "You entered " << letter << ". Continue with program" << endl;
                return true;
            } else if (letter == 'n' || letter == 'N') { //if choice is no
                cout << "You entered " << letter << ". Continue selecting normally" << endl;
                return false;
            }
        }
        else
        {
            cout << "Please enter Y or N to continue" << endl;
        }
    }
    return true;
}
