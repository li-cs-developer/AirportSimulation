#include "Node.h"

//constructor
Node::Node(Event& event){
    this->event = event.clone();
    this->next = nullptr;
}

//destructor
Node::~Node(){
    delete event; //delete the event stored in the node
}

//copy construtor
Node::Node(const Node& other){
    this->event = other.event->clone(); 
    this->next = nullptr; 
}

/*********** getters ***********/

Event* Node::getEvent() const {
    return event;
}

Node* Node::getNext() const{
    return next;
}

/*********** setters ***********/

void Node::setNext(Node *next){
    this->next = next;
}