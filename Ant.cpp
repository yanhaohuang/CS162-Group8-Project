/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Function definitions for class Ant
*********************************************************************/

#include "Ant.hpp"

Ant::Ant(int row, int col)  : Critter(row, col, 3) {}

Type Ant::getType() {
    return ANT;
}

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

bool Ant::eatAnt() {
    return false;
}

bool Ant::starved() {
    return false;
}

Critter *Ant::breed() {                             //breed new ant
    Critter *child = new Ant(childRow, childCol);
    resetBreedAge();
    return child;
}
