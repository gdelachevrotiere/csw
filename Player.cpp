/*
 * Player.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: root
 */

#include "Player.h"

Player::Player(std::string name) {
	this->name = name;
	wallet = new Wallet(0);
}

Player::~Player() {
	delete &name;
}

void Player::print() const {
	std::cout << "Player[" << name << "](gold=" << wallet->get_gold() << ")" <<  std::endl;
}
