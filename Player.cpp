#include "Player.h"

Player::Player(const string name) {
	this->name = name;
    wallet = make_shared<Wallet>(*new Wallet(7));
}

int Player::get_production(const RessourceType ressource_type){
	int quantity = 0;
	for (auto const& b: buildings) {
		quantity += b->get_production(ressource_type);
	}
	return quantity;
}

shared_ptr<Wallet> Player::get_wallet() {
    return wallet;
}

void Player::attack(int n) {

}

void build(shared_ptr<Building> building) {
	map<RessourceType,bool> sufficient;
	for (int i=0;i++;i<6) {
		sufficient.insert(make_pair(RessourceType(i),building->get_cost().get_ressource(RessourceType(i))>0));
	}
}


void Player::print() {
	cout << "Player[" << name << "](" << endl;
    cout << "----gold=" << wallet->get_gold() << endl;
    cout << "----wood=" << get_production(Wood) << endl;
    cout << "----clay=" << get_production(Clay) << endl;
    cout << "----stone=" << get_production(Stone) << endl;
    cout << ")" << endl;
}

Player::~Player() {}