#include "RequestTakeoff.h"

//constructor
RequestTakeoff::RequestTakeoff(Plane plane, int time):
    Request(plane, time)
{}

//copy constructor
RequestTakeoff::RequestTakeoff(const RequestTakeoff& other): 
    Request(other) 
{}

//clone method, make a deep copy of an event
RequestTakeoff* RequestTakeoff::clone(){
    return new RequestTakeoff(*this);
}

//toString method, print required messages
string RequestTakeoff::toString(){
    return Event::toString() + " ready for takeoff.";
}