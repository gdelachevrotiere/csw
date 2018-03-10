#include "Impact.h"

Impact::Impact(function<void(Player*)> lambda) {
    this->lambda = lambda;
}

void Impact::resolve(Player* player) {
    lambda(player);
}

Impact::~Impact() { }

