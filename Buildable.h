#ifndef CWS_BUILDABLE_H
#define CWS_BUILDABLE_H

#include "Cost.h"

class Player;

class Buildable {
protected:
    Cost cost;
    int victoryPoints;
    bool built;
public:
    Buildable();
    virtual ~Buildable();

    Cost get_cost();
    int get_victory_points();
    void build();
    bool is_built();
    virtual Impact get_build_impact();
    virtual string print() = 0;
};

#endif
