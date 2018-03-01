#ifndef WALLET_H_
#define WALLET_H_

#include "Globals.h"

class Wallet {
	int gold;
public:
	Wallet(int n);
	Wallet(): Wallet(0) {};
	virtual ~Wallet();

	int get_gold() const;
	void receive(int);
	bool can_spend(int);
	void spend(int);
};

#endif
