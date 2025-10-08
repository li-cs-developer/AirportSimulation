#include "Simulation.h"

//constructor
Simulation::Simulation(string filename, int numRunways){
    //return if the runway number is not a positve integer
    runways = nullptr;
    if(numRunways <= 0){
        cout << "\nSimulation Failed Becasue Number of Runways Is Not A Positive Integer!" 
             << "Please Try Again!\n" << endl;
        return;
    }

    //open the file
    ifstream inputFile;
	inputFile.open(filename); 

    //return if the file is not found
    if(!inputFile.is_open()){
        cout << "Simulation Failed Becasue File Not Found! Please Try Again!" << endl;
        return;
    }

    //assign and initialize class instances
    this->filename = filename;
    this->numRunways = numRunways;
    runways = new int[numRunways]();
    currentATC_ID = 0;
    timeWasted = 0;
    
    //print simulation begins
    cout << "\nSimulation begins..." << endl; 

    //read the first line, make an event from it, and enqueue it to the event queue
    Event *event = getNextRequest(inputFile);
    if(event == nullptr){
        cout << "\nNo Events" << endl;
        return; 
    }
    events.enqueue(*event);
    delete event;
    
    //while the event queue is not empty, process the event 
	while(!events.isEmpty()){  
        //dequeue the event and print it
        event = events.dequeue();
        cout << event->toString() << endl;

        //assign needed varibale for later use
        Plane plane = event->getPlane();
        int time = event->getTime();
        int runwayNum;
        
        //process reuqest events
        if(dynamic_cast<Request*>(event)){
            //if the runway is available 
            if(runwayAvailable(event->getTime())){
                //assign a runway number to the plane
                runwayNum = assignRunway();

                //update the runway availibility
                runways[runwayNum-1] = time + plane.getTimeRequired();

                //make a landing or takeoff event with current time and put it into the events queue
                delete event;
                event = new LandingAndTakeoff(plane, time, runwayNum);
                events.enqueue(*event);
            }

            //if the runway is not available 
            else{

                //if it's a request landing event
                if(dynamic_cast<RequestLanding*>(event)){
                    //put the event into the waiting line for landing 
                    waitingLanding.enqueue(*event);
                }

                //if it's a request takeoff event
                else{
                    //put the event into the waiting line for landing 
                    waitingTakeoff.enqueue(*event);
                }
            }

            //read the next line and make an event from it
            delete event;
            event = getNextRequest(inputFile);

            //if there is a next event
            if(event != nullptr){
                //put the event into the events queue
                events.enqueue(*event);
                delete event;
            }
        }

        //process landing and takeoff events
        else if(dynamic_cast<LandingAndTakeoff*>(event)){
            //cout << "process landing/takeoff, create departure" << endl;
            int runwayNum = static_cast<LandingAndTakeoff*>(event)->getRunwayNum();
            int departureTime = time + plane.getTimeRequired();
            delete event;
            event = new ClearRunway(plane, departureTime, runwayNum);
            events.enqueue(*event);
            delete event;
        }

        //process clear runway (departure) events
        else if(dynamic_cast<ClearRunway*>(event)){
            //store the needed variables for later use
            int currentTime = time;
            runwayNum = static_cast<ClearRunway*>(event)->getRunwayNum();

            //clear the event pointer for later use
            delete event;
            event = nullptr;

            //if waiting line for landing is not empty
            if(!waitingLanding.isEmpty()){
                //dequeue next event from landing waiting line 
                event = waitingLanding.dequeue();
            }

            //if waiting line for landing is empty but waiting line for takeoff is not empty
            else if(!waitingTakeoff.isEmpty()){
                //dequeue next event from takeoff waiting line 
                event = waitingTakeoff.dequeue();
            }

            //if there is a next event
            if(event != nullptr){
                //store values needed for later use
                plane = event->getPlane();
                time = event->getTime();

                //calculate the time wasted because runways were not available
                timeWasted += (currentTime - time);
                runways[runwayNum-1] = currentTime + plane.getTimeRequired();

                //make a landing or takeoff event and put it into the event queue
                delete event;
                event = new LandingAndTakeoff(plane, currentTime, runwayNum);
                events.enqueue(*event);
                delete event;
            }
        } 
    }
    
    
    delete event; //free dynamic allocated memories
    
        
    //print results at the end
    cout << "\n#######################" << endl;  
    cout << "The simulation has ended." << endl;

    ostringstream runwayInfo;
    runwayInfo << "The number of runways was " << numRunways << ".";
    cout << runwayInfo.str() << endl;

    ostringstream timeInfo;
    timeInfo << "The total amount of time wasted because runways were not available was " 
             << timeWasted << " minutes.";
    cout << timeInfo.str() << endl;
    cout << "#######################\n" << endl;

}

