#include "../State/State.h"

#ifndef operation_h
#define operation_h


class Operation
{
    
private:
    bool *operation;
    int numRepresentation;
    int quantifyOfItemsInBoat;

public:
    // Constructor
    Operation(int numRepresentation, int quantifyOfItemsInBoat, int totalOfItems);
    // ~Operation();

    // Getters
    bool *getOperation();
    int getNumRepresentation();
    int getQuantifyOfItemsInBoat();

    //printing
    void print(int quantifyOfItems);


    // Operations
    bool canMove(State *state);
    State *move(State *state, int quantifyOfItems);

};

#endif