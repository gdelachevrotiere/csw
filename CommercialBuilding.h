#ifndef COMMERCIALBUILDING_H_
#define COMMERCIALBUILDING_H_

#include "Building.h"

class CommercialBuilding final: public Building {
	int income;
	vector<RessourceType> market;
public:
    CommercialBuilding(Cost, int);
	CommercialBuilding(Cost, vector<RessourceType>);
	virtual ~CommercialBuilding();

	int get_production(RessourceType);
    vector<RessourceType> get_market();
	Impact get_build_impact();
	string print();
};

#endif