//destructor
Simulation::~Simulation(){
    if(runways != nullptr){
        delete []runways;
        runways = nullptr;
    } 
}

//------------------------------------------------------
// getNextRequest
//
// PURPOSE: it reads the next line in the file and makes request event then returns it
// PARAMETERS:
// ifstream - the ifstream of the file to be read
// Returns: a pointer of Event made from the read line
//------------------------------------------------------
Event* Simulation::getNextRequest(ifstream& inputFile){
    string line;

    //if there is next line
    if(getline(inputFile, line)){
        //increment the current ATC ID
        currentATC_ID++;

        //stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
		stringstream sst(line);  
		string token;
		string callSign = "";
		string flightNum = "";
		string size = "";
		string requestType = "";
		
		sst >> token;  //grabbing the next token (reading time)
		int time = stoi(token); //converting time (string format) to an int
		sst >> callSign;  //grabbing the next token (reading call sign)
		sst >> flightNum;  //grabbing the next token (reading flight number)
		sst >> size;  //grabbing the next token (reading plane size)
        //grabbing the next token (reading request type, either landing or takeoff)
		sst >> requestType;  

        //make a plane with the extracted data
        Plane plane = Plane(callSign+" "+flightNum, findRequestType(requestType), 
                            findPlaneSize(size), currentATC_ID);

        //if the plane is requesting for landing 
        if(plane.isLanding()){
            //return a RequestLanding event
            return new RequestLanding(plane, time);
        } 

        //if the plane is requesting for takeoff
        else{
            //return a RequestTakeoff event
            return new RequestTakeoff(plane, time);
        }
    }

    //if there is no next line
    else{
        return nullptr; 
    }
}

//------------------------------------------------------
// runwayAvailable
//
// PURPOSE: it determines if a runway is available 
// PARAMETERS:
// int - the runway number, expected to be from 1 - runwayNum (the class instance)
// Returns: true if the runway is available, false if the runway is not available
//------------------------------------------------------
bool Simulation::runwayAvailable(int time){
    //loop the runways 
    for(int i=0; i<numRunways; i++){
        //return true if the time in a runway is less than the current time
        if(runways[i] < time){
            return true;
        }
    }
    //return false if all times in runways are greater than the current time
    return false;
}

//------------------------------------------------------
// assignRunway
//
// PURPOSE: it assigns a runway that is available to a plane
// PARAMETERS: N/A
// Returns: an available runway number
//------------------------------------------------------
int Simulation::assignRunway(){
    //initilize needed variables for later use
    int runway = 0; 
    int min = runways[0]; 

    //loop the runways
    for(int i=1; i<numRunways; i++){
        //if one runway time is less than the current minimum time runway
        if(runways[i] < min){
            //change the minimum time runway to the runways[i]
            min = runways[i];
            runway = i;
        }
    }

    //return the runway number, plus 1 since the runway number starts at 1
    return runway+1;
}

//------------------------------------------------------
// findRequestType
//
// PURPOSE: it finds the corresponing enum value of a string request type
// PARAMETERS:
// string - request type, expected to be one of landing and takeoff
// Returns: the corresponing enum value of the string request type
//------------------------------------------------------
int Simulation::findRequestType(string type){
    //if the request type equals takeoff
    if(type == requestTypes[TAKEOFF]){
        //return enum value of takeoff
        return TAKEOFF;
    }

    //if the request type equals landing
    else{
        //return enum value of landing
        return LANDING;
    }
}

//------------------------------------------------------
// findPlaneSize
//
// PURPOSE: it finds the corresponing enum value of a string plane size 
// PARAMETERS:
// string - plane size, expected to be one of small, large, heavy and super
// Returns: the corresponing enum value of the string plane size 
//------------------------------------------------------
int Simulation::findPlaneSize(string size){
    //initilize needed variables for later use
    int planeSize = 0;
    const int NUM_SIZES = 4;

    //loop through planeSizes array 
    for(int i=0; i<NUM_SIZES; i++){
        //if the size matches the size in planeSizes array 
        if(planeSizes[i] == size){
            //return the corresponding enum value and exit the loop
            planeSize = i;
            break;
        }
    }

    //return the corresponding enum value
    return planeSize;
}

