#ifndef MILITARYBUILDING_H_
#define MILITARYBUILDING_H_

#include "Building.h"
#include "ConflictZone.h"

class MilitaryBuilding: public Building {
	int strength;
public:
    MilitaryBuilding(Cost c, int i);
	virtual ~MilitaryBuilding();

    int get_production(RessourceType) final { return 0; };
    Impact get_build_impact() final;
    string print();
};

#endif
