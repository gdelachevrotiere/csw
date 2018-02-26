#include "Player.h"
using namespace std;

Player::Player(string name) {
	this->name = name;
	wallet = new Wallet(0);
	wallet->receive(7);
}

void Player::build(Building *building) {
}

Player::~Player() {
	delete &name;
}

void Player::print() const {
	cout << "Player[" << name << "](gold=" << wallet->get_gold() << ")" <<  endl;
}
