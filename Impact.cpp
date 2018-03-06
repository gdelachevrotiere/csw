#include "Impact.h"

Impact::Impact(function<void(shared_ptr<Player>)> lambda) {
    this->lambda = lambda;
}

void Impact::apply(shared_ptr<Player> player) {
    lambda(player);
}

Impact::~Impact() { }

