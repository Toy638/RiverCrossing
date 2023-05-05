#ifndef NODE_H
#define NODE_H

# include "../Operation/Operation.h"
# include "../Restriction/Restriction.h"
# include "../State/State.h"

class Node
{
private:
    State *state;
    Operation *operation;
    Restriction *restriction;
    Node *nextNode;
public:

    /**
     * @brief Construct a new Node object
     * 
     * @param state 
     */
    Node(State *state);

    /**
     * @brief Construct a new Node object
     * 
     * @param operation 
     */
    Node(Operation *operation);

    /**
     * @brief Construct a new Node object
     * 
     * @param restriction 
     */
    Node(Restriction *restriction);

    ~Node();


    /**
     * @brief Get the State object
     * 
     * @return State* 
     */
    State *getState();

    /**
     * @brief Get the Restriction object
     * 
     * @return Restriction* 
     */
    Restriction *getRestriction();

    /**
     * @brief Get the Operation object
     * 
     * @return Operation* 
     */
    Operation *getOperation();
    /**
     * @brief Get the Next Node object
     * 
     * @return Node* 
     */
    Node *getNextNode();


    /**
     * @brief Set the State object
     * 
     * @param state 
     */
    void setState(State *state);

    /**
     * @brief Set the Restriction object
     * 
     * @param restriction 
     */
    void setRestriction(Restriction *restriction);

    /**
     * @brief Set the Operation object
     * 
     * @param operation 
     */
    void setOperation(Operation *operation);


    /**
     * @brief Set the Next Node object
     * 
     * @param nextNode 
     */
    void setNextNode(Node *nextNode);

};





#endif