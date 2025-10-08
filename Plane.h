//-----------------------------------------
// CLASS: Plane
//
// REMARKS: This class represents a Plane requests landing or takeoff at YWG
//-----------------------------------------

#pragma once
#include <string>
#include "GlobalEnums.h"
using namespace std;
#include "GlobalVariables.h" 
extern string requestTypes[];


class Plane{
    private: 
        //flight number (eg. "Delta 1243", "AirCanada 973",etc)
        string flightNum; 
        //requets type enum value (LANDING == 3 or TAKEOFF == 1)
        int requestType; 
        //plane size enum value (SAMLL == 0, LARGE == 1, HEAVY == 2, SUPER == 3)
        int planeSize; 
        //ATC ID
        int ATC_ID; 
        //time required for process
        int timeRequired; 
        
    public:
        //constructors
        Plane();
        Plane(string, int, int, int);

        //------------------------------------------------------
        // isLanding
        //
        // PURPOSE: it determines if the plane's request type is landing
        // PARAMETERS: N/A
        // Returns: true if the request type is landing, false if the request type is takeoff
        //------------------------------------------------------
        bool isLanding() const;

        //getters
        string getFlightNum() const;
        int getRequestType() const;
        int getPlaneSize() const;
        int getATC_ID() const;
        int getTimeRequired() const;
        
};
