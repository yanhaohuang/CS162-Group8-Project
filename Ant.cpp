/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Function definitions for class Ant
*********************************************************************/

#include "Ant.hpp"

/*
 * Ant constructor taking a row and col as parameters and inherits
 * the values of the row from Critter base class as well as breeding
 * ready age of 3
 */
Ant::Ant(int row, int col)  : Critter(row, col, 3) {}

/*
 * getType returns the type of the critter is Ant
 */
Type Ant::getType() {
    return ANT;
}

/*
 * move takes an integer pointer called adjacent and returns
 * true if the ant is able to move to a respective space. It then
 * increments the breeding age and returns true for moved if possible
 */
bool Ant::move(int *adjacent) {
    int dir = rand() % 4;

    if(adjacent[dir] == SPACE) {
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

        moved = true;
    }

    incrementBreedAge();
    return moved;
}

/*
 * eatAnt determines if the ant can eat and in this case it can't eat
 */
bool Ant::eatAnt() {
    return false;
}

/*
 * starved determines if the ant starved or not but in this case ants do not starve
 */
bool Ant::starved() {
    return false;
}

/*
 * breed is a pointer to an ant critter and allows the ant to
 * breed and create a baby ant using a row and col set for the new
 * ant and resets the breeding age
 */
Critter *Ant::breed() {                             //breed new ant
    Critter *child = new Ant(childRow, childCol);
    resetBreedAge();
    return child;
}
