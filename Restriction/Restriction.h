#ifndef RESTRICTION_H
#define RESTRICTION_H

#include "../State/State.h"

class Restriction{
    private:
        bool *restriction;
        int numRepresentation;
        bool sideOfRestriction;
    public:
        Restriction(bool *Restriction ,int numRepresentation, int quantifyOfItems, bool sideOfRestriction);
        bool isValid(State *state);
        void print(int totalOfItems);
};


#endif



