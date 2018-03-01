#ifndef BUILDING_H_
#define BUILDING_H_

#include "Globals.h"
#include "Cost.h"

class Building {
protected:
	Cost cost;
	int victoryPoints;
    bool available;
public:
    Building();
    virtual ~Building();

	Cost get_cost();
    int get_victory_points();
    virtual int get_production(RessourceType) = 0;
};

#endif
