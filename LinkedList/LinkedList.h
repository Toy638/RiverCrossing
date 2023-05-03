#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../Node/Node.h"

class LinkedList
{
private:

    Node *head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    //GETTERS
    Node *getHead();
    int getSize();


    //pertenencia
    bool isEmpty();
    bool searchState(State *state);
 
    
    Node *pop();

    //SETTERS
    void insertBegin(Node *Node); //ENQUEUE
    void insertEnd(Node *Node); //PUSH   

    //PRINTING
    void printState(int quantifyOfItems);

    //OPERATIONS

};





#endif