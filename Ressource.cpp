#include "Ressource.h"

Ressource::Ressource() {};

Ressource::Ressource(Cost cost, RessourceType ressource_type, int quantity) {
    this->cost = cost;
    this->production = RessourceMap{ {ressource_type, quantity} };
};

int Ressource::get_production(RessourceType ressource_type) {
    return (production.end()!=production.find(ressource_type)) ? production[ressource_type] : 0;
}

void Ressource::print() {
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
    cout << "Ressource[";
    for (auto b: production) {
        cout << "(" << f(b.first) << "," << b.second << ")";
    }
    cout << "] ~ ";
    cost.print();
    cout << endl;
}

Ressource::~Ressource() {}