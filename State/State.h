#include <iostream>
#include <cmath>
#include "../bitService/bitService.h"

#ifndef STATE_H
#define STATE_H
#define LEFT 0
#define RIGHT 1

class State
{

private:

    bool sideBoat;
    bool *river;
    int numLeftRiver;
    int numRightRiver;
    State *previousState;
    State *nextState;
    

public:
    //*CONSTRUCTORS
 
    /**
     * @brief Construct a new State object
     * 
     * @param totalOfItems Total of items in the problem
     */
    State(int totalOfItems);

    /**
     * @brief Destroy the State object  
     * 
     */
     ~State();

    //*GETTERS

    /**
     * @brief Get the River Boolean Representation
     * 
     * @return bool* 
     */
    bool *getRiver();

    /**
     * @brief Get the Side of the boat
     * 
     * @return bool 
     */
    bool getSideBoat();

    /**
     * @brief Get the Num Left River
     * 
     * @return int 
     */
    int getNumLeftRiver();
    
    /**
     * @brief Get the Num Right River object
     * 
     * @return int 
     */
    int getNumRightRiver();

    /**
     * @brief Get the Length River object
     * 
     * @return int 
     */
    int getLengthRiver(); 

    /**
     * @brief Get the Father object 
     * 
     * @return State* 
     */
    State *getFather();

    /**
     * @brief Get the Next State object
     * 
     * @return State* 
     */
    State *getNextState();

    //*SETTERS
    
    /**
     * @brief Set the River Boolean Representation object
     * 
     * @param river 
     */
    void setSideBoat(bool sideBoat);
    
    /**
     * @brief Set the Num Left River object
     * 
     * @param numLeftRiver 
     */
    void setNumLeftRiver(int numLeftRiver);

    /**
     * @brief Set the Num Right River object
     * 
     * @param numRightRiver 
     */
    void setNumRightRiver(int numRightRiver);
    
    /**
     * @brief Set the Father object
     * 
     * @param previousState 
     */
    void setFather(State *previousState);

    /**
     * @brief Set the Next State object
     * 
     * @param nextState 
     */
    void setNextState(State *nextState);


    //OPERATIONS
    /** 
     * @brief Check if the state is the final state
     * 
     * @param quantifyOfItems
     * @param quantifyOfDrivers
     * @param totalOfItems
     * 
     * @return bool
     * 
    */
    
    bool isFinal(int quantifyOfItems, int quantifyOfDrivers, int totalOfItems);


    //printing

    /**
     * @brief Print the state
     * 
     * @param quantifyOfItems 
     */
    void print(int quantifyOfItems);
    
    

    /**
     * @brief Print the left river
     * 
     * @param quantifyOfItems 
     */

    void printLeftRiver(int quantifyOfItems);

    /**
     * @brief Print the right river
     * 
     * @param quantifyOfItems 
     */
    void printRightRiver(int quantifyOfItems);
    
    /** 
     * @brief Print the path of the state
     * 
    */
    void printPath(int quantifyOfItems);    

};



#endif