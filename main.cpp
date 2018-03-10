#include "Globals.h"
#include "Game.h"
#include "Wonder.h"
#include "RawMaterial.h"
#include "MilitaryBuilding.h"
#include "test.h"
using namespace std::placeholders;

function<void(shared_ptr<Player>)> make_grant_gold(int n) {
    return bind([](shared_ptr<Player> p, int n) { p->get_wallet()->receive(n); }, _1, n);
}

function<void(shared_ptr<Player>)> make_attack(int n) {
    return bind([](shared_ptr<Player> p, int n) { p->attack(n); }, _1, n);
}

function<void(shared_ptr<Player>)> gain_artifact = [](shared_ptr<Player> p) { };

shared_ptr<Artifact> choose_artifact(const vector<shared_ptr<Artifact>>& artifact_bank) {
    return artifact_bank.front();
}

int main() {

    /*
	const vector<shared_ptr<Wonder>> wonders {
        make_shared<Wonder>(*new Wonder("The Appian Way", Cost(RessourceMap{{Stone, 2},{Wood, 1}}), vector<Impact>())),
        make_shared<Wonder>(*new Wonder("Circus Maximus", Cost(RessourceMap{{Glass, 1},{Clay, 1},{Wood, 1}}), vector<Impact>())),
        make_shared<Wonder>(*new Wonder("The Collossus" , Cost(RessourceMap{{Clay, 2},{Wood, 2}}), vector<Impact>()))
    };

    const vector<shared_ptr<Building>> buildings {
        make_shared<RawMaterial>(*new RawMaterial(Cost(1), Wood)),
        make_shared<RawMaterial>(*new RawMaterial(Cost(2), Clay)),
        make_shared<RawMaterial>(*new RawMaterial(Cost(0), Stone)),
        make_shared<RawMaterial>(*new RawMaterial(Cost(1), Wood,2)),
        make_shared<RawMaterial>(*new RawMaterial(Cost(2), Clay,2)),
        make_shared<RawMaterial>(*new RawMaterial(Cost(3), Stone,2)),
        make_shared<RawMaterial>(*new RawMaterial(Glass)),
        make_shared<RawMaterial>(*new RawMaterial(Paper)),
        make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost(RessourceMap{{Wood, 1}}), 1)),
        make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost(RessourceMap{{Clay, 1}}), 1)),
        make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost(1), 1)),
        make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost(2), 2)),
        make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost(RessourceMap{{Stone, 2}}), 3)),
    };

    const auto grantGold = make_grant_gold(3);
    shared_ptr<Impact> imp = make_shared<Impact>(*new Impact(grantGold));

	shared_ptr<Player> playerA(new Player(A, "Gabriel"));
    shared_ptr<Player> playerB(new Player(B, "Catherine"));
    shared_ptr<City> city(new City(buildings));


    // playerA->build();

    Game game(playerA, playerB, wonders, city);
    // game.start();

    */

    player_test();
    conflict_zone_test();
    military_win_test();

    return 0;
}

void run_game() {

}