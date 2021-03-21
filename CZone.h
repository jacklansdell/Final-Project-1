#include "Zone.h"
#pragma once

class CZone : public Zone<CZone>
{
public:
	CZone(int y, int x, bool adjtoPL)
		:Zone(y, x, adjtoPL) {}

	bool STEP()
	{
		if (population == 0 && adjtoPowerLine) { return true; }//if populatiom is 0 and adj to powerlines return true
		else if (population == 0 && isadjwithPopulation(1, 1)) { return true; }//if populatiom is 0 and adj to 1 cell with pop. equal to 1 return true
		else if (population == 1 && isadjwithPopulation(2, 1)) { return true; }//if populatiom is 0 and adj to 2 cell with pop. equal to 1 return true
		return false;// if none of the above return false
	}

	void Implement() {
		++population;
	}
};
