#include "Wallet.h"

Wallet::Wallet(int n) {
    cout << "Wallet has been created with : " << n << " gold." << endl;
	gold = n;
}

int Wallet::get_gold() const {
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

Wallet::~Wallet() { }

