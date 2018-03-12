#include "Ressource.h"

Ressource::Ressource() {};

Ressource::Ressource(Cost cost, RessourceType ressource_type, int quantity) {
    this->cost = cost;
    this->production = RessourceMap{ {ressource_type, quantity} };
};

int Ressource::get_production(RessourceType ressource_type) {
    return (production.end()!=production.find(ressource_type)) ? production[ressource_type] : 0;
}

string Ressource::print() {
    auto f = [](RessourceType r){
        switch(r) {
            case Gold: return "Gold";
            case Wood: return "Wood";
            case Stone: return "Stone";
            case Clay: return "Clay";
            case Glass: return "Glass";
            case Paper: return "Paper";
        }
    };
    stringstream sout;
    sout << "Ressource[";
    for (auto b: production) {
        sout << "(" << f(b.first) << "," << b.second << ")";
    }
    sout << "] ~ " << cost.print() << endl;
    return sout.str();
}

Impact Ressource::get_build_impact() {
    return [](Player* p){}; //no impact
};

Ressource::~Ressource() {}