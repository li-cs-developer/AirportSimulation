//-----------------------------------------
// CLASS: RequestTakeoff
//
// REMARKS: This class represent a request takeoff event
//-----------------------------------------

#pragma once
#include "Request.h"

class RequestTakeoff:public Request{
    public:
        //constructor
        RequestTakeoff(Plane, int); 

        //copy constructor
        RequestTakeoff(const RequestTakeoff&); 
        
        //clone method, make a deep copy of an event
        RequestTakeoff* clone() override;

        //toString method, print required messages
        string toString() override;
};