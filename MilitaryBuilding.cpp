#include "MilitaryBuilding.h"
#include "Player.h"
#include "lambda.h"

MilitaryBuilding::MilitaryBuilding(Cost cost, int strength) {
    this->cost = cost;
	this->strength = strength;
}

Impact MilitaryBuilding::get_build_impact() {
    return attack_impact(strength);
}

string MilitaryBuilding::print() {
    stringstream sout;
    sout << "MilitaryBuilding[" << strength << "] ~ " << cost.print() << endl;
    return sout.str();
}

MilitaryBuilding::~MilitaryBuilding() {}

