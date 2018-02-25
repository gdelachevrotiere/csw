/*
 * Wallet.h
 *
 *  Created on: Feb 25, 2018
 *      Author: root
 */

#ifndef WALLET_H_
#define WALLET_H_

class Wallet {
	int gold;
public:
	Wallet(int);
	virtual ~Wallet();

	int get_gold();
	void receive(int);
	bool can_spend(int);
	void spend(int);
};

#endif /* WALLET_H_ */
