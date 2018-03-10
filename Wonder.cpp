#include "Wonder.h"

Wonder::Wonder(string name, Cost cost, vector<Impact> impacts) {
    this->name = name;
	built = false;
	this->cost = cost;
}

Cost Wonder::get_cost() {
    return cost;
}

void Wonder::build() {
	built = true;
}

string Wonder::get_name() {
    return name;
}

bool Wonder::is_built() {
	return built;
}

Wonder::~Wonder() {

}

