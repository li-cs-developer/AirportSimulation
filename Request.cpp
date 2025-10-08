#include "Request.h"

//constructor
Request::Request(Plane plane, int time):
    Event(plane, time)
{}

//copy constructor
Request::Request(const Request& other): 
    Event(other) 
{}

//clone method, make a deep copy of an event
Request* Request::clone(){
    return new Request(*this);
}