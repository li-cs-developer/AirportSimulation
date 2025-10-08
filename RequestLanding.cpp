#include "RequestLanding.h"

//constructor
RequestLanding::RequestLanding(Plane plane, int time):
    Request(plane, time)
{}

//copy constructor
RequestLanding::RequestLanding(const RequestLanding& other): 
    Request(other) 
{}

//clone method, make a deep copy of an event
RequestLanding* RequestLanding::clone(){
    return new RequestLanding(*this);
}

//toString method, make the required message
string RequestLanding::toString(){
    return Event::toString() + " inbound for landing.";
}

