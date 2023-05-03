#ifndef STATE_H
#define STATE_H


#include <bitset>
#include <iostream>
#define LEFT 0
#define RIGHT 1


using namespace std;

class State
{
private:
    bool sideBoat;
    int numBits;
    bitset<64>river; // en estado natural representa el lado izquierdo
    State *prev;

public:

    State();
    State(string leftSide, State *prev);
    ~State();

    //GETTERS

    bool getSideBoat();
    bitset<64> GetBitset();
    int getDecimalRepresentation(bool SideToGet);
    string getStringBinaryRepresentation(bool sideToGet);

    //PRINTING

    void printLeftRiver();
    void printRightRiver();
    void printSideBoat();

    void print();




};


#endif