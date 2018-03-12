#ifndef WONDER_H_
#define WONDER_H_

#include "Globals.h"
#include "Buildable.h"

class Wonder: public Buildable {
	string name;
    vector<Impact> impacts;
public:
	Wonder(string, Cost, vector<Impact>);
	virtual ~Wonder();

    string get_name();
    int get_production(RessourceType) final;
    Impact get_build_impact() final;
	string print() final;
};

#endif
