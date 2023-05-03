#include "../State/State.h"
#include "../Restriction/Restriction.h"
#include "../Operation/Operation.h"
#include "../Node/Node.h"

#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[]){

    LinkedList *list = new LinkedList();

    State *ts = new State(3);
    ts->setNumLeftRiver(12);
    ts->setNumRightRiver(3);

    State *search = new State(3);
    search->setNumLeftRiver(5);
    search->setNumRightRiver(3);

    Node *node = new Node(ts);
    Node *node2 = new Node(new State(3));
    Node *node3 = new Node(new State(3));
    Node *node4 = new Node(new State(3));

    list->insertBegin(node);
    list->insertBegin(node2);
    list->insertBegin(node3);
    list->insertBegin(node4);

    list->pop();

    list->printState(3);

    // Aparentemente el search esta bien
    cout << list->searchState(search) << endl;
    
    return 0;

}