#include "RiverCrossing.h"


int main(){

    RiverCrossing *river = new RiverCrossing("sistema5.txt");
    river->generateOperations();
    river->generateRestrictions();
    river->solve();
    


}

