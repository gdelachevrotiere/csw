#include "Player.h"
#include "Building.h"

Player::Player(string name) {
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

vector<shared_ptr<Building>> Player::get_buildings() {
    return buildings;
}

Cost Player::get_wealth() {
    map<RessourceType,int> production;
    int runningSum;
    RessourceType ressource;
    for (int i=0;i++;i<6) {
        runningSum = 0;
        ressource = RessourceType(i);
        for (const auto& b : get_buildings()) {
            runningSum += b->get_production(ressource);
        }
        production.insert(make_pair(RessourceType(i),runningSum));
    }
    return Cost(get_wallet()->get_gold(), production);
}

void Player::build(shared_ptr<Building> building) {

    if (building->get_cost().less_than(get_wealth()) ) {
        building->set_owner(shared_ptr<Player>(this));
        building->resolve_build_impact();
    } else {
        cout << "The player's wealth is insufficient to build this building." << endl;
    }
}

void Player::attack(int n) {

}


string Player::get_name() {
    return name;
}

void Player::print() {
	cout << "Player[" << name << "](";
    cout << "gold=" << wallet->get_gold();
    cout << ",wood=" << get_production(Wood);
    cout << ",clay=" << get_production(Clay);
    cout << ",stone=" << get_production(Stone);
    cout << ")" << endl;
}

Player::~Player() {}