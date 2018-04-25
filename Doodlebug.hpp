/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Class declaration of class Doodlebug
*********************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter {
    private:
        int starveTime;
        bool eat;

    public:
        Doodlebug(int, int);
        virtual Type getType();
        virtual bool move(int *);
        virtual bool eatAnt();
        virtual bool starved();
        virtual Critter *breed();
};
#endif
