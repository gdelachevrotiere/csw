#include "Cost.h"

Cost::Cost(int gold, const map<RessourceType,int> ressources){
    this->gold = gold;
    this->ressources = ressources;
}

int Cost::get_gold() {
    return gold;
}

int Cost::get_ressource(RessourceType ressource_type) {
    return (ressources.find(ressource_type) != ressources.end()) ? ressources[ressource_type] : 0;
}

bool Cost::less_than(Cost cost) {
    map<RessourceType,bool> ressourceCheck;
    RessourceType ressource;
    for (int i=0;i++;i<6) {
        ressource = RessourceType(i);
        ressourceCheck.insert(make_pair(ressource, this->get_ressource(ressource) <= cost.get_ressource(ressource)));
    }
    bool sufficientRessources = all_of(ressourceCheck.begin(), ressourceCheck.end(),
                                       [](pair<RessourceType,bool> p){ return p.second; });
    bool sufficientGold = get_gold() <= cost.get_gold();
    return sufficientRessources && sufficientGold;
}

string Cost::print() {
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
    sout << "Cost[" << "(Gold," << gold << ")";
    for (auto b: ressources) {
        sout << "(" << f(b.first) << ", " << b.second << ")";
    }
    sout << "]";
    return sout.str();
}

Cost::~Cost(){ }