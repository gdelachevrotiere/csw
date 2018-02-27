#include "Impact.h"

Impact::Impact(ImpactType impact_type) {
    this->impact_type = impact_type;
}

void Impact::apply(Player* player) {
    // TBD
}

Impact::~Impact() {
    delete &impact_type;
}

