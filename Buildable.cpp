#include "Buildable.h"

Buildable::Buildable() {
    victoryPoints = 0;
    built = false;
}

Cost Buildable::get_cost() {
    return cost;
}

bool Buildable::is_built() {
    return built;
}

void Buildable::build() {
    built = true;
}

int Buildable::get_victory_points() {
    return victoryPoints;
}

Impact Buildable::get_build_impact() {
    return [](Player* p){};
};

Buildable::~Buildable() { }
