//-----------------------------------------
// CLASS: LandingAndTakeoff
//
//
//
// Author: Cathy Li, student number 7984285
// REMARKS: This class represents a landing or takeoff event
//-----------------------------------------

#pragma once
#include "EventOnRunway.h"

class LandingAndTakeoff:public EventOnRunway{
    public:
        //constructor
        LandingAndTakeoff(Plane, int, int); 

        //copy constructor
        LandingAndTakeoff(const LandingAndTakeoff&); 

        //clone method, make a deep copy of an event
        LandingAndTakeoff* clone() override; 

        //toString method, make the required message
        string toString() override;     
};