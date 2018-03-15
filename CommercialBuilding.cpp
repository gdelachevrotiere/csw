#include "CommercialBuilding.h"
#include "Player.h"

CommercialBuilding::CommercialBuilding(const Cost& cost, const int& income) {
    this->cost = cost;
    this->income = income;
    this->market = vector<RessourceType>();
}

CommercialBuilding::CommercialBuilding(const Cost& cost, const vector<RessourceType>& market) {
    this->cost = cost;
    this->income = 0;
    this->market = market;
}

vector<RessourceType> CommercialBuilding::get_market() {
    return market;
}

Impact CommercialBuilding::get_build_impact() {
    return lambda::income_impact(income);
};

string CommercialBuilding::print() {
    stringstream sout;
    sout << "CommercialBuilding[" << "] ~ " << cost.print() << endl;
    return sout.str();
};