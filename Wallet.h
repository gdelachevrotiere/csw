#ifndef WALLET_H_
#define WALLET_H_

class Wallet {
	int gold;
public:
	Wallet();
	Wallet(int n);
	virtual ~Wallet();

	int get_gold() const;
	void receive(int);
	bool can_spend(int);
	void spend(int);
};

#endif
