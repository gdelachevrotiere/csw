#include "Building.h"

Building::Building(){
    victory_points = 0;
}

Cost Building::get_cost() {
	return cost;
}

int Building::get_victory_points() {
	return victory_points;
}

Building::~Building(){
    delete &cost, &victory_points;
}
