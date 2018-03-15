#include "Ressource.h"

Ressource::Ressource() {};

Ressource::Ressource(const Cost &cost, const RessourceType &ressource, const int &quantity) {
    this->cost = cost;
    this->ressource = ressource;
    this->quantity = quantity;
};

int Ressource::get_production(RessourceType ressource) {
    return this->ressource==ressource ? quantity : 0;
}

string Ressource::print() {
    stringstream sout;
    sout << "Ressource[";
    sout << "(" << util::print_ressource(ressource) << "," << quantity << ")";
    sout << "] ~ " << cost.print() << endl;
    return sout.str();
}