#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "../State/State.h"
#include "../LinkedList/LinkedList.h"

class Hashtable
{
private:
    LinkedList **table;
    int size;

public:
    //CONSTRUCTORS
    Hashtable(/* args */);
    ~Hashtable();

    //GETTERS
    int getSize();
    LinkedList **getTable();


    //METHODS
    int hashFunction(State *state);
    void insert(State *state);
    bool search(State *state);

};

#endif