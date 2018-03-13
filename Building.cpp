#include "Building.h"

optional<Link> Building::get_link() {
    return link;
}

int Building::get_production(RessourceType) {
    return 0;
};