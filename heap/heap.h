#include "../State/State.h"

#ifndef HEAP_H
#define HEAP_H


//todo: definir todas las operaciones por realizar en el heap
// entender max heapify y build max heap



class Heap {
    private:
        State **heap;
        int index;
        int maxSize;    

    public:
    
        Heap(int size);
        ~Heap();

        State getMaxRoot();
        State *lChild(int index);
        State *rChild(int index);
        
        void maxHeapify();
        void remove();
        void print();
    


}







#endif
