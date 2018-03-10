#ifndef CWS_BUILDABLE_H
#define CWS_BUILDABLE_H

#include "Cost.h"

class Player;

class Buildable {
protected:
    Cost cost;
    Player* owner;
    int victoryPoints;
    bool available;
    bool built;
public:
    Buildable();
    virtual ~Buildable();

    Cost get_cost();
    int get_victory_points();
    void set_owner(Player*);
    void build();
    bool is_built();
    bool is_available();
    Player* get_owner();
    virtual int get_production(RessourceType) = 0;
    virtual void resolve_build_impact() = 0;
    virtual string print() = 0;
};

#endif
