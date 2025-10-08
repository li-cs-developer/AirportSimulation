//-----------------------------------------
// CLASS: Event
//
// REMARKS: This class represents an event for event driven simulation
//-----------------------------------------

#pragma once
#include <sstream> //necessary for using stringstream
#include <string>
#include "Plane.h"

extern string planeSizes[];

class Event{
    private: 
        Plane plane; //plane that participate the event
        int time; //time of the event occurs
    public:
        //constructors
        Event();
        Event(Plane, int);

        //destrcutor
        virtual ~Event(); 

        //copy constructor
        Event(const Event&); 

        //clone method, make a deep copy of an event
        virtual Event* clone();
        
        //toString method, make the required message
        virtual string toString();

        //getters
        Plane getPlane();
        int getTime();
};

