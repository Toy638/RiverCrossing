// #include "Hashtable.h"


// Hashtable::Hashtable(/* args */){
//     this->table = (LinkedList **)malloc(sizeof(LinkedList *) * 128);
//     this->size  = 128;
//     for (int i = 0; i < this->size; i++)
//     {
//         table[i] = new LinkedList();
//     }
    
// }

// Hashtable::~Hashtable()
// {
//     for (int i = 0; i < this->size; i++)
//     {
//         table[i]->~LinkedList();
//     }
    
// }

// //Getters

// int Hashtable::getSize(){
//     return this->size;
// }

// LinkedList **Hashtable::getTable(){
//     return this->table;
// }

// int Hashtable::hashFunction(State *state){
//     return state->getNumLeftRiver() % this->size;
// }

// void Hashtable::insert(State *state){
//     int index = this->hashFunction(state);
//     this->table[index]->insertEnd(state);
// }

// bool Hashtable::search(State *state){
//     int index = this->hashFunction(state);
//     if(this->table[index]->getHead() == nullptr){
//         return false;
//     }
//     return this->table[index]->search(state);
// }






