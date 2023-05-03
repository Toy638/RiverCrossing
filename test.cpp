#include <iostream>
#include "Operation/Operation.h"
#include "bitService/bitService.h"
#include "State/State.h"
using namespace std;




int main (){

    // int totalOfItems = 4;
    // int quantifyOfItemsInBoat = 2;
    // int numRepresentation = 3;   
    // bool *operation = new bool[totalOfItems];
    // operation[0] = true;
    // operation[1] = true;
    // operation[2] = false;
    // operation[3] = false;

    // bool *operation2 = new bool[totalOfItems];
    // operation2[0] = true;
    // operation2[1] = true;
    // operation2[2] = true;
    // operation2[3] = true;

    // Operation *operation1 = new Operation(operation, numRepresentation, quantifyOfItemsInBoat, totalOfItems);
    // Operation *operation3 = new Operation(operation2, 15, 4, totalOfItems);
    // State *state = new State(totalOfItems);

    // cout << "State" << endl;
    // state->print(totalOfItems);

    // cout << "Operation" << endl;

    // operation1->print(totalOfItems);

    // cout << "Can move? " << operation1->canMove(state) << endl;
    // State *testState = operation1->move(state);
    // cout << "State after move" << endl;
    // testState->print(totalOfItems);
    // cout << endl;

    int number = 6;

    int shift = 2;

    number = number >> shift;

    cout << (number & 1);
    

    return 0;

}