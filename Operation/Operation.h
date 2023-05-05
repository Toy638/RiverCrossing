#include "../State/State.h"

#ifndef operation_h
#define operation_h


class Operation
{
    
private:
    bool *operation;
    int numRepresentation;
    int quantifyOfItemsInBoat;

public:
    // *CONSTRUCTORS

    /** 
     * @brief Construct a new Operation object
     *  @param numRepresentation Numeric representation of the operation
     *  @param quantifyOfItemsInBoat Quantify of items in the boat in the operation
     *  @param totalOfItems Total of items in the problem
     * 
     *  @return Operation*
    */
    Operation(int numRepresentation, int quantifyOfItemsInBoat, int totalOfItems);
    // ~Operation();

    //* GETTERS

    /**
     * @brief Get the Operation object
     * 
     * @return bool* 
     */
    bool *getOperation();
   
    /**
     * @brief Get the Num Representation object 
     * 
     * @return int 
     */

    int getNumRepresentation();
    
    /**
     * @brief Get the Quantify Of Items In Boat object 
     * 
     * @return int 
     */
    int getQuantifyOfItemsInBoat();

    //* PRINTING

    /**
     * @brief Print the operation
     * 
     * @param quantifyOfItems 
     */
    void print(int quantifyOfItems);


    // *OPERATIONS

    /**
     * @brief Check if the operation can be done in the state
     * 
     * @param state 
     * @return true 
     * @return false 
     */
    bool canMove(State *state);
    
    /**
     * @brief Move the state from the operation
     * 
     * @param state Prev State
     * @param quantifyOfItems Total Items in the problem
     * @return State* 
     */
    State *move(State *state, int quantifyOfItems);

};

#endif