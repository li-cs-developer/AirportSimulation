//-----------------------------------------
// CLASS: Simulation
//
//
//
// Author: Cathy Li, student number 7984285
// REMARKS: This class represents a Event Driven Simulation for WAA
//-----------------------------------------

#pragma once
#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>
#include <iostream>
#include "RequestLanding.h"
#include "RequestTakeoff.h"
#include "LandingAndTakeoff.h"
#include "ClearRunway.h"
#include "PriorityQueue.h"

class Simulation{
    private:
        //instances
        string filename; //filename to be processed
        int numRunways; //number of runways 
        Queue waitingLanding; //planes waiting for landing
        Queue waitingTakeoff; //planes waiting for takeoff
        PriorityQueue events; //all events
        int *runways; //all runways
        int currentATC_ID; //current ATC ID
        int timeWasted; //time wasted because runways were not available
        
        //------------------------------------------------------
        // getNextRequest
        //
        // PURPOSE: it reads the next line in the file and makes request event then returns it
        // PARAMETERS:
        // ifstream - the ifstream of the file to be read
        // Returns: a pointer of Event made from the read line
        //------------------------------------------------------
        Event* getNextRequest(ifstream&);


        //------------------------------------------------------
        // runwayAvailable
        //
        // PURPOSE: it determines if a runway is available 
        // PARAMETERS:
        // int - the runway number, expected to be from 1 to runwayNum (the class instance)
        // Returns: true if the runway is available, false if the runway is not available
        //------------------------------------------------------
        bool runwayAvailable(int);


        //------------------------------------------------------
        // assignRunway
        //
        // PURPOSE: it assigns a runway that is available to a plane
        // PARAMETERS: N/A
        // Returns: an available runway number
        //------------------------------------------------------
        int assignRunway();


        //------------------------------------------------------
        // findRequestType
        //
        // PURPOSE: it finds the corresponing enum value of a string request type
        // PARAMETERS:
        // string - request type, expected to be one of landing and takeoff
        // Returns: the corresponing enum value of the string request type
        //------------------------------------------------------
        int findRequestType(string);


        //------------------------------------------------------
        // findPlaneSize
        //
        // PURPOSE: it finds the corresponing enum value of a string plane size 
        // PARAMETERS:
        // string - plane size, expected to be one of small, large, heavy and super
        // Returns: the corresponing enum value of the string plane size 
        //------------------------------------------------------
        int findPlaneSize(string);

    public:
        //constructor
        Simulation(string, int);

        //destructor
        ~Simulation();  
};

