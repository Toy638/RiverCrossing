#include "State.h"

using namespace std;

State::State(int totalOfItems){

    this->river = new bool[totalOfItems];

    for (int i = 0; i < totalOfItems; i++)
    {
        this->river[i] = true;
    }
    this->sideBoat = LEFT;
    this->numRightRiver = 0;
    this->previousState = nullptr;
    this->numLeftRiver = pow(2, totalOfItems) - 1;

}




State::~State(){

    delete[] river;

}

//GETTER's

bool *State::getRiver(){

    return this->river;

}

bool State::getSideBoat(){

    return this->sideBoat;

}

int State::getNumLeftRiver(){

    return this->numLeftRiver;

}

int State::getNumRightRiver(){

    return this->numRightRiver;

}

int State::getLengthRiver(){

    return (sizeof(this->river)/sizeof(this->river[0]));

}

State *State::getFather(){

    return this->previousState;

}

State *State::getNextState(){

    return this->nextState;

}

//SETTER's

void State::setSideBoat(bool sideBoat){

    this->sideBoat = sideBoat;

}

void State::setNumLeftRiver(int numLeftRiver){

    this->numLeftRiver = numLeftRiver;

}

void State::setNumRightRiver(int numRightRiver){

    this->numRightRiver = numRightRiver;

}

void State::setFather(State *previousState){

    this->previousState = previousState;

}

void State::setNextState(State *nextState){

    this->nextState = nextState;

}


//PRINTING
void State::print(int quantifyOfItems){
    
    cout << "Side of the boat: " << this->sideBoat << endl;
    cout << "Left river: "<< endl;
    printLeftRiver(quantifyOfItems);
    cout << "NumRepresentation Left river: " << this->numLeftRiver << endl;
    cout << "Right river: "<< endl;
    printRightRiver(quantifyOfItems);
    cout << "NumRepresentation Right river: " << this->numRightRiver << endl;

}

void State::printLeftRiver( int quantifyOfItems){

    bitService *bitServ = new bitService();

    bool *river = bitServ->intToBits(this->getNumLeftRiver(), quantifyOfItems);

    for (int i = 0; i < quantifyOfItems; i++)
    {
        cout << river[i];
    }
    cout << endl;

}

void State::printRightRiver( int quantifyOfItems){

    bitService *bitServ = new bitService();
    bool *river = bitServ->intToBits(this->getNumLeftRiver(), quantifyOfItems);


    for (int i = 0; i < quantifyOfItems; i++)
    {
        cout << not(river[i]);
    }
    cout << endl;

}

//todo: modificar en todos lados en los que aparezca
bool State::isFinal(int quantifyOfDrivers, int quantifyOfItems, int totalOfItems){

    return (this->getNumRightRiver() == (pow(2,totalOfItems)-1));
    
}

void State::printPath(int quantifyOfItems){
    
        if (this->previousState != nullptr){
            this->previousState->printPath(quantifyOfItems);
        }
        this->print(quantifyOfItems);
        cout << endl;
}

