#ifndef SCIENTIFICBUILDING_H_
#define SCIENTIFICBUILDING_H_

#include "Building.h"

class ScientificBuilding final: public Building {
	Science science;
public:
	ScientificBuilding(const Science&, const int&);
	explicit ScientificBuilding(const Science& s): ScientificBuilding(s, 0) { };
	virtual ~ScientificBuilding() { };

	Science get_science();
};

#endif
