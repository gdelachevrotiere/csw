#ifndef WONDER_H_
#define WONDER_H_

#include "Globals.h"
#include "Buildable.h"
#include "Impact.h"

class Wonder: public Buildable {
	string name;
public:
	Wonder(string, Cost, vector<Impact>);
	virtual ~Wonder();

    string get_name();
    int get_production(RessourceType) final;
    void resolve_build_impact() final;
	string print() final;
};

#endif
