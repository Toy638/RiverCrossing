#include "Hashtable.h"

Hashtable::Hashtable(int totalOfItems)
{
    int quantifyOfCombinations = pow(2,totalOfItems);
    this->table = (LinkedList **)malloc(sizeof(LinkedList *) * quantifyOfCombinations);
    this->size  = quantifyOfCombinations;
    for (int i = 0; i < this->size; i++)
    {
        table[i] = new LinkedList();
    }
}

Hashtable::~Hashtable()
{
    for (int i = 0; i < this->size; i++)
    {
        table[i]->~LinkedList();
    }
}

int Hashtable::getSize(){
    return this->size;
}

LinkedList **Hashtable::getTable(){
    return this->table;
}

int Hashtable::hashFunction(Node *node){
    return node->getState()->getNumLeftRiver() % this->size;
}

void Hashtable::insert(Node *node){
    int index = this->hashFunction(node);
    this->table[index]->insertEnd(node);
}

bool Hashtable::searchState(Node *node){

    int index = this->hashFunction(node);
    if(this->table[index]->getHead() == nullptr){
        return false;
    }
    return this->table[index]->searchState(node->getState());

}



