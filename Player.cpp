#include "Player.h"
#include "Building.h"
#include "Buildable.h"
#include "Wonder.h"
#include "CommercialBuilding.h"

Player::Player(string name, int gold) {
    this->name = name;
    this->gold = gold;
}

Player Player::copy() {
    Player c = Player();
    c.name = name; // values below
    c.gold = gold;
    c.active = active; // pointers below
    c.wonders = wonders;
    c.civilians = civilians;
    c.commerces = commerces;
    c.manufactures = manufactures;
    c.militaries = militaries;
    c.materials = materials;
    c.scientifics = scientifics;
    c.progressTokens = progressTokens;
    c.zone = zone;
    return c;
}

Player Player::tweak(vector<Tweak> tweaks) {
    Player c = copy();
    for (const auto& t: tweaks) {
        c = t(c);
    }
    return c;
}

int Player::get_production(const RessourceType ressource){
	int quantity = 0;
	for (auto const& b: get_buildings()) {
		quantity += b->get_production(ressource);
	}
	return quantity;
}

int Player::get_cost(RessourceType ressource, shared_ptr<Player> opponent) {
    int cost = 2 + opponent->get_production(ressource);
    auto o = get_cost_overrides();
    if(find(o.begin(), o.end(), ressource) != o.end()) {
        cost = 1;
    }
    return cost;
}

vector<RessourceType> Player::get_cost_overrides() {
    vector<RessourceType> v;
    for (const auto& b: get_buildings()) {
        if (const auto& c = dynamic_pointer_cast<CommercialBuilding>(b)) {
           for (const auto&m : c->get_market()) {
               v.push_back(m);
           };
        }
    }
    sort(v.begin(), v.end());
    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());
    return v;
}

vector<shared_ptr<Building>> Player::get_buildings() {
    vector<shared_ptr<Building>> buildings;
    //buildings.insert(buildings.end(), civilians.begin(), civilians.end());
    //buildings.insert(buildings.end(), commerces.begin(), commerces.end());
    //buildings.insert(buildings.end(), manufactures.begin(), manufactures.end());
    //buildings.insert(buildings.end(), militaries.begin(), militaries.end());
    //buildings.insert(buildings.end(), materials.begin(), materials.end());
    //buildings.insert(buildings.end(), scientifics.begin(), scientifics.end());
    return buildings;
}

vector<shared_ptr<Wonder>> Player::get_wonders() {
    return wonders;
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
    return Cost(get_gold(), production);
}

bool Player::enough_wealth(shared_ptr<Buildable> buildable) {
    return buildable->get_cost().less_than(get_wealth());
}

bool Player::is_active(shared_ptr<Building> building) {
    return active==building;
}

bool Player::is_owner(shared_ptr<Buildable> buildable) {
    if(dynamic_pointer_cast<Building>(buildable)) {
        auto buildings = get_buildings();
        return find(buildings.begin(), buildings.end(), buildable) != buildings.end();
    } else if(dynamic_pointer_cast<Wonder>(buildable)) {
        return find(wonders.begin(), wonders.end(), buildable) != wonders.end();
    } else {
        throw runtime_error("unsupported buildable type");
    }
}

bool Player::can_build(shared_ptr<Buildable> buildable) {
    return (active!=nullptr) && enough_wealth(buildable);
}

void Player::register_built(shared_ptr<Building> building) {
    //if(auto a = dynamic_pointer_cast<CivilianBuilding>(building)) { civilians.push_back(a); }
    //else if(auto b = dynamic_pointer_cast<CommercialBuilding>(building)) { commerces.push_back(b); }
    //else if(auto c = dynamic_pointer_cast<ManufacturedGood>(building)) { manufactures.push_back(c); }
    //else if(auto d = dynamic_pointer_cast<MilitaryBuilding>(building)) { militaries.push_back(d); }
    //else if(auto e = dynamic_pointer_cast<RawMaterial>(building)) { materials.push_back(e); }
    //else if(auto f = dynamic_pointer_cast<ScientificBuilding>(building)) { scientifics.push_back(f); }
}

void Player::build() {
    if (can_build(active)) {
        spend(active->get_cost().get_gold());
        active->build();
        active->get_build_impact()(this);
        register_built(active);
        active.reset();
    } else {
        throw runtime_error("The player's wealth is insufficient to build this building, or there is no active building");
    }
}

void Player::build_wonder(shared_ptr<Wonder> wonder) {
    if (can_build(wonder)) {
        spend(wonder->get_cost().get_gold());
        wonder->build();
        wonder->get_build_impact()(this);
        active.reset();
    } else {
        throw runtime_error("The player's wealth is insufficient to build this wonder, or there is no active building");
    }
}

void Player::sell(shared_ptr<Graveyard> graveyard) {
    int income = 2; //minimum income
    for (const auto& b: get_buildings()) {
        if (dynamic_pointer_cast<CommercialBuilding>(b)) {
            income++;
        }
    }
    earn(income);
    graveyard->push_back(active);
    active.reset();
}

void Player::claim(shared_ptr<Building> building) {
    active = move(building);
}

void Player::claim_wonder(shared_ptr<Wonder> wonder) {
    wonders.push_back(wonder);
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
    sout << "gold=" << get_gold() << ",";
    sout << "wood=" << get_production(Wood) << ",";
    sout << "clay=" << get_production(Clay) << ",";
    sout << "stone=" << get_production(Stone) << ")";
    return sout.str();
}

int Player::get_gold() const {
    return gold;
}

void Player::earn(int n) {
    gold += n;
}

bool Player::can_spend(int n) {
    return gold >= n;
}

void Player::spend(int n) {
    if(!can_spend(n)) {
        throw "gold is insufficient to spend that amount";
    }
    gold -= n;
}

Player::~Player() {}