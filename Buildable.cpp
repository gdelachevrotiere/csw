#include "Buildable.h"

Buildable::Buildable() {
    victoryPoints = 0;
    built = false;
    claimed = false;
}

Cost Buildable::get_cost() {
    return cost;
}

bool Buildable::is_built() {
    return built;
}

bool Buildable::is_claimed() {
    return claimed;
}

void Buildable::register_claim() {
    if (is_claimed()) {
        throw runtime_error("the buildable is already claimed");
    }
    claimed = true;
}

void Buildable::register_build() {
    if (is_built()) {
        throw runtime_error("the buildable is already built");
    }
    built = true;
}

int Buildable::get_victory_points() {
    return victoryPoints;
}

Impact Buildable::get_build_impact() {
    return [](Player* p){};
};

string Buildable::pretty_print() {
    stringstream sout;
    sout << print() << ": " << cost.print() << " -> victory[" << victoryPoints << "]";
    return sout.str();
}
