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
    Node(State *state);
    Node(Operation *operation);
    Node(Restriction *restriction);

    ~Node();

    State *getState();
    Restriction *getRestriction();
    Operation *getOperation();
    Node *getNextNode();


    void setState(State *state);
    void setRestriction(Restriction *restriction);
    void setOperation(Operation *operation);

    void setNextNode(Node *nextNode);

};





#endif