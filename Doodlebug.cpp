/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Function definitions for class Doodlebug
*********************************************************************/

#include "Doodlebug.hpp"

/*
 * This is the Doodlebug constructor and takes a row and col for the
 * doodlebug to be placed on and inherits from the Critter class
 * The doodlebug inherits critter's row col and breeding age.
 */
Doodlebug::Doodlebug(int row, int col) : Critter(row, col, 8) {
    starveTime = 0;
}

/*
 * getType will return that the doodlebug is of type bug
 */
Type Doodlebug::getType() {
    return BUG;
}

/*
 * move takes an integer pointer and returns a boolean if the
 * Doodlebug is allowed to move to an adjacent space or if
 * an adjacent space is open for the Doodlebug to move to.
 */
bool Doodlebug::move(int *adjacent) {
    moved = false;
    eat = false;
    int dir = rand() % 4;

    for (int i = 0; i < 4; i++) {           //first check if adjacent cell has an ant
        if (adjacent[i] == ANT) {
            moved = true;
        }
    }

    if (moved) {                            //randomly choose ant and move to ant
        starveTime = 0;                     //reset starve time
        eat = true;
        while (adjacent[dir] != ANT) {
            dir = rand() % 4;
        }
            switch(dir) {
                case NORTH: {
                            row--;
                            break;
                }
                case EAST: {
                             col++;
                             break;
                }
                case SOUTH: {
                            row++;
                            break;
                }
                 case WEST: {
                            col--;
                            break;
                }
            }
    } else {                                //else if no ant is in adjacent cell
        starveTime++;
        if (adjacent[dir] == SPACE) {
            moved = true;

            switch (dir) {
                case NORTH: {
                            row--;
                            break;
                }
                case EAST: {
                            col++;
                            break;
                }
                case SOUTH: {
                            row++;
                            break;
                }
                 case WEST: {
                            col--;
                            break;
                 }
            }
        }
    }

    incrementBreedAge();
    return moved;
}

/*
 * eatAnt will allow the Doodlebug to eat an ant and returns a bool
 */
bool Doodlebug::eatAnt() {
    return eat;
}

/*
 * starved returns a bool depending on if 3 steps is up since a doodlebug
 * has not eaten and returns that the Doodlebug had starved or not
 */
bool Doodlebug::starved() {
    if (starveTime >= 3) {
        return true;
    }
    return false;
}

/*
 * breed is a doodlebug pointer and creates a new bug and sets a row and col
 * for that new baby Doodlebug and resets the breeding age for the existing
 * Doodlebug
 */
Critter *Doodlebug::breed() {                               //breed new bug
    Critter *child = new Doodlebug(childRow, childCol);
    resetBreedAge();
    return child;
}
