#include "Player.h"
#include "Wonder.h"

using namespace std;

Player::Player(const string name) {
	this->name = name;
	wallet = Wallet(0);
	wallet.receive(7);
}

int Player::get_production(const RessourceType ressource_type) {
	int quantity = 0;
	for (auto b: buildings) {
		quantity += b->get_production(ressource_type);
	}
	return quantity;
}

Player::~Player() {
	delete &name;
}

void Player::print() const {
	cout << "Player[" << name << "](gold=" << wallet.get_gold() << ")" <<  endl;
}
