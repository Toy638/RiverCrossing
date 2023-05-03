#ifndef BITSERVICE_H
#define BITSERVICE_H

#include <iostream>
#include <cmath>

class bitService
{
private:
    bool active;
public:
    bitService(/* args */);
    ~bitService();
    bool assignOppositeBool(bool boolToAssign);
    bool *assignOppositeBoolArray(bool *boolArrayToAssign, int size);
    int bitsToInt(bool *boolArrayToAssign, int size);
    bool *intToBits(int intToAssign, int size);
    //brianKernighan
    int *countSetBits(int number, int quantifyOfDrivers, int totalOfITems);


};

#endif