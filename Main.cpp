//-----------------------------------------
// REMARKS: build an event-driven simulation program that will help estimate the effect of having x 
//          number of available runways on the total time wasted by planes waiting for an available 
//          runway, depending on a provided scenario of planes requesting to land/takeoff
//-----------------------------------------

#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>
#include <iostream>
#include "Simulation.h"

int main(int argc, char* argv[]){
    //if the number of command line argument is not 3, terminate the program
    if(argc != 3){
		cout<<"Invalid Commandline Arguments!" << endl;
		cout<<"Please Enter The Filename At argv[1] And Number of Runways At argv[2]"<<endl;
		return 1;
	}

    //assgin argve[1] to filename
	string filename = argv[1];

    //assgin argve[2] to number of runways 
	int numRunways;
    try{
        //try to convert argv[2] to an integer
        numRunways = stoi(argv[2]);
    } 
    catch(const exception& e){
        //print error message if it fails
        cout << "Error: Please Enter An Integer At argv[2]." << endl;
        return 1;
    }

    //create a simulation with the input filename and number of runways
    Simulation simulation = Simulation(filename, numRunways);

    //print the End of the Program message
    cout << "-------- End of the Program --------\n" << endl;
    return 0;
}