#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../LinkedList/LinkedList.h"
#include "../Node/Node.h"

class Hashtable
{
private:
    LinkedList **table;
    int size;
public:

    /**
     * @brief Construct a new Hashtable object
     * 
     * @param quantifyOfItems 
     */
    Hashtable(int quantifyOfItems);

    /**
     * @brief Destroy the Hashtable object
     * 
     */
    ~Hashtable();

    //Getters
    /**
     * @brief Get the Size object
     * 
     * @return int 
     */
    int getSize();

    /**
     * @brief Get the Table object
     * 
     * @return LinkedList** 
     */
    LinkedList **getTable();

    /**
     * @brief realizes the hash function and returns the index
     * 
     * @param node Node to be hashed
     * @return int 
     */
    int hashFunction(Node *node);
    /**
     * @brief Insert the node into the hashtable
     * 
     * @param node Node to be inserted
     */
    void insert(Node *node);
    /**
     * @brief Search the state in the hashtable
     * 
     * @param node 
     * @return bool  
     */
    bool searchState(Node *node);

};





#endif