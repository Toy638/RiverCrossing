#include "Restriction.h"
using namespace std;

//Constructores
Restriction::Restriction( bool *RestrictionInput ,int numRepresentation, int quantifyOfItems, bool sideOfRestriction){

    this->restriction = new bool[quantifyOfItems];
    this->numRepresentation = numRepresentation;
    
    for(int i = 0; i < quantifyOfItems; i++){
        this->restriction[i] = RestrictionInput[i];
    }

    this->sideOfRestriction = sideOfRestriction;

//    free(RestrictionInput); //! analizar el como trabaja en la memoria

}


bool Restriction::isValid(State *state){

    if(this->sideOfRestriction == LEFT){
        return (this->numRepresentation != state->getNumLeftRiver());
    }

    return (this->numRepresentation != state->getNumRightRiver());
}  

void Restriction::print(int totalOfItems){
    cout << "Restriction" << endl;
    cout << "NumRepresentation: " << this->numRepresentation << endl;
    for (int i = 0; i < totalOfItems; i++)
    {
        cout << restriction[i] << " ";
    }
    cout << endl;
    
}



