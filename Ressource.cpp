#include "Ressource.h"

Ressource::Ressource() {};

Ressource::Ressource(Cost cost, RessourceType ressource_type, int quantity) {
    this->cost = cost;
    this->production = RessourceMap{ {ressource_type, quantity} };
};

int Ressource::get_production(RessourceType ressource_type) {
    return (production.end()!=production.find(ressource_type)) ? production[ressource_type] : 0;
}

Ressource::~Ressource() {
    delete &production;
}