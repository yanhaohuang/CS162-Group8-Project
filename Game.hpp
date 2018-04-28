/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Class declaration of class Game
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Ant.hpp"
#include "Doodlebug.hpp"

class Game {
    private:
        int steps;
        int numAnts;
        int numBugs;
        int rows;
        int cols;
        int adjacent[4];
        Critter ***grid;

    public:
        void menu();
        void play();
        void initialize();
        void initializeEC();
        void move(Type);
        void resetMove();
        void printGrid();
        void getAdjacent(int, int);
        ~Game();
};
#endif
