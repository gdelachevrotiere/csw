#include "Wonder.h"
using namespace std;

Wonder::Wonder(string name, array<int, 5> cost, vector<Impact> impacts) {
	this->name = name;
	this->cost.insert( pair<RessourceType,int>(wood,  cost.at(0)) );
	this->cost.insert( pair<RessourceType,int>(stone, cost.at(1)) );
	this->cost.insert( pair<RessourceType,int>(clay,  cost.at(2)) );
	this->cost.insert( pair<RessourceType,int>(glass, cost.at(3)) );
	this->cost.insert( pair<RessourceType,int>(paper, cost.at(4)) );
	built = false;
}

map<RessourceType,int> Wonder::get_cost() {
    return cost;
}

void Wonder::build() {
	built = true;
}

bool Wonder::is_built() {
	return built;
}

Wonder::~Wonder() {

}

