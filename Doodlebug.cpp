/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Function definitions for class Doodlebug
*********************************************************************/

#include "Doodlebug.hpp"

Doodlebug::Doodlebug(int row, int col) : Critter(row, col, 8) {
    starveTime = 0;
}

Type Doodlebug::getType() {
    return BUG;
}

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

bool Doodlebug::eatAnt() {
    return eat;
}

bool Doodlebug::starved() {
    if (starveTime >= 3) {
        return true;
    }
    return false;
}

Critter *Doodlebug::breed() {                               //breed new bug
    Critter *child = new Doodlebug(childRow, childCol);
    resetBreedAge();
    return child;
}
