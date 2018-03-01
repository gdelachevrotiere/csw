#include "Building.h"

Building::Building(){
    victoryPoints = 0;
    available = false;
}

Cost Building::get_cost() {
	return cost;
}

int Building::get_victory_points() {
	return victoryPoints;
}

Building::~Building(){ }
