#ifndef RAWMATERIAL_H_
#define RAWMATERIAL_H_

#include "Ressource.h"

class RawMaterial: public Ressource {
	RessourceType ressource_type;
	int quantity;
public:
	RawMaterial(RessourceType, int);
	virtual ~RawMaterial();

	RessourceType get_ressource_type();
	int get_quantity();
};

#endif /* RAWMATERIAL_H_ */
