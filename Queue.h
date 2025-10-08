//-----------------------------------------
// CLASS: Queue
//
// REMARKS: This class represents a FIFO Queue ADT
//-----------------------------------------

#pragma once
#include "Node.h"

class Queue{
    private: 
        Node *head;
        Node *tail;
    protected:
        //getters
        Node* getHead() const;
        Node* getTail() const;

        //setters
        void setHead(Node*);
        void setTail(Node*);
    public:
        //constructor
        Queue(); 

        //destructor
        ~Queue(); 

        //adds a new event to the tail of the queue
        virtual void enqueue(Event&); 

        //removes the event from the front of the queue and returns it
        Event* dequeue();

        //checks if the queue is empty and returns a boolean     
        bool isEmpty() const; 
};