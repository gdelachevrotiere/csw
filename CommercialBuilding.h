#ifndef COMMERCIALBUILDING_H_
#define COMMERCIALBUILDING_H_

#include "Building.h"

class CommercialBuilding final: public Building {
	int income;
	vector<RessourceType> market;
public:
    CommercialBuilding(const Cost&, const int&);
	CommercialBuilding(const Cost&, const vector<RessourceType>&);
	virtual ~CommercialBuilding() { };

    vector<RessourceType> get_market();
	Impact get_build_impact();
	string print();
};

#endif
