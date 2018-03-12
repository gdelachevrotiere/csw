#ifndef COMMERCIALBUILDING_H_
#define COMMERCIALBUILDING_H_

#include "Building.h"

class CommercialBuilding: public Building {
	int income;
	vector<RessourceType> market;
public:
    CommercialBuilding(Cost, int);
	CommercialBuilding(Cost, vector<RessourceType>);
	virtual ~CommercialBuilding();

	int get_production(RessourceType) final;
    vector<RessourceType> get_market();
	Impact get_build_impact() final;
	string print() final;
};

#endif
