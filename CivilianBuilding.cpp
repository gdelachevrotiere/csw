#include "CivilianBuilding.h"

CivilianBuilding::CivilianBuilding(const Cost& cost, const int &victorypoints) {
    this->victoryPoints = victoryPoints;
    this->cost = cost;
};

string CivilianBuilding::print() {
    stringstream sout;
    sout << "CivilianBuilding[" << get_victory_points() << "]";
    return sout.str();
};
