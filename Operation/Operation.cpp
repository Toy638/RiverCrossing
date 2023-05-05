#include "Operation.h"

using namespace std;

//CONSTRUCTOR

Operation::Operation(int numRepresentation, int quantifyOfItemsInBoat, int totalOfItems)
{
    this->operation = new bool[totalOfItems];
    for (int i = 0; i < totalOfItems; i++)
    {
        this->operation[i] = operation[i];
    }
    this->numRepresentation = numRepresentation;
    this->quantifyOfItemsInBoat = quantifyOfItemsInBoat;
}


//GETTER's

bool *Operation::getOperation()
{
    return this->operation;
}

int Operation::getNumRepresentation()
{
    return this->numRepresentation;
}

int Operation::getQuantifyOfItemsInBoat()
{
    return this->quantifyOfItemsInBoat;
}

//PRINTING

void Operation::print(int quantifyOfItems)
{
    cout << "Operation: ";

    //todo: lograr imprimir la operacion usando bitservice
    // ? Realmente me interesa imprimir la operacion o realmente me interesa imprimir el estado y sus cambios
    // for (int i = 0; i < quantifyOfItems; i++)
    // {
    //     cout << this->operation[i] << " ";
    // }
    // cout << endl;

    cout << "Num Representation: " << this->numRepresentation << endl;
    cout << "Quantify of Items in boat: " << this->quantifyOfItemsInBoat << endl; 
}



//OP'S


bool Operation::canMove(State *state){

        int numLeftRiver = state->getNumLeftRiver();
        int numRightRiver = state->getNumRightRiver();
        int OperationNumRep = this->numRepresentation;

    if( state->getSideBoat() == LEFT){
        cout << "NumLeftRiver: " << state->getNumLeftRiver() << endl;
        cout << "NumRepresentation: " << this->numRepresentation << endl;
        return ((numLeftRiver & OperationNumRep) == OperationNumRep);
    }

    return ((numRightRiver & OperationNumRep) == OperationNumRep);

}

// Todo: verificar si está bien con el + o usar el pperador & ~
// ! verificar que retorne el nullptr en la funcion successor
State *Operation::move(State *state, int quantifyOfItems){

    State *stateReturn = new State(quantifyOfItems);

    if(!this->canMove(state)){
        return nullptr;
    }
    stateReturn->setFather(state);

    if( state->getSideBoat() == LEFT){
        stateReturn->setNumLeftRiver(state->getNumLeftRiver() - this->numRepresentation);
        stateReturn->setNumRightRiver(state->getNumRightRiver() + this->numRepresentation);
        stateReturn->setSideBoat(RIGHT);
        return stateReturn;
    }

    stateReturn->setNumLeftRiver(state->getNumLeftRiver() + this->numRepresentation);
    stateReturn->setNumRightRiver(state->getNumRightRiver() - this->numRepresentation);
    stateReturn->setSideBoat(LEFT);
 
    return stateReturn;

}