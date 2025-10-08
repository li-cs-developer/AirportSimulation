//-----------------------------------------
// CLASS: PriorityQueue
//
// REMARKS: This class represents a priority queue ADT, it prioritizes time then ATC ID
//-----------------------------------------

#pragma once
#include "Queue.h"

class PriorityQueue:public Queue{
    public:
        //adds a new event to the queue, prioritizes time then ATC ID
        void enqueue(Event&) override;
};