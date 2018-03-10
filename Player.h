#ifndef PLAYER_H_
#define PLAYER_H_

#include "Globals.h"
#include "Wallet.h"
#include "Artifact.h"

class Building;
class Cost;

class Player {
	string name;
    shared_ptr<Wallet> wallet;
	vector<shared_ptr<Building>> buildings;
	vector<shared_ptr<Artifact>> progressTokens;
public:
	explicit Player(string s);
	virtual ~Player();

	void print();
    shared_ptr<Wallet> get_wallet();
    void attack(int n);
    vector<shared_ptr<Building>> get_buildings();
    Cost get_wealth();
	string get_name();
    int get_production(RessourceType);
	void build(shared_ptr<Building> building);
};

#endif
