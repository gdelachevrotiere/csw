#ifndef MILITARYBUILDING_H_
#define MILITARYBUILDING_H_

#include "Building.h"

class MilitaryBuilding: public Building {
	int strength;
public:
    MilitaryBuilding(Cost c, int i);
	virtual ~MilitaryBuilding();

    int get_production(RessourceType) { return 0; };
    void resolve_build_impact();
    void print();
};

#endif
