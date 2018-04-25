/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Function definitions for class Critter
*********************************************************************/

#include "Critter.hpp"

Critter::Critter(int row, int col, int breedReadyAge) {
    this->breedReadyAge = breedReadyAge;
    this->row = row;
    this->col = col;
    this->moved = false;
    this->breedReady = false;
    this->breedAge = 0;
}

int Critter::getRow() {
    return row;
}

int Critter::getCol() {
    return col;
}

void Critter::resetMove() {
    moved = false;
}

bool Critter::getMoved() {
    return moved;
}

void Critter::incrementBreedAge() {
    breedAge += 1;
    if (breedAge == breedReadyAge) {
        breedReady = true;
    }
}

void Critter::resetBreedAge() {
    breedAge = 0;
    breedReady = false;
}

bool Critter::getBreedReady() {
    return breedReady;
}

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

Critter::~Critter(){}
