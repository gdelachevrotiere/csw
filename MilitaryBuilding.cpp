#include "MilitaryBuilding.h"
#include "Player.h"

MilitaryBuilding::MilitaryBuilding(Cost cost, int strength) {
    this->cost = cost;
	this->strength = strength;
}

void MilitaryBuilding::resolve_build_impact() {
    owner->attack(strength);
}

void MilitaryBuilding::print() {
    cout << "MilitaryBuilding[" << strength << "] ~ ";
    cost.print();
    cout << endl;
}

MilitaryBuilding::~MilitaryBuilding() {}

