#include "Plane.h"

//default constructor
Plane::Plane():flightNum(""), requestType(0), planeSize(0), ATC_ID(0){}

//constructor
Plane::Plane(string flightNum, int requestType, int planeSize, int ATC_ID){
    this->flightNum = flightNum;
    this->requestType = requestType;
    this->planeSize = planeSize;
    this->ATC_ID = ATC_ID;
    timeRequired = requestType + planeSize;
}

//------------------------------------------------------
// isLanding
//
// PURPOSE: it determines if the plane's request type is landing
// PARAMETERS: N/A
// Returns: true if the request type is landing, false if the request type is takeoff
//------------------------------------------------------
bool Plane::isLanding() const{
    return this->requestType == LANDING;
}

/*********** getters ***********/

string Plane::getFlightNum() const{
    return flightNum;
}

int Plane::getRequestType() const{
    return requestType;
}

int Plane::getPlaneSize() const{
    return planeSize;
}

int Plane::getATC_ID() const{
    return ATC_ID;
}

int Plane::getTimeRequired() const{
    return timeRequired;
}