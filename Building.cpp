#include "Building.h"

Building::Building(){
    victoryPoints = 0;
    available = false;
}

Cost Building::get_cost() {
	return cost;
}

void Building::set_owner(shared_ptr<Player> owner) {
    this->owner = owner;
    available = false;
}

int Building::get_victory_points() {
	return victoryPoints;
}


Building::~Building(){ }
