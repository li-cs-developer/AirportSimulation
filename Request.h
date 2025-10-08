//-----------------------------------------
// CLASS: Request
//
// REMARKS: This class represents a request event
//-----------------------------------------

#pragma once
#include "Event.h"

class Request:public Event{
    public:
        //constructor
        Request(Plane, int); 

        //copy constructor
        Request(const Request&); 

        //clone method, make a deep copy of an event
        Request* clone() override; 
};