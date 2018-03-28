#ifndef PLAYER_H_
#define PLAYER_H_

#include "Globals.h"
#include "Artifact.h"
#include "ConflictZone.h"

class Buildable;
class Building;
class CivilianBuilding;
class CommercialBuilding;
class ManufacturedGood;
class MilitaryBuilding;
class RawMaterial;
class ScientificBuilding;
class Cost;
class Wonder;
class Ressource;

function<void(Player*)> make_grant_gold(int n);
function<void(Player*)> make_attack(int n);

class Player {
    string name;
    int gold;
    shared_ptr<Building> active;
    ConflictZone* zone;
    vector<shared_ptr<Wonder>> wonders;
    vector<shared_ptr<Artifact>> progressTokens;

    vector<shared_ptr<CivilianBuilding>> civilians;
    vector<shared_ptr<CommercialBuilding>> commerces;
    vector<shared_ptr<ManufacturedGood>> manufactures;
    vector<shared_ptr<MilitaryBuilding>> militaries;
    vector<shared_ptr<RawMaterial>> materials;
    vector<shared_ptr<ScientificBuilding>> scientifics;
public:
	Player(const string&, const int&);
    Player(): Player("john", 0) { }
    explicit Player(const string& n) : Player(n, 7) { }
	virtual ~Player();

    // Members
    string get_name();
    vector<shared_ptr<Building>> get_buildings();
    vector<shared_ptr<Wonder>> get_wonders();
    shared_ptr<Building> get_active();
	string print();

    vector<shared_ptr<CivilianBuilding>> get_civilians();
    vector<shared_ptr<CommercialBuilding>> get_commerces();
    vector<shared_ptr<ManufacturedGood>> get_manufactures();
    vector<shared_ptr<MilitaryBuilding>> get_militaries();
    vector<shared_ptr<RawMaterial>> get_materials();
    vector<shared_ptr<ScientificBuilding>> get_scientifics();
    vector<shared_ptr<Ressource>> get_ressources();

    int get_victory_points();

    void set_conflict_zone(ConflictZone*);
    void attack(int n);
    bool enough_wealth(shared_ptr<Buildable>);
	void claim(shared_ptr<Building>);
    void register_built(shared_ptr<Building>);
    void claim_wonder(shared_ptr<Wonder>);
    bool can_build(shared_ptr<Buildable> buildable);
    int get_total_cost(shared_ptr<Building>, shared_ptr<Player>);
    void build();
    void qbuild(shared_ptr<Building>);
    void build_wonder(shared_ptr<Wonder>);
    bool is_owner(shared_ptr<Buildable>);
    bool is_active(shared_ptr<Building>);
    void sell(shared_ptr<Graveyard>);
    int get_production(RessourceType);
    vector<RessourceMap> get_production_alternatives();
    int get_cost(RessourceType, shared_ptr<Player>);
    vector<RessourceType> get_cost_overrides();
    Player copy();
    Player tweak(vector<Tweak> tweaks);

    // Wallet
    int get_gold() const;
    void earn(int);
    bool can_spend(int);
    void spend(int);
};

#endif
