#ifndef BITSERVICE_H
#define BITSERVICE_H

#include <iostream>
#include <cmath>

class bitService
{
private:
    bool active;
public:

    /**
     * @brief Construct a new bit Service object
     * 
     */
    bitService(/* args */);
    
    /**
     * @brief Destroy the bit Service object
     * 
     */
    ~bitService();
    
    /**
     * @brief Get the negation of the bool
     * 
     * @return bool
     */
    bool assignOppositeBool(bool boolToAssign);

    /**
     * @brief Get the negation of the bool array
     * 
     * @return bool*
     */
    bool *assignOppositeBoolArray(bool *boolArrayToAssign, int size);

    /**
     * @brief Get the int representation of the bool array
     * 
     * @return int
     */
    int bitsToInt(bool *boolArrayToAssign, int size);
    
    /**
     * @brief Get the bool array representation of the int
     * 
     * @return bool*
     */
    bool *intToBits(int intToAssign, int size);
    //todo: brianKernighan

    /**
     * @brief Get the count of set bits in the int
     * 
     * @return int
     */
    int *countSetBits(int number, int quantifyOfDrivers, int totalOfITems);


};

#endif