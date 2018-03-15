#ifndef CIVILIANBUILDING_H_
#define CIVILIANBUILDING_H_

#include "Building.h"

class CivilianBuilding final: public Building {
public:
	CivilianBuilding(const int& victorypoints);
	virtual ~CivilianBuilding() { };

	string print();
};

#endif
