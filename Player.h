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
	Wallet wallet;
	vector<Building*> buildings;
	vector<Artifact*> progress_tokens;
public:
	Player(string s);
	virtual ~Player();

	void print() const;
	int get_production(RessourceType);
	void build(Building *building);
};

#endif
