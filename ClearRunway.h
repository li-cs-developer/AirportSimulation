//-----------------------------------------
// CLASS: ClearRunway
//
// REMARKS: This class represents a clear runway event (departure)
//-----------------------------------------

#pragma once
#include "EventOnRunway.h"

class ClearRunway:public EventOnRunway{
    public:
        //constructor
        ClearRunway(Plane, int, int); 

        //copy constructor
        ClearRunway(const ClearRunway&); 

        //clone method, make a deep copy of an event
        ClearRunway* clone() override; 

        //toString method, make the required message
        string toString() override; 
};

