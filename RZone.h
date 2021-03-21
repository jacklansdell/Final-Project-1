#include "Zone.h"

#pragma once
// Residential area and its functions
class RZone : public Zone<RZone>
{
public:
	RZone(int y, int x, bool adjtoPL)
		:Zone(y, x, adjtoPL) {
	}

	vector<Worker*> getWorkersAvailable()
	{
		vector<Worker*> w;
		vector<Worker*>::iterator it;

		for (it = workers.begin(); it != workers.end(); it++)
		{
			if ((*it)->isAvailable())
				w.push_back(*(it));
		}

		return w;
	}
	bool STEP()
	{
		if (population == 0 && adjtoPowerLine) { return true; } //if populatiom is 0 and adj to powerlines return true
		else if (population == 0 && isadjwithPopulation(1, 1)) { return true; } //if population is 0 and if adj. to 1 cell with pop. equal to 1 return true
		else if (population == 1 && isadjwithPopulation(2, 1)) { return true; } //if population is 1 and if adj. to 2 cell with pop. equal to 1 return true
		else if (population == 2 && isadjwithPopulation(4, 2)) { return true; } //if population is 2 and if adj. to 4 cell with pop. equal to 2 return true
		else if (population == 3 && isadjwithPopulation(6, 3)) { return true; } //if population is 3 and if adj. to 6 cell with pop. equal to 3 return true
		else if (population == 4 && isadjwithPopulation(8, 4)) { return true; } //if population is 4 and if adj. to 8 cell with pop. equal to 4 return true
		return false; // if none of the above return false
	}

	void Implement() { 
		++population;
		workers.push_back(new Worker()); // add worker
	}

private:
	vector<Worker*> workers;
};