#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../Node/Node.h"

class LinkedList
{
private:

    Node *head;
    int size;

public:
    /**
     * @brief Construct a new Linked List object
     * 
     */
    LinkedList();

    /**
     * @brief Destroy the Linked List object
     * 
     */
    ~LinkedList();

    //GETTERS
    /**
     * @brief Get the Head object
     * 
     * @return Node* 
     */
    Node *getHead();

    /**
     * @brief Get the Size object
     * 
     * @return int 
     */
    int getSize();


    //pertenencia

    /**
     * @brief Check if the linkedList is Empty
     * 
     * @return bool
     */
    bool isEmpty();
    /**
     * @brief Search the state in the linkedList
     * 
     * @param state State to be searched
     * @return true 
     * @return false 
     */
    bool searchState(State *state);
 
    
    /**
     * @brief Delete the first node
     * 
     * @return Node* 
     */
    Node *pop();

    //SETTERS
    /**
     * @brief Insert the node in the first position 
     * 
     * @param Node 
     */
    void insertBegin(Node *Node); //ENQUEUE

    /**
     * @brief Insert the node in the last position
     * 
     * @param Node 
     */
    void insertEnd(Node *Node); //PUSH   

    //PRINTING
    /**
     * @brief print the state of the node
     * 
     * @param quantifyOfItems 
     */
    void printState(int quantifyOfItems);

    //OPERATIONS

};





#endif