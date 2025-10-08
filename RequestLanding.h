//-----------------------------------------
// CLASS: RequestLanding
//
// REMARKS: This class represents a request landing event
//-----------------------------------------

#pragma once
#include "Request.h"

class RequestLanding:public Request{
    public:
        //constructor
        RequestLanding(Plane, int); 

        //copy constructor
        RequestLanding(const RequestLanding&); 

        //clone method, make a deep copy of an event
        RequestLanding* clone() override;

        //toString method, make the required message
        string toString() override;
};