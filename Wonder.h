#ifndef WONDER_H_
#define WONDER_H_

#include "Globals.h"
#include "Buildable.h"
#include "Impact.h"

class Wonder: public Buildable {
	string name;
    vector<shared_ptr<Impact>> impacts;
public:
	Wonder(string, Cost, vector<shared_ptr<Impact>>);
	virtual ~Wonder();

    string get_name();
    int get_production(RessourceType) final;
    void resolve_build_impact() final;
	string print() final;
};

#endif
