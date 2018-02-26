#include "RawMaterial.h"

RawMaterial::RawMaterial(RessourceType ressource_type, int quantity) {
	this->ressource_type = ressource_type;
	this->quantity = quantity;
}

RessourceType RawMaterial::get_ressource_type() {
	return ressource_type;
}

int RawMaterial::get_quantity() {
	return quantity;
}

RawMaterial::~RawMaterial() {

}

