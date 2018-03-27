#include "ScientificBuilding.h"

ScientificBuilding::ScientificBuilding(const Science& science, const int& victoryPoints) {
    this->science = science;
    this->victoryPoints = victoryPoints;
}

Science ScientificBuilding::get_science() {
    return science;
}

string ScientificBuilding::print() {
    stringstream sout;
    sout << "ScientificBuilding[" << util::print_science(science) << "]";
    return sout.str();
}

