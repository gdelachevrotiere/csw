#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <vector>
#include "Wallet.h"
#include "Building.h"
#include "ProgressTokens.h"

using namespace std;

class Player {
	string name;
	Wallet *wallet;
	vector<Building> buildings;
	vector<ProgressTokens> progress_tokens;
public:
	Player(string);
	virtual ~Player();

	void print() const;
	void build(Building *building);
};

#endif
