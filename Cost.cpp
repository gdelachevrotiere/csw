#include "Cost.h"

Cost::Cost(int gold, const map<RessourceType,int> ressources){
    this->gold = gold;
    this->ressources = ressources;
}

int Cost::get_ressource(RessourceType ressource_type) {
    return (ressources.find(ressource_type) != ressources.end()) ? ressources[ressource_type] : 0;
}

Cost::~Cost(){
    delete &gold, ressources;
}