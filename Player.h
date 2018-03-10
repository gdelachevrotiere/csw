#ifndef PLAYER_H_
#define PLAYER_H_

#include "Globals.h"
#include "Wallet.h"
#include "Artifact.h"
#include "ConflictZone.h"

class Buildable;
class Building;
class Cost;
class Wonder;

class Player {
	string name;
    shared_ptr<Wallet> wallet;
	vector<shared_ptr<Building>> buildings;
	vector<shared_ptr<Artifact>> progressTokens;
    ConflictZone* zone;
public:
	Player(string, int);
	Player(string n) : Player(n, 7) {};
	virtual ~Player();

	string print();
    shared_ptr<Wallet> get_wallet();
    void set_conflict_zone(ConflictZone*);
    void attack(int n);
    vector<shared_ptr<Building>> get_buildings();
    Cost get_wealth();
	string get_name();
    int get_production(RessourceType);
    bool can_build(shared_ptr<Buildable>);
	void claim(shared_ptr<Buildable>);
	void build(shared_ptr<Buildable>);
    bool enough_wealth(shared_ptr<Buildable>);
    bool is_owner(shared_ptr<Buildable>);
};

#endif
