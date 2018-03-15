#include "Player.h"
#include "Wonder.h"

#include "Buildable.h"
#include "Building.h"
#include "CivilianBuilding.h"
#include "CommercialBuilding.h"
#include "ManufacturedGood.h"
#include "MilitaryBuilding.h"
#include "RawMaterial.h"
#include "ScientificBuilding.h"
#include "Ressource.h"

Player::Player(const string& name, const int& gold) {
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


vector<shared_ptr<CivilianBuilding>> Player::get_civilians() {
    return civilians;
};

vector<shared_ptr<CommercialBuilding>> Player::get_commerces() {
    return commerces;
};

vector<shared_ptr<ManufacturedGood>> Player::get_manufactures() {
    return manufactures;
};

vector<shared_ptr<MilitaryBuilding>> Player::get_militaries() {
    return militaries;
};

vector<shared_ptr<RawMaterial>> Player::get_materials() {
    return materials;
};

vector<shared_ptr<ScientificBuilding>> Player::get_scientifics() {
    return scientifics;
};

vector<shared_ptr<Ressource>> Player::get_ressources() {
    vector<shared_ptr<Ressource>> ressources;
    for (auto r: get_materials()) {
        ressources.push_back(r);
    }
    for (auto m: get_manufactures()) {
        ressources.push_back(m);
    }
    return ressources;
};

vector<shared_ptr<Building>> Player::get_buildings() {
    vector<shared_ptr<Building>> bs;
    bs.insert(bs.end(), civilians.begin(), civilians.end());
    bs.insert(bs.end(), commerces.begin(), commerces.end());
    bs.insert(bs.end(), manufactures.begin(), manufactures.end());
    bs.insert(bs.end(), militaries.begin(), militaries.end());
    bs.insert(bs.end(), materials.begin(), materials.end());
    bs.insert(bs.end(), scientifics.begin(), scientifics.end());
    return bs;
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
    for (const auto& c: get_commerces()) {
       for (const auto&m : c->get_market()) {
           v.push_back(m);
       };
    }
    sort(v.begin(), v.end());
    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());
    return v;
}

vector<shared_ptr<Wonder>> Player::get_wonders() {
    return wonders;
}

vector<RessourceMap> Player::get_production_alternatives() {
    // Counts the raw production from Ressource cards (RawMaterial & ManufacturedGood)
    int singleProduction[6];
    vector<int> rindex {0, 1, 2, 3, 4, 5};
    int runningSum;
    for (const auto &i: rindex) {
        runningSum = 0;
        for (const auto& b : get_ressources()) {
            runningSum += b->get_production(RessourceType(i));
        }
        singleProduction[i] = runningSum;
    }

    // Gets all combinations of shared_productions
    vector<vector<RessourceType>> sharedProductions;
    vector<RessourceType> sp;
    for (const auto& w: get_wonders()) {
        sp = w->get_shared_production();
        if (!sp.empty()) {
            sharedProductions.push_back(sp);
        }
    }

    vector<vector<RessourceType>> sharedProductionPools = util::cartesian_product(sharedProductions);

    // Counts the total production per combined shared production pool, and adds raw production
    vector<RessourceMap> allProductions;
    int count;
    int totalProduction[6];
    for (const auto& production_pool: sharedProductionPools) {
        for (const auto &i: rindex) {
            count = 0;
            for (auto r: production_pool) {
                if (r == RessourceType(i)) {
                    count++;
                }
            }
            totalProduction[i] = singleProduction[i] + count;
        }
        RessourceMap rmap;
        for (const auto &i: rindex) {
            if (totalProduction[i]>0) {
                rmap.insert(pair<RessourceType,int>({RessourceType(i), totalProduction[i]}));
            }
        }
        if(!rmap.empty()) {
            allProductions.push_back(rmap);
        }
    }

    // If there was no production alternatives, consider the regular production
    if(allProductions.empty()) {
        RessourceMap rmap;
        for (const auto &i: rindex) {
            if (singleProduction[i]>0) {
                rmap.insert(pair<RessourceType,int>({RessourceType(i), singleProduction[i]}));
            }
        }
        allProductions.push_back(rmap);
    }

    return allProductions;
}

int Player::get_total_cost(shared_ptr<Building> building, shared_ptr<Player> opponent) {
    vector<int> rindex {0, 1, 2, 3, 4, 5};
    int have, diff, price;
    RessourceType r;
    Cost buildingCost = building->get_cost();
    auto alternatives = get_production_alternatives();
    vector<int> prices;
    for (auto a: alternatives) {
        price = 0;
        for (const auto &i: rindex) {
            r = RessourceType(i);
            have = a.find(r)!=a.end() ? a[r] : 0;
            diff = buildingCost.get_ressource(r) - have;
            price += diff<=0 ? 0: diff*get_cost(r, opponent);
        }
        prices.push_back(price);
    }
    int min = *min_element(prices.begin(), prices.end());
    return min;
}

bool Player::enough_wealth(shared_ptr<Buildable> buildable) {
    for (const auto &p: get_production_alternatives()) {
        if (buildable->get_cost().less_than(Cost(get_gold(), p))) {
            return true;
        }
    }
    return false;
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

void Player::register_built(shared_ptr<Building> b) {
    if(auto pCivilian = dynamic_pointer_cast<CivilianBuilding>(b)) {
        civilians.push_back(pCivilian);
    }
    else if(auto pCommercial = dynamic_pointer_cast<CommercialBuilding>(b)) {
        commerces.push_back(pCommercial);
    }
    else if(auto pManufactured = dynamic_pointer_cast<ManufacturedGood>(b)) {
        manufactures.push_back(pManufactured);
    }
    else if(auto pMilitary = dynamic_pointer_cast<MilitaryBuilding>(b)) {
        militaries.push_back(pMilitary);
    }
    else if(auto pMaterial = dynamic_pointer_cast<RawMaterial>(b)) {
        materials.push_back(pMaterial);
    }
    else if(auto pScientific = dynamic_pointer_cast<ScientificBuilding>(b)) {
        scientifics.push_back(pScientific);
    }
}

bool Player::can_build(shared_ptr<Buildable> buildable) {
    if (active==nullptr) {
        throw runtime_error("there is no active building, choose a building first");
    } else if (!enough_wealth(buildable)) {
        throw runtime_error("the player's wealth is insufficient to build this building");
    } else if (buildable->is_built()){
        throw runtime_error("the building is already built");
    }
    return true;
}

void Player::build() {
    if (can_build(active)) {
        spend(active->get_cost().get_gold());
        active->register_build();
        active->get_build_impact()(this);
        register_built(active);
        active.reset();
    } else {
        throw runtime_error("can't build");
    }
}

void Player::build_wonder(shared_ptr<Wonder> wonder) {
    if (can_build(wonder)) {
        spend(wonder->get_cost().get_gold());
        wonder->register_build();
        wonder->get_build_impact()(this);
        active.reset();
    } else {
        throw runtime_error("can't build");
    }
}

void Player::sell(shared_ptr<Graveyard> graveyard) {
    int income = 2 + static_cast<int>(get_commerces().size());
    earn(income);
    graveyard->push_back(active);
    active.reset();
}

void Player::claim(shared_ptr<Building> building) {
    building->register_claim();
    active = move(building);
}

void Player::qbuild(shared_ptr<Building> building) {
    claim(building);
    build();
}

void Player::claim_wonder(shared_ptr<Wonder> wonder) {
    wonder->register_claim();
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