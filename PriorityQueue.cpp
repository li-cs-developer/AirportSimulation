#include "PriorityQueue.h"

//adds a new event to the queue, prioritizes time then ATC ID
void PriorityQueue::enqueue(Event& event){
    
    //make a new node to store the event
    Node* node = new Node(event);

    //if the queue is empty, insert at the head
    if (isEmpty()){
        setHead(node);
        setTail(node);
        return;
    }

    //needed varibale for traversing the queue
    Node* current = getHead();
    Node* previous = nullptr;

    //traverse the queue to find the correct insertion point
    while (current != nullptr){
        //prioritize by time first
        if (event.getTime() < current->getEvent()->getTime()){
            break;
        }
        //if times are the same, prioritize by ATC_ID
        else if(event.getTime() == current->getEvent()->getTime() &&
                event.getPlane().getATC_ID() < current->getEvent()->getPlane().getATC_ID()){
            break;
        }
        
        //move to the next node
        previous = current;
        current = current->getNext();
    }

    //previous is null
    if(previous == nullptr){
        //insert at the head
        node->setNext(getHead());
        setHead(node);
    } 

    ////previous is not null
    else{
        //insert at the correct position
        previous->setNext(node);
        node->setNext(current);
    }

    //update tail if inserted at the end
    if(node->getNext() == nullptr){
        setTail(node);
    }
    
}