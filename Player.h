#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "Wonder.h"
#include "Wallet.h"
#include "Card.h"

class Player {
	std::string name;
	Wallet* wallet;
	Wonder wonders[2];
	Card cards[10];
public:
	Player(std::string);
	virtual ~Player();
	void print() const;
};

#endif
