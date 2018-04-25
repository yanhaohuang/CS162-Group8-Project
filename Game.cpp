/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 8
** Date: 5-XX-2018
** Description: Function definitions for class Game
*********************************************************************/

#include "Game.hpp"

void Game::menu() {
    int input;

    do {
        cout << "   Predator-Prey Game Menu" << endl
                << "1) Start Predator-Prey Game" << endl
                << "2) Quit" << endl
                << "Enter your choice: " ;
        input = validate(1, 2);

        switch (input) {
            case 1: {
                    play();
                    break;
            }
            case 2: {
                    cout << "Quitting program" << endl;
            }
        }
    } while (input != 2);
}

void Game::play() {
    initialize();
    int input;

    do {
        cout << "Enter the number of steps: ";
        int steps = validate(0, numeric_limits<int>::max());

        for (int i = 0; i < steps; i++) {
            cout << "Step " << i + 1 << ":" << endl;

            move(BUG);                                      //move bug first
            move(ANT);                                      //move ant second
            resetMove();                                    //reset all moved to false
            printGrid();
        }

        cout << "Continue playing game?" << endl
                << "1) Continue" << endl
                << "2) End game" << endl
                << "Enter your choice: ";
        input = validate(1, 2);
        cout << endl << endl;

    } while (input != 2);

    cout << "Game Over" << endl << endl;
}

void Game::initialize() {
    cols = 20;
    rows = 20;
    numAnts = 100;
    numBugs = 5;

    grid = new Critter**[rows];

    for (int r = 0; r < rows; r++) {
        grid[r] = new Critter*[cols];

        for (int c = 0; c < cols; c++) {
            grid[r][c] = NULL;
        }
    }

    int randRow;
    int randCol;

    for (int i = 0; i < numAnts; i++) {
        do {
            randRow = rand() % rows;
            randCol = rand() % cols;
        } while (grid[randRow][randCol] != NULL);
        grid[randRow][randCol] = new Ant(randRow, randCol);
    }

    for (int j = 0; j < numBugs; j++) {
        do {
            randRow = rand() % rows;
            randCol = rand() % cols;
        } while (grid[randRow][randCol] != NULL);
        grid[randRow][randCol] = new Doodlebug(randRow, randCol);
    }

    printGrid();
}

void Game::move(Type critter) {
    int newRow;
    int newCol;
    bool dead;
    Critter *thisCritter;
    Critter *newCritter;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            dead = false;

            if (grid[r][c] == NULL) continue;

            if (grid[r][c]->getType() == critter) {                                     //check critter type here

                thisCritter = grid[r][c];

                if (!thisCritter->getMoved()) {                                         //check if already moved
                    getAdjacent(r, c);

                    if (thisCritter->move(adjacent)) {                                  //move critter
                        newRow = thisCritter->getRow();
                        newCol = thisCritter->getCol();

                        if (grid[r][c]->getType() == BUG && grid[r][c]->eatAnt()) {;    //for bugs only, check if ate ant
                            delete grid[newRow][newCol];
                        }
                        grid[newRow][newCol] = thisCritter;
                        grid[r][c] = NULL;
                    }
                }

                if (thisCritter->getType() == BUG && thisCritter->starved()) {          //for bugs only, check if starved
                    newRow = thisCritter->getRow();
                    newCol = thisCritter->getCol();
                    thisCritter = NULL;
                    delete grid[newRow][newCol];
                    grid[newRow][newCol] = NULL;
                    dead = true;
                }

                if (dead == false && thisCritter->getBreedReady()) {                    //check if ready to breed
                    getAdjacent(thisCritter->getRow(), thisCritter->getCol());

                    if (thisCritter->canBreed(adjacent)) {
                        newCritter = thisCritter->breed();
                        newRow = newCritter->getRow();
                        newCol = newCritter->getCol();
                        grid[newRow][newCol] = newCritter;
                    }
                }
            }

        }
    }
}

void Game::resetMove() {                                                                    //reset all moves
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] != NULL) {
                grid[r][c]->resetMove();
            }
        }
    }
}

void Game::printGrid() {
    for(int i = 0; i < cols * 4 + 1; i++) {
        cout <<"_";
    }

    for (int r = 0; r < rows; r++) {
        cout << endl << "|";
        for (int c = 0; c < cols; c++) {
            cout << " ";

            if (grid[r][c] != NULL) {

                if (grid[r][c]->getType() == ANT) {
                    cout << "O";
                } else {
                    cout << "X";
                }
            } else {
                cout << " ";
            }

            cout << " |";
        }
        cout << endl;
    }

    for(int i = 0; i < cols * 4 + 1; i++) {
        cout <<"_";
    }
    cout << endl << endl << endl;
}


void Game::getAdjacent(int row, int col) {                          //get adjacent 4 cells
    for (int i = 0; i < 4; i++) {
        adjacent[i] = -1;                                           //-1 is for off grid
    }

    if (row - 1 >= 0) {
        if (grid[row - 1][col] == NULL) {
            adjacent[0] = SPACE;
        } else if(grid[row - 1][col]->getType() == ANT) {
            adjacent[0] = ANT;
        } else if(grid[row - 1][col]->getType() == BUG) {
            adjacent[0] = BUG;
        }
    }

    if (row + 1 < rows) {
        if (grid[row + 1][col] == NULL) {
            adjacent[2] = SPACE;
        } else if (grid[row + 1][col]->getType() == ANT) {
            adjacent[2] = ANT;
        } else if (grid[row + 1][col]->getType() == BUG) {
            adjacent[2] = 2;
        }
    }

    if (col - 1 >= 0) {
        if (grid[row][col - 1] == NULL) {
            adjacent[3] = SPACE;
        } else if (grid[row][col - 1]->getType() == ANT) {
            adjacent[3] = ANT;
        } else if (grid[row][col - 1]->getType() == BUG) {
            adjacent[3] = BUG;
        }
    }

    if (col + 1 < cols) {
        if (grid[row][col + 1] == NULL) {
            adjacent[1] = SPACE;
        }
        else if (grid[row][col + 1]->getType() == ANT) {
            adjacent[1] = ANT;
        }
        else if (grid[row][col + 1]->getType() == BUG) {
            adjacent[1] = BUG;
        }
    }
}

Game::~Game() {                                     //destructor, deallocate all memory
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] != NULL) {
                delete grid[r][c];
            }
        }
        delete [] grid[r];
    }
    delete [] grid;
}
