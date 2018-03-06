#include "Globals.h"
#include "Game.h"
#include "Wonder.h"
#include "RawMaterial.h"
#include <functional>
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

	const vector<shared_ptr<Wonder>> wonders {
        make_shared<Wonder>(*new Wonder("The Appian Way", Cost(RessourceMap{{Stone, 2},{Wood, 1}}), vector<Impact>())),
        make_shared<Wonder>(*new Wonder("Circus Maximus", Cost(RessourceMap{{Glass, 1},{Clay, 1},{Wood, 1}}), vector<Impact>())),
        make_shared<Wonder>(*new Wonder("The Collossus" , Cost(RessourceMap{{Clay, 2},{Wood, 2}}), vector<Impact>()))
    };
	cout << "The number of wonders is: " << wonders.size() << endl;

    const vector<shared_ptr<Building>> buildings {
        make_shared<RawMaterial>(*new RawMaterial(Wood)),
        make_shared<RawMaterial>(*new RawMaterial(Clay)),
        make_shared<RawMaterial>(*new RawMaterial(Stone)),
        make_shared<RawMaterial>(*new RawMaterial(Wood,2)),
        make_shared<RawMaterial>(*new RawMaterial(Clay,2)),
        make_shared<RawMaterial>(*new RawMaterial(Stone,2)),
        make_shared<RawMaterial>(*new RawMaterial(Glass)),
        make_shared<RawMaterial>(*new RawMaterial(Paper))
    };
    cout << "The number of buildings is: " << buildings.size() << endl;

    const auto grantGold = make_grant_gold(3);

    shared_ptr<Impact> imp = make_shared<Impact>(*new Impact(grantGold));

	shared_ptr<Player> playerA(new Player("Gabriel"));
    shared_ptr<Player> playerB(new Player("Catherine"));

	cout << "Welcome to 7 Wonders Duel C++ version" << endl;
	cout << "The players are: " << endl;
    playerA->print();
    playerB->print();

    Game game(playerA, playerB, wonders, buildings);

    return 0;
}
