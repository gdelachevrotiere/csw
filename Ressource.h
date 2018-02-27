#ifndef RESSOURCE_H_
#define RESSOURCE_H_

#include "Building.h"

class Ressource: public Building {
    RessourceMap production;
public:
    Ressource();
    Ressource(Cost, RessourceType, int);
    Ressource(Cost c, RessourceType r): Ressource(c, r, 1) {};
    Ressource(RessourceType r, int i): Ressource(Cost(), r, i) {};
    Ressource(RessourceType r): Ressource(r, 1) {};
    virtual ~Ressource();

    int get_production(RessourceType);
};

#endif
