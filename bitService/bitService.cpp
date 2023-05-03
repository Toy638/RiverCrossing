
#include "bitService.h"

using namespace std;

bitService::bitService(/* args */)
{
    this->active = true;
}

bitService::~bitService()
{
}

bool bitService::assignOppositeBool(bool boolToAssign)
{
    return !boolToAssign;
}

bool *bitService::assignOppositeBoolArray(bool *boolArrayToAssign, int size)
{
    bool *boolArrayToReturn = new bool[size];
    for (int i = 0; i < size; i++)
    {
        boolArrayToReturn[i] = assignOppositeBool(boolArrayToAssign[i]);
    }
    return boolArrayToReturn;
}

int bitService::bitsToInt(bool *boolArrayToAssign, int size)
{
    int intToReturn = 0;
    for (int i = 0; i < size; i++)
    {
        intToReturn += boolArrayToAssign[i] * pow(2, size - i - 1);
    }
    return intToReturn;

}

bool *bitService::intToBits(int intToAssign, int size)
{
    bool *boolArrayToReturn = new bool[size];

    for (int i = size-1; i > -1; i--)
    {
        boolArrayToReturn[i] = intToAssign % 2;
        intToAssign /= 2;
    }

    return boolArrayToReturn;
}

int *bitService::countSetBits(int number, int quantifyOfDrivers, int quantifyOfItems){

    unsigned int countItemsInBoat = 0;
    unsigned int countDrivers = 0;
    unsigned int driverIterator = 0;

    while (number)
    {
        // cout << number << endl;
        countItemsInBoat += number & 1;

        if(driverIterator >= quantifyOfItems){
            countDrivers += number & 1;
        }
        driverIterator ++;
        number >>= 1;

    }

    // cout << "Items In Boat: " << countItemsInBoat << endl;
    // cout << "Drivers: " << countDrivers << endl;

    //todo: ver como mejorar esa asquerosa sintaxis
    int *ItemsDrivers = new int[2];
    ItemsDrivers[0] = countItemsInBoat;
    ItemsDrivers[1] = countDrivers;

    return ItemsDrivers;
}




