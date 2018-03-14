#include "Cost.h"

Cost::Cost(int gold, const map<RessourceType,int> ressources){
    this->gold = gold;
    this->ressources = ressources;
}

int Cost::get_gold() {
    return gold;
}

int Cost::get_ressource(RessourceType ressource) {
    return (ressources.find(ressource) != ressources.end()) ? ressources[ressource] : 0;
}

bool Cost::less_than(Cost cost) {
    map<RessourceType, bool> check;
    RessourceType r;
    for (int i=0;i++;i<6) {
        r = RessourceType(i);
        check.insert(make_pair(r, get_ressource(r) <= cost.get_ressource(r)));
    }
    bool sufficientRessources = all_of(check.begin(), check.end(), [](pair<RessourceType,bool> p){ return p.second; });
    bool sufficientGold = get_gold() <= cost.get_gold();
    return sufficientRessources && sufficientGold;
}

string Cost::print() {
    stringstream sout;
    sout << "Cost[" << "(Gold," << gold << ")";
    for (auto b: ressources) {
        sout << "(" << print_ressource(b.first) << ", " << b.second << ")";
    }
    sout << "]";
    return sout.str();
}

Cost::~Cost(){ }