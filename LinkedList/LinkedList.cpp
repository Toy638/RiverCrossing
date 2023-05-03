#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
    this->head = nullptr;
    this->size = 0;
}

LinkedList::~LinkedList(){
    Node *aux = this->head;
    while (aux != nullptr)
    {
        Node *aux2 = aux->getNextNode();
        delete aux;
        aux = aux2;
    }
}

//GETTERS

Node *LinkedList::getHead(){
    return this->head;
}

int LinkedList::getSize(){
    return this->size;
}


//PERTENENCIA

bool LinkedList::isEmpty(){
    return this->size == 0;
}

bool LinkedList::searchState(State *state){
    Node *aux = this->head;
    while (aux != nullptr)
    {
        if (aux->getState()->getNumLeftRiver() == state->getNumLeftRiver() && aux->getState()->getNumRightRiver() == state->getNumRightRiver() )
        {
            return true;
        }
        aux = aux->getNextNode();
    }
    return false;
};

Node *LinkedList::pop(){
    Node *aux = this->head;
    this->head = aux->getNextNode();
    this->size--;
    return aux;
}


//SETTERS

void LinkedList::insertBegin(Node *node){

    if (this->head == nullptr)
    {
        this->head = node;
        this->size++;
    }else{
        node->setNextNode(this->head);
        this->head = node;
        this->size++;
    }
}

void LinkedList::insertEnd(Node *node){
    if (this->head == nullptr)
    {
        this->head = node;
        node->setNextNode(nullptr);
        this->size++;
    }else{
        Node *aux = this->head;
        while (aux->getNextNode() != nullptr)
        {
            aux = aux->getNextNode();
        }
        aux->setNextNode(node);
        node->setNextNode(nullptr);
        this->size++;
    }
}

//PRINTING

void LinkedList::printState(int quantifyOfItems){

    Node *aux = this->head;

    while (aux != nullptr)
    {
        aux->getState()->print(quantifyOfItems);
        aux = aux->getNextNode();
    
    }
}


















