#ifndef RESSOURCE_H_
#define RESSOURCE_H_

#include "Building.h"

class Ressource: public Building {
    RessourceType ressource;
    int quantity;
public:
    Ressource();
    Ressource(const Cost&, const RessourceType&, const int&);
    Ressource(const Cost &c, const RessourceType &r): Ressource(c, r, 1) {};
    Ressource(const RessourceType& r, const int& i): Ressource(Cost(), r, i) {};
    Ressource(const RessourceType& r): Ressource(r, 1) {};
    virtual ~Ressource();

    int get_production(RessourceType) final;
    string print();
};

#endif
