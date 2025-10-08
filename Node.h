//-----------------------------------------
// CLASS: Node
//
// REMARKS: This class represents a node, it stores an event and the next node
//-----------------------------------------

#pragma once
#include "Event.h"

class Node{
    private: 
        Event *event; //the event stored in the node
        Node *next; //next node
    public:
        //constructor
        Node(Event&); 

        //destructor
        ~Node(); 

        //copy construtor
        Node(const Node&); 

        //getters
        Event* getEvent() const;
        Node* getNext() const;

        //setter
        void setNext(Node*);
};