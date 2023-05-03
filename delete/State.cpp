#include "State.h"


State::State(){
    this->sideBoat = LEFT;
    this->river.reset();
    this->prev = nullptr;

}


State::State(string bitset, State *prev){
    int len = bitset.length();
    int init = this->river.size() - bitset.length();

    this->sideBoat = not(prev->getSideBoat());

    for (int i = 0 ; i < len ; i++)
    {

        if(bitset[i] == '1'){
            this->river.set(init);
        }
        else{
            this->river.reset(init);
        }
        init++;
        
    }
    



    this->prev = prev;

}


//todo:
State::~State(){

}


//GETTERS

bool State::getSideBoat(){
    return this->sideBoat;
}

bitset<64> State::GetBitset(){
    return this->river;
}

int State::getDecimalRepresentation(bool sideToGet){

    if(sideToGet == LEFT){
        return this->river.to_ulong();
    }
    // return rightRiver
    return this->river.flip().to_ulong();

}

string State::getStringBinaryRepresentation(bool sideToGet){

    if(sideToGet == LEFT){
        return this->river.to_string();
    }
    // return rightRiver
    return this->river.flip().to_string();

}


//SETTERS


//PRINTING

void State::printLeftRiver(){
    cout << this->river.to_string() << endl;
    cout << this->river.to_ulong() << endl;
}

void State::printRightRiver(){
    cout << this->river.flip().to_string() << endl;
    cout << this->river.flip().to_ulong() << endl;
}

void State::printSideBoat(){
    if(this->sideBoat == LEFT){
        cout << "LEFT" << endl;
    }
    else{
        cout << "RIGHT" << endl;
    }
}

void State::print(){
    cout << "Left River: " << endl;
    this->printLeftRiver();
    cout << "Right River: " << endl;
    this->printRightRiver();
    cout << "Side Boat: " << endl;
    this->printSideBoat();
    cout << endl;
}



