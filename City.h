#ifndef CWS_CITY_H
#define CWS_CITY_H

#include "Globals.h"
#include "Building.h"

class City {
    vector<shared_ptr<Building>> buildings;
public:
    City(vector<shared_ptr<Building>>);
    ~City();
};


#endif
