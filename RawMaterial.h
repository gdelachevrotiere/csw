#ifndef RAWMATERIAL_H_
#define RAWMATERIAL_H_

#include "Ressource.h"

class RawMaterial: public Ressource {
public:
    RawMaterial(Cost c, RessourceType r, int i): Ressource(c, r, i) { };
    RawMaterial(Cost c, RessourceType r): Ressource(c, r) { };
    RawMaterial(RessourceType r, int i): Ressource(r, i) { };
    RawMaterial(RessourceType r): Ressource(r) { };
};

#endif
