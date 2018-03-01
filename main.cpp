#include "Globals.h"
#include "Game.h"
#include "Wonder.h"
#include "RawMaterial.h"

int main() {

	vector<shared_ptr<Wonder>> wonders {
        make_shared<Wonder>(*new Wonder("The Appian Way", Cost(RessourceMap{{Stone, 2},{Wood, 1}}), vector<Impact>())),
        make_shared<Wonder>(*new Wonder("Circus Maximus", Cost(RessourceMap{{Glass, 1},{Clay, 1},{Wood, 1}}), vector<Impact>())),
        make_shared<Wonder>(*new Wonder("The Collossus" , Cost(RessourceMap{{Clay, 2},{Wood, 2}}), vector<Impact>()))
    };
	cout << "The number of wonders is: " << wonders.size() << endl;

    vector<shared_ptr<Building>> buildings {
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

	shared_ptr<Player> playerA(new Player("Gabriel"));
    shared_ptr<Player> playerB(new Player("Catherine"));

	cout << "Welcome to 7 Wonders Duel C++ version" << endl;
	cout << "The players are: " << endl;
    playerA->print();
    playerB->print();

    Game game(playerA, playerB, wonders, buildings);

    return 0;
}
