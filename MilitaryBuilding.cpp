#include "MilitaryBuilding.h"
#include "Player.h"

MilitaryBuilding::MilitaryBuilding(Cost cost, int strength) {
    this->cost = cost;
	this->strength = strength;
}

void MilitaryBuilding::resolve_build_impact() {
    owner->attack(strength);
}

string MilitaryBuilding::print() {
    stringstream sout;
    sout << "MilitaryBuilding[" << strength << "] ~ " << cost.print() << endl;
    return sout.str();
}

MilitaryBuilding::~MilitaryBuilding() {}

