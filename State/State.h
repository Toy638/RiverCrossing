#include <iostream>
#include <cmath>
#include "../bitService/bitService.h"

#ifndef STATE_H
#define STATE_H
#define LEFT 0
#define RIGHT 1

class State
{

private:

    bool sideBoat;
    bool *river;
    int numLeftRiver;
    int numRightRiver;
    State *previousState;
    State *nextState;
    

public:
    State(int quantifyOfItems, int quantifyOfDrivers, int totalOfItems);
    //todo: ver si es posible tener una interpretacion en numeros solamenta e independizarse de los binarios
//    State(bool *river, bool sideBoat, int numLeftRiver, int numRightRiver);
    ~State();

    //GETTERS
    bool *getRiver();
    bool getSideBoat();
    int getNumLeftRiver();
    int getNumRightRiver();
    int getLengthRiver(); //! bug
    State *getFather();
    State *getNextState();

    //SETTERS
    void setSideBoat(bool sideBoat);
    void setNumLeftRiver(int numLeftRiver);
    void setNumRightRiver(int numRightRiver);
    void setFather(State *previousState);
    void setNextState(State *nextState);


    //OPERATIONS
    bool isFinal(int quantifyOfItems, int quantifyOfDrivers, int totalOfItems);


    //printing
    void print(int quantifyOfItems);
    void printLeftRiver(int quantifyOfItems);
    void printRightRiver(int quantifyOfItems);
    void printPath(int quantifyOfItems);    

};



#endif