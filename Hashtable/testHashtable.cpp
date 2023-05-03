#include "Hashtable.h"

using namespace std;

int main(){
    
        Hashtable *table = new Hashtable(3);
    
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
    
        table->insert(node);
        table->insert(node2);
        table->insert(node3);
        table->insert(node4);
    
        // 

        // Aparentemente el search esta bien
        cout << table->searchState(node) << endl;


        for (int i = 0; i < table->getSize(); i++)
        {
            table->getTable()[i]->printState(3);
            if(table->getTable()[i]->getHead() == nullptr){
                cout << "NULL: " << i << endl;
            }

        }
        


        return 0;



}

