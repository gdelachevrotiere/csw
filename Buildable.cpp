#include "Buildable.h"

Buildable::Buildable() {
    victoryPoints = 0;
    available = true;
    built = false;
}

Cost Buildable::get_cost() {
    return cost;
}

bool Buildable::is_built() {
    return built;
}

bool Buildable::is_available() {
    return available;
}

void Buildable::set_owner(Player* owner) {
    if (is_available()) {
        this->owner = owner;
        available = false;
    }
    else {
        throw runtime_error("The Buildable is not currently available");
    }
}

Player* Buildable::get_owner() {
    return owner;
}

void Buildable::build() {
    built = true;
}

int Buildable::get_victory_points() {
    return victoryPoints;
}

Buildable::~Buildable() { }
