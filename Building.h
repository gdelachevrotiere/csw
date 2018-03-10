#ifndef BUILDING_H_
#define BUILDING_H_

#include "Globals.h"
#include "Cost.h"

class Player;

class Building {
protected:
	Cost cost;
	int victoryPoints;
    bool available;
    shared_ptr<Player> owner;
public:
    Building();
    virtual ~Building();

	Cost get_cost();
    int get_victory_points();
    void set_owner(shared_ptr<Player>);
    virtual int get_production(RessourceType) = 0;
    virtual void resolve_build_impact() = 0;
    virtual void print() = 0;
};

#endif
