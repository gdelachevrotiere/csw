#ifndef BUILDING_H_
#define BUILDING_H_

#include "Globals.h"
#include "Buildable.h"

class Player;

class Building: public Buildable {
public:
    Building();
    virtual ~Building();
};

#endif
