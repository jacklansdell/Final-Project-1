#include <vector>
#include <iterator>
using namespace std;

#pragma once

template <class Z>
class Zone
{
public:

	Zone(int y, int x, bool adjtoPL)
	{
		this->adjtoPowerLine = adjtoPL;
		this->population = 0;
		this->x = x;
		this->y = y;
	}

	void addAdjs(Z* adjs)
	{
		this->adjacents.push_back(adjs);
	}

	int getX(){return this->x;}
	int getY(){return this->y;}
	int getPopulation(){return this->population;}

	int getAdjPopulation() {
		int p = 0;
		typename vector<Z*>::iterator it;
		for (it = adjacents.begin(); it != adjacents.end(); it++) {
			p = p + (*it)->getPopulation();
		}
		return p;
	}

protected:
	int x, y;
	vector<Z*> adjacents;
	int population;
	bool adjtoPowerLine;

	bool isadjwithPopulation(int nZones, int p)
	{
		int count = 0;
		typename vector<Z*>::iterator it;
		for (it = adjacents.begin(); it != adjacents.end(); it++)
		{
			if ((*it)->getPopulation() >= p)
				count += 1;
		}

		if (count >= nZones)return true;
		else return false;
	}
};
