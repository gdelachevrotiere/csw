#include "Player.h"
#include "Building.h"
#include "Buildable.h"
#include "Wonder.h"
using namespace std::placeholders;

function<void(Player*)> make_grant_gold(int n) {
    return bind([](Player* p, int n) { p->get_wallet()->receive(n); }, _1, n);
}

function<void(Player*)> make_attack(int n) {
    return bind([](Player* p, int n) { p->attack(n); }, _1, n);
}

Player::Player(string name, int gold) {
    this->name = name;
    wallet = make_shared<Wallet>(*new Wallet(gold));
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

bool Player::enough_wealth(shared_ptr<Buildable> buildable) {
    return buildable->get_cost().less_than(get_wealth());
}

bool Player::is_owner(shared_ptr<Buildable> buildable) {
    return buildable->get_owner() == this;
}

bool Player::can_build(shared_ptr<Buildable> buildable) {
    return enough_wealth(buildable) && is_owner(buildable);
}

void Player::build(shared_ptr<Buildable> buildable) {
    if (can_build(buildable)) {
        buildable->build();
        buildable->resolve_build_impact();
        wallet->spend(buildable->get_cost().get_gold());
    } else {
        throw runtime_error("The player's wealth is insufficient to build this building");
    }
}

void Player::claim(shared_ptr<Buildable> buildable) {
    buildable->set_owner(this);
}

void Player::set_conflict_zone(ConflictZone* zone) {
    this->zone = zone;
}

void Player::attack(int n) {
    zone->register_attack(this, n);
}

string Player::get_name() {
    return name;
}

string Player::print() {
    stringstream sout;
	sout << "Player[" << name << "](";
    sout << "gold=" << wallet->get_gold() << ",";
    sout << "wood=" << get_production(Wood) << ",";
    sout << "clay=" << get_production(Clay) << ",";
    sout << "stone=" << get_production(Stone) << ")";
    return sout.str();
}

Player::~Player() {}