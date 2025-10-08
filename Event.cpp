#include "Event.h"

//default constructor
Event::Event():plane(Plane("", 0, 0, 0)), time(0){}

//default destructor
Event::~Event(){}

//constructor
Event::Event(Plane plane, int time){
    this->plane = plane;
    this->time = time;
}

//copy constructor
Event::Event(const Event& other){
    this->plane = other.plane;
    this->time = other.time;
}

//clone method, make a deep copy of an event
Event* Event::clone(){
    return new Event(*this);
}

//toString method, make the required message
string Event::toString(){
    ostringstream string;
    
    string << "TIME: " << time << " -> " <<  plane.getFlightNum() << " (" << plane.getATC_ID() 
           << ") " << planeSizes[this->getPlane().getPlaneSize()];

    return string.str();
}

/*********** getters ***********/

Plane Event::getPlane(){
    return plane;
}

int Event::getTime(){
    return time;
}