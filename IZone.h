#include "Zone.h"
using namespace std;
//Industrial zone and its code
#pragma once

class IZone : public Zone<IZone>
{
public:
	IZone(int y, int x, bool adjtoPL)
		:Zone(y, x, adjtoPL) {
	}

	bool STEP()
	{
		if (population == 0 && adjtoPowerLine) { return true; } //if populatiom is 0 and adj to powerlines return true
		else if (population == 0 && isadjwithPopulation(1, 1)) { return true; }//if populatiom is 0 and adj to 1 cell with pop. equal to 1 return true
		else if (population == 1 && isadjwithPopulation(2, 1)) { return true; }//if populatiom is 1 and adj to 2 cell with pop. equal to 1 return true
		else if (population == 2 && isadjwithPopulation(4, 2)) { return true; }//if populatiom is 2 and adj to 4 cell with pop. equal to 2 return true
		return false;// if none of the above return false
	}

	vector<Good*> getGoodsSoldable() {
		vector<Good*> g;
		vector<Good*>::iterator it;

		for (it = goods.begin(); it != goods.end(); it++)
		{
			if ((*it)->isSoldable())
				g.push_back(*(it));
		}

		return g;
	}

	void Implement() {
		++population; // incrase population
		goods.push_back(new Good());//increase goods
	}

private:
	vector<Good*> goods;
};

