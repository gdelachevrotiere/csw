#include "Wonder.h"

using namespace std::placeholders;

Wonder::Wonder(
    const string& name,
    const Cost& cost,
    const vector<RessourceType>& sharedProduction,
    const vector<Impact> &impacts
) {
    this->name = name;
	this->cost = cost;
    this->impacts = impacts;
    this->sharedProduction = sharedProduction;
}

string Wonder::get_name() {
    return name;
}

string Wonder::print() {
    stringstream sout;
    sout << "Wonder[" << name << "] ~ " << get_cost().print();
    return sout.str();
}

vector<RessourceType> Wonder::get_shared_production() {
    return is_built() ? sharedProduction: vector<RessourceType>();
}

Impact Wonder::get_build_impact() {
    return lambda::multi_impact(impacts);
};

