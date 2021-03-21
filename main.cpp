#include <iostream>
#include <fstream>
#include "City.h"

using namespace std;

int main()
{
  //user input config file
    string config_filename;
    bool isdiff;
    cout << "Beginning simulation" << endl;
    cout << "Please enter the name of the configuration file: ";
    cin >> config_filename;
    //prasing configfile string to City class
    City city(config_filename);
    //Display initial region
    cout << "Initial Region State" << endl;
    city.display();
    
    //starting simulation using for loop and time_limit
    for (int s = 0; s < city.time_limit; s++) {
        
        isdiff = city.SimulateOneStep(s);

        if (!isdiff)break;
        cout << endl;
    }

    //Display final region
    cout << "Final Region State" << endl;
    city.display();
    //display pollution
    cout << "Pollution" << endl;
    city.displayPollution();
    //display total population
    cout << "The total populations for the region are :" << endl;
    cout << "Residential: " << city.getRPopulation(0, 0, city.getLength() - 1, city.getWidth() - 1) << endl;
    cout << "Industrial: " << city.getIPopulation(0, 0, city.getLength() - 1, city.getWidth() - 1) << endl;
    cout << "Commercial: " << city.getCPopulation(0, 0, city.getLength() - 1, city.getWidth() - 1) << endl;

    //display total pollition in region   
    cout << "The total amount of pollution in the region is " 
        << city.getTotalPollution(0, 0, city.getLength() - 1, city.getWidth() - 1) 
        << " units." << endl;

    cout << "Please enter the diagonal corners of the area you wish to have more information about. (";
    cout<<"MinX = 0, MinY = 0, MaxX = "<<city.getLength() - 1<<", MaxY = "<<city.getWidth() - 1<<")"<<endl;
    //cin diaonal corners to get cross section
    int x1, y1, x2, y2;
    cout << "X1: "; cin >> x1;
    cout << "Y1: "; cin >> y1;
    cout << "X2: "; cin >> x2;
    cout << "Y2: "; cin >> y2;

    //display population using diagonal coordinates.
    cout << "The total populations for the requested area are: " << endl;
    cout << "Residential: " << city.getRPopulation(x1, y1, x2, y2) << endl;
    cout << "Industrial: " << city.getIPopulation(x1, y1, x2, y2) << endl;
    cout << "Commercial: " << city.getCPopulation(x1, y1, x2, y2) << endl;
    //display pollution using diagonal coordinates
    cout << "The total amount of pollution for the requested area is "
        << city.getTotalPollution(x1, y1, x2, y2) << " units." << endl;

    cout << "Simulation Complete!" << endl;
    return 0;
}//main

