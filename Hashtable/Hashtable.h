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
    Hashtable(int quantifyOfItems);
    ~Hashtable();

    //Getters
    int getSize();
    LinkedList **getTable();


    int hashFunction(Node *node);
    void insert(Node *node);
    bool searchState(Node *node);

};





#endif