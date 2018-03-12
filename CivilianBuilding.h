#ifndef CIVILIANBUILDING_H_
#define CIVILIANBUILDING_H_

#include "Building.h"

class CivilianBuilding: public Building {
public:
	CivilianBuilding();
	virtual ~CivilianBuilding();

	int get_production(RessourceType) final { return 0; };
	Impact get_build_impact() final { return [](Player*){}; };
	string print() final { return "dummy"; };
};

#endif
