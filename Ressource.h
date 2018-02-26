#ifndef RESSOURCE_H_
#define RESSOURCE_H_

#include "Building.h"

enum RessourceType { wood, stone, clay, glass, paper };

class Ressource: public Building {
public:
	Ressource();
	virtual ~Ressource();
};

#endif /* RESSOURCE_H_ */
