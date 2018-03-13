#ifndef BUILDING_H_
#define BUILDING_H_

#include "Globals.h"
#include "Buildable.h"

class Building: public Buildable {
    optional<Link> link;
public:
    Building() {
        link = nullopt;
    };
    virtual ~Building() {};

    optional<Link> get_link();
    virtual int get_production(RessourceType);
};

#endif
