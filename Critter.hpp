/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Class declaration of class Critter
*********************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include "validate.hpp"

enum Direction {NORTH, EAST, SOUTH, WEST};
enum Type {SPACE, ANT, BUG};

class Critter {
    protected:
        int row;
        int col;
        bool moved;
        int breedReadyAge;
        bool breedReady;
        int breedAge;
        int childRow;
        int childCol;

    public:
        Critter(int, int, int);
        virtual Type getType() = 0;
        virtual bool move(int *) = 0;
        virtual bool eatAnt() = 0;
        virtual bool starved() = 0;
        virtual Critter *breed() = 0;

        int getRow();
        int getCol();
        void resetMove();
        bool getMoved();
        void incrementBreedAge();
        void resetBreedAge();
        bool getBreedReady();
        bool canBreed(int *);
        virtual ~Critter();
};
#endif
