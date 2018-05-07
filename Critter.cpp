/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Function definitions for class Critter
*********************************************************************/

#include "Critter.hpp"

/*
 * Critter constructor takes a row, col, and breed age and sets
 * the attributes that will be inherited by the derived classes
 */
Critter::Critter(int row, int col, int breedReadyAge) {
    this->breedReadyAge = breedReadyAge;
    this->row = row;
    this->col = col;
    this->moved = false;
    this->breedReady = false;
    this->breedAge = 0;
}

/*
 * getRow returns the row
 */
int Critter::getRow() {
    return row;
}

/*
 * getCol returns the column
 */
int Critter::getCol() {
    return col;
}

/*
 * resetMove resets the move for the bug
 */
void Critter::resetMove() {
    moved = false;
}

/*
 * getMoved returns the boolean if the bug has moved or not
 */
bool Critter::getMoved() {
    return moved;
}

/*
 * incrementBreedAge increments breeding age by one and if
 * the age to breed is equal to the breeding age then the
 * breed Ready becomes true. This is true for if the breeding
 * age is equal to the breed ready age
 */
void Critter::incrementBreedAge() {
    breedAge += 1;
    if (breedAge == breedReadyAge) {
        breedReady = true;
    }
}

/*
 * resetBreedAge resets the breeding age back to 0 and
 * sets breedReady to false if it wasn't otherwise
 */
void Critter::resetBreedAge() {
    breedAge = 0;
    breedReady = false;
}

/*
 * getBreedReady returns a boolean if the bug is ready to breed or not
 */
bool Critter::getBreedReady() {
    return breedReady;
}

/*
 * canBreed takes a integer pointer parameter and returns a boolean
 * if the critter can breed or not
 */
bool Critter::canBreed(int *adjacent) {
    int randSeq[4] = {-1, -1, -1, -1};
    bool unique = false;

    for (int i = 0; i < 4; i++) {                       //get a random sequence of 4 values
        while (!unique) {
            unique = true;
            randSeq[i] = rand() % 4;

            for (int j = 0; j < i; j++) {
                if(randSeq[i] == randSeq[j]) {
                    unique = false;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {                   //go through the random sequence
        switch (randSeq[i]) {
            case NORTH: {
                        if (adjacent[0] == SPACE) {
                            childRow = row - 1;
                            childCol = col;
                            return true;
                        }
                        break;
            }
            case EAST: {
                        if (adjacent[1] == SPACE) {
                            childRow = row;
                            childCol = col + 1;
                            return true;
                        }
                        break;
            }
            case SOUTH: {
                        if (adjacent[2] == SPACE) {
                            childRow = row + 1;
                            childCol = col;
                            return true;
                        }
                        break;
            }
            case WEST: {
                        if (adjacent[3] == SPACE) {
                            childRow = row;
                            childCol = col - 1;
                            return true;
                        }
                        break;
            }
        }
    }
    return false;
}

/*
 * destructor for critter
 */
Critter::~Critter(){}
