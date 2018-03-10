#ifndef WONDER_H_
#define WONDER_H_

#include "Globals.h"
#include "Impact.h"
#include "Cost.h"

class Wonder {
	string name;
	bool built;
	Cost cost;
public:
	Wonder(string, Cost, vector<Impact>);
	virtual ~Wonder();

	void build();
    string get_name();
	Cost get_cost();
	bool is_built();
};

#endif
