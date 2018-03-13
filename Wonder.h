#ifndef WONDER_H_
#define WONDER_H_

#include "Globals.h"
#include "Buildable.h"

class Wonder final: public Buildable {
	string name;
    vector<Impact> impacts;
public:
	Wonder(string, Cost, vector<Impact>);
	virtual ~Wonder();

    string get_name();
    int get_production(RessourceType);
	vector<RessourceType> get_shared_production();
    Impact get_build_impact();
	string print();
};

#endif
