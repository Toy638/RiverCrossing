#include "../heap/heap.h"


Heap::Heap(int size) {
    this->index = 0;
    this->size = size;
    heap = new *State[size];
}

Heap::~Heap() {
    delete[] heap;
}

State *Heap::getMaxRoot() {
    return heap[0];
}

State *Heap::lChild(int index) {
    return heap[2*index + 1];
}

State *Heap::rChild(int index) {
    return heap[2*index + 2];
}

void Heap::maxHeapify(int i){

    State *r = rChild(i);
    State *l = lChild(i);

    largest = i;

    if(l < heap_size && this.heap[l] > this.heap[i]) {
        largest = l;
    }

    if(r < heap_size && this.heap[r] > this.heap[largest]) {
        largest = r;
    }

    if(largest != i) {
        swap(this.heap[i], this.heap[largest]);
        maxHeapify(largest);
    }


}


