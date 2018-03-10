#include "Wonder.h"
#include "Impact.h"

Wonder::Wonder(string name, Cost cost, vector<Impact> impacts) {
    this->name = name;
	this->cost = cost;
}

string Wonder::get_name() {
    return name;
}

string Wonder::print() {
    stringstream sout;
    sout << "Wonder[" << name << "] ~ " << get_cost().print();
    return sout.str();
}

int Wonder::get_production(RessourceType ressource_type) { return 0; }

void Wonder::resolve_build_impact() { };

Wonder::~Wonder() { }

