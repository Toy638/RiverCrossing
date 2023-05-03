#include "Hashtable.h"

using namespace std;

int main(){
    Hashtable *table = new Hashtable();
    State *state = new State(3);
    State *ts;

    table->insert(state);
    cout <<"Realizando busqueda 1: " << table->search(state) << endl;
    cout <<"Realizando busqueda 2: " << table->search(ts) << endl;
    return 0;

}