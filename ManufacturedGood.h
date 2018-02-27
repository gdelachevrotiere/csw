#ifndef MANUFACTUREDGOOD_H_
#define MANUFACTUREDGOOD_H_

#include "Ressource.h"

class ManufacturedGood: public Ressource {
public:
	ManufacturedGood(Cost c, RessourceType r, int i): Ressource(c, r, i) { };
};

#endif
