#include "../State/State.h"

#ifndef HEAP_H
#define HEAP_H

class Heap {
    private:
        State *heap;
        int size;    
    
    public:
        Heap(int size);
        ~Heap();
        void insert(int value);
        void remove();
        void print();
    


}







#endif
