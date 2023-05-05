#ifndef RESTRICTION_H
#define RESTRICTION_H

#include "../State/State.h"

class Restriction{
    private:
        bool *restriction;
        int numRepresentation;
        bool sideOfRestriction;
    public:

        /**
         * @brief Construct a new Restriction object
         * 
         * @param Restriction Boolean representation of the restriction
         * @param numRepresentation  numeric representation of the restriction 
         * @param quantifyOfItems quantify of items in the problem
         * @param sideOfRestriction boolean side representation of the restriction
         */
        Restriction(bool *Restriction ,int numRepresentation, int quantifyOfItems, bool sideOfRestriction);

        /**
         * @brief 
         * 
         * @param state 
         * @return bool 
         */
        bool isValid(State *state);


        /**
         * @brief 
         * 
         * @param totalOfItems quantify of items in the problem
         */
        void print(int totalOfItems);
};


#endif



