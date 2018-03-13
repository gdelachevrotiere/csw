#ifndef MILITARYBUILDING_H_
#define MILITARYBUILDING_H_

#include "Building.h"
#include "ConflictZone.h"

class MilitaryBuilding final: public Building {
	int strength;
public:
    MilitaryBuilding(Cost c, int i);
	virtual ~MilitaryBuilding();

    Impact get_build_impact();
    string print();
};

#endif
