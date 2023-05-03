#include "../State/State.h"
#include "../Operation/Operation.h"
#include "Restriction.h"

using namespace std;

int main(int argc, char*argv[]){

    bool *restriction = new bool[4];
    restriction[0] = 0;
    restriction[1] = 0;
    restriction[2] = 1;
    restriction[3] = 1;
    
    bool *operation = new bool[4];
    operation[0] = 1;
    operation[1] = 1;
    operation[2] = 0;
    operation[3] = 0;

    Operation *operation1 = new Operation(operation, 16, 2, 4);
    Restriction *restriction1 = new Restriction(restriction, 12, 4, RIGHT);

    State *state = new State(4);
    State *temporalState = operation1->move(state,4);
    cout << (temporalState == nullptr) << endl;  // ? Que pasa cuando no se puede mover : retorna nullptr

//    cout << restriction1->isValid(temporalState) << endl;
    cout << restriction1->isValid(state) << endl;

}





