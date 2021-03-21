#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cmath>
#include <queue>

#include "Good.h"
#include "Worker.h"
#include "CZone.h"
#include "IZone.h"
#include "RZone.h"
using namespace std;

#pragma once

class City
{
public:

    City(string filename);
    ~City();

    int refresh_rate, time_limit;
    char* regionName;

    int getWidth() {return this->width;}
    int getLength() { return this->length; }
    void display();
    void displayPollution();
    vector<Worker*> getAvailWorkers();
    vector<Good*> getSoldableGoods();

    int getRPopulation(int, int, int, int);
    int getCPopulation(int, int, int, int);
    int getIPopulation(int, int, int, int);
    
    int getTotalPollution(int, int, int, int);

    bool SimulateOneStep(int);

private:
    vector<CZone*> czones;
    vector<IZone*> izones;
    vector<RZone*> rzones;

    int length, width;
    const static int MAX_DIM = 50;
    char layout[MAX_DIM][MAX_DIM];
    int pollution[MAX_DIM][MAX_DIM];

    template<class Z>void PriorityImplementation(vector<Z*>, vector<Z*>* zones);
    template<class Z>void PriorityImplementation2(vector<Z*>, vector<Z*>* zones);
    template<class Z>void PriorityImplementation3(vector<Z*>, vector<Z*>* zones);
    template<class Z>void PriorityImplementation4(vector<Z*>, vector<Z*>* zones);
    void ImplementPrioritizedCZones();
    void ImplementPrioritizedIZones();
    void ImplementPrioritizedRZones();

    void InitializeZones();
    void PrepareLayout();
    void InitPollution();
    void CreateAdjacency();
    void Pollute();
    void PolluteNode(int, int, int);
    bool adjtoPowerLine(int, int);
    bool isAccessiblebyRoads(int, int);
    bool haschanged(char[MAX_DIM][MAX_DIM]);

};

