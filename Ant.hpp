/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Class declaration of class Ant
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant : public Critter {
    public:
        Ant(int, int);
        virtual Type getType();
        virtual bool move(int *);
        virtual bool eatAnt();
        virtual bool starved();
        virtual Critter *breed();
};
#endif
