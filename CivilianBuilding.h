#ifndef CIVILIANBUILDING_H_
#define CIVILIANBUILDING_H_

#include "Building.h"

class CivilianBuilding final: public Building {
public:
	CivilianBuilding(const Cost&, const int& victorypoints);
	virtual ~CivilianBuilding() { };

	string print();
};

#endif
