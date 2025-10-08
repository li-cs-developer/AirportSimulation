//-----------------------------------------
// CLASS: EventOnRunway
//
// REMARKS: This class represents an event on runway
//-----------------------------------------

#pragma once
#include "Event.h"

class EventOnRunway:public Event{
    private:
        int runwayNum; //runway number assigned to the event
    public:
        //constructor
        EventOnRunway(Plane, int, int); 

        //copy constructor
        EventOnRunway(const EventOnRunway&); 

        //clone method, make a deep copy of an event
        EventOnRunway* clone() override;

        //getter
        int getRunwayNum();
};