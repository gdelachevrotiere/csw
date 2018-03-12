#include "Wonder.h"
#include "lambda.h"

using namespace std::placeholders;

Wonder::Wonder(string name, Cost cost, vector<Impact> impacts) {
    this->name = name;
	this->cost = cost;
    this->impacts = impacts;
}

string Wonder::get_name() {
    return name;
}

string Wonder::print() {
    stringstream sout;
    sout << "Wonder[" << name << "] ~ " << get_cost().print();
    return sout.str();
}

int Wonder::get_production(RessourceType ressource_type) {
    return 0;
}

Impact Wonder::get_build_impact() {
    return multi_impact(impacts);
};

Wonder::~Wonder() { }

