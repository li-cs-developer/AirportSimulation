#include "EventOnRunway.h"

//constructor
EventOnRunway::EventOnRunway(Plane plane, int time, int runwayNum):
    Event(plane, time), runwayNum(runwayNum)
{}

//copy constructor
EventOnRunway::EventOnRunway(const EventOnRunway& other):Event(other){
    this->runwayNum = other.runwayNum;
}

//clone method, make a deep copy of an event
EventOnRunway* EventOnRunway::clone(){
    return new EventOnRunway(*this);
}

/*********** getters ***********/

int EventOnRunway::getRunwayNum(){
    return runwayNum;
}