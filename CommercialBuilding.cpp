#include "CommercialBuilding.h"
#include "Player.h"
#include "lambda.h"

CommercialBuilding::CommercialBuilding(Cost cost, vector<RessourceType> market) {
    this->cost = cost;
    this->income = 0;
    this->market = market;
}

CommercialBuilding::CommercialBuilding(Cost cost, int income) {
    this->cost = cost;
    this->income = income;
    this->market = vector<RessourceType>();
}

int CommercialBuilding::get_production(RessourceType) {
    return 0;
};

vector<RessourceType> CommercialBuilding::get_market() {
    return market;
}

Impact CommercialBuilding::get_build_impact() {
    return income_impact(income);
};

string CommercialBuilding::print() {
    stringstream sout;
    sout << "CommercialBuilding[" << "]";
    return sout.str();
};

CommercialBuilding::~CommercialBuilding() { }

