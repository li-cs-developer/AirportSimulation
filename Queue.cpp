#include "Queue.h"

//constructor
Queue::Queue(){
    
    //initalize both head and tail to null
    this->head = nullptr;
    this->tail = head;
}

//destructor
Queue::~Queue(){
    Node* current = head;

    //loop through the queue and delete every node in the queue
    while(current != nullptr){
        Node* temp = current;
        current = current->getNext();
        delete temp;
    }
}

//adds a new event to the tail of the queue
void Queue::enqueue(Event& event){

    //make a node for the event
    Node *node = new Node(event);

    //if the queue is empty set the head and tail to node
    if(isEmpty()){
        head = node;
        tail = node;
    } 

    //if the queue is not empty, insert the node to tail
    else {
        tail->setNext(node);
        tail = node;
    }
}

//removes the event from the front of the queue and returns it
Event* Queue::dequeue(){

    //return null if the queue is empty
    if(this->isEmpty()){
        return nullptr;
    }

    //clone the head's event for return
    Event *event = head->getEvent()->clone();

    //ready for delete the head
    Node *remove = head;

    //update the new head
    head = head->getNext();

    //update tail if the queue is empty
    if(head == nullptr){
        tail = head;
    }

    //delete the first node
    delete remove;

    //return the first event 
    return event;
}

//checks if the queue is empty and returns a boolean
bool Queue::isEmpty() const{
    return head == nullptr;
}

/*********** getters ***********/

Node* Queue::getHead() const{
    return head;
}

Node* Queue::getTail() const{
    return tail;
}

/*********** setters ***********/

void Queue::setHead(Node *head){
    this->head = head;
}

void Queue::setTail(Node *tail){
    this->tail = tail;
}