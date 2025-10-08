#include "LandingAndTakeoff.h"

//constructor
LandingAndTakeoff::LandingAndTakeoff(Plane plane, int time, int runwayNum):
    EventOnRunway(plane, time, runwayNum)
{}

//copy constructor
LandingAndTakeoff::LandingAndTakeoff(const LandingAndTakeoff& other):
    EventOnRunway(other) 
{}

//clone method, make a deep copy of an event
LandingAndTakeoff* LandingAndTakeoff::clone(){
    return new LandingAndTakeoff(*this);
}

//toString method, make the required message
string LandingAndTakeoff::toString(){
    string requestType = requestTypes[this->getPlane().getRequestType()];
    ostringstream string;

    string << " cleared for " << requestType <<" on runway " << getRunwayNum() 
           << ". (time req. for " << requestType << ": " << getPlane().getTimeRequired() << ")";

    return Event::toString() + string.str();
}