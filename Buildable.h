#ifndef CWS_BUILDABLE_H
#define CWS_BUILDABLE_H

#include "Cost.h"

class Player;

class Buildable {
protected:
    Cost cost;
    int victoryPoints;
    bool built;
    bool claimed;
public:
    Buildable();
    virtual ~Buildable();

    Cost get_cost();
    int get_victory_points();
    void register_build();
    void register_claim();
    bool is_built();
    bool is_claimed();
    virtual Impact get_build_impact();
    virtual string print() = 0;
};

#endif
