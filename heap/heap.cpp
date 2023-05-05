#include "heap.h"

Heap::Heap(int size) {
    this->size = size;
    heap = new State[size];
}

Heap::~Heap() {
    delete[] heap;
}

Heap::insert(){
    
}
    

