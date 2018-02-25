/*
 * Wallet.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: root
 */

#include "Wallet.h"

Wallet::Wallet(int n) {
	gold = n;
}

int Wallet::get_gold() {
	return gold;
}

void Wallet::receive(int n) {
	gold += n;
}

bool Wallet::can_spend(int n) {
	return gold >= n;
}

void Wallet::spend(int n) {
	if(!can_spend(n)) {
		throw "gold is insufficient to spend that amount";
	}
	gold -= n;
}

Wallet::~Wallet() {
	delete &gold;
}

