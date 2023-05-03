#include "Node.h"

Node::Node(State *state){
    this->state = state;
    this->operation = nullptr;
    this->restriction = nullptr;
    this->nextNode = nullptr;
}

Node::Node(Operation *operation){
    this->state = nullptr;
    this->operation = operation;
    this->restriction = nullptr;
    this->nextNode = nullptr;
}

Node::Node(Restriction *restriction){
    this->state = nullptr;
    this->operation = nullptr;
    this->restriction = restriction;
    this->nextNode = nullptr;
}

Node::~Node(){
    delete this->state;
    delete this->operation;
    delete this->restriction;
}

State *Node::getState(){
    return this->state;
}

Restriction *Node::getRestriction(){
    return this->restriction;
}

Operation *Node::getOperation(){
    return this->operation;
}

Node *Node::getNextNode(){
    return this->nextNode;
}


void Node::setState(State *state){
    this->state = state;
}

void Node::setRestriction(Restriction *restriction){
    this->restriction = restriction;
}

void Node::setOperation(Operation *operation){
    this->operation = operation;
}

void Node::setNextNode(Node *nextNode){
    this->nextNode = nextNode;
}











