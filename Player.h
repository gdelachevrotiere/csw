#ifndef PLAYER_H_
#define PLAYER_H_

#include "Globals.h"
#include "Wallet.h"
#include "Building.h"
#include "Artifact.h"
#include "Ressource.h"
#include "RawMaterial.h"

class Player {
	string name;
    shared_ptr<Wallet> wallet;
	vector<shared_ptr<Building>> buildings;
	vector<shared_ptr<Artifact>> progressTokens;
public:
	Player(string s);
	virtual ~Player();

	void print();
    shared_ptr<Wallet> get_wallet();
	int get_production(RessourceType);
	void build(shared_ptr<Building> building);
    void attack(int n);
};

#endif
