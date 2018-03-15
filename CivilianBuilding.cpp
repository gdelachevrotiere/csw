#include "CivilianBuilding.h"

CivilianBuilding::CivilianBuilding(const int &victorypoints) {
    this->victoryPoints = victoryPoints;
};

string CivilianBuilding::print() {
    stringstream sout;
    sout << "CivilianBuilding[" << get_victory_points() << "]" << endl;
    return sout.str();
};