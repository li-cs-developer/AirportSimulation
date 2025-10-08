#include "ClearRunway.h"

//constructor
ClearRunway::ClearRunway(Plane plane, int time, int runwayNum):
    EventOnRunway(plane, time, runwayNum)
{}

//copy constructor
ClearRunway::ClearRunway(const ClearRunway& other):
    EventOnRunway(other) 
{}

//clone method, make a deep copy of an event
ClearRunway* ClearRunway::clone(){
    return new ClearRunway(*this);
}

//toString method, make the required message
string ClearRunway::toString(){
    ostringstream string;
    string << " has cleared the runway " << getRunwayNum();  
    return Event::toString() + string.str();
}