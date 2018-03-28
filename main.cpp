#include "Globals.h"
#include "Game.h"
#include "Wonder.h"
#include "RawMaterial.h"
#include "MilitaryBuilding.h"
#include "CommercialBuilding.h"
#include "CivilianBuilding.h"

int game() {

    const vector<shared_ptr<Wonder>> wonders {
        make_shared<Wonder>(*new Wonder(
                "The Appian Way",
                Cost({ {Stone, 2}, {Wood, 1} }),
                vector<Impact>({lambda::income_impact(4)})
        )),
        make_shared<Wonder>(*new Wonder(
                "Circus Maximus",
                Cost({ {Glass, 1}, {Clay, 1}, {Wood, 1} }),
                vector<Impact>({lambda::attack_impact(2)})
        )),
        make_shared<Wonder>(*new Wonder(
                "The Collossus",
                Cost({ {Clay,2}, {Wood,2} }),
                vector<Impact>({lambda::income_impact(2), lambda::attack_impact(1)})
        ))
    };

    const vector<shared_ptr<Building>> buildings {
        make_shared<RawMaterial>(*new RawMaterial(Cost(1), Wood)),
        make_shared<RawMaterial>(*new RawMaterial(Cost(2), Clay)),
        make_shared<RawMaterial>(*new RawMaterial(Cost(0), Stone)),
        make_shared<RawMaterial>(*new RawMaterial(Cost(1), Wood,2)),
        make_shared<RawMaterial>(*new RawMaterial(Cost(2), Clay,2)),
        make_shared<RawMaterial>(*new RawMaterial(Cost(3), Stone,2)),
        make_shared<RawMaterial>(*new RawMaterial(Clay)),
        make_shared<RawMaterial>(*new RawMaterial(Wood)),

        make_shared<CommercialBuilding>(*new CommercialBuilding(Cost(3), {Wood})),
        make_shared<CommercialBuilding>(*new CommercialBuilding(Cost(3), {Clay})),
        make_shared<CommercialBuilding>(*new CommercialBuilding(Cost(3), {Stone})),
        make_shared<CommercialBuilding>(*new CommercialBuilding(Cost(3), {Stone, Wood})),

        make_shared<CivilianBuilding>(*new CivilianBuilding(Cost(1, {{Clay, 1}}), 1)),
        make_shared<CivilianBuilding>(*new CivilianBuilding(Cost(2, {{Wood, 1}}), 3)),
        make_shared<CivilianBuilding>(*new CivilianBuilding(Cost(1, {{Stone, 1}}), 1)),

        make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost({{Wood, 1}}), 1)),
        make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost({{Clay, 1}}), 1)),
        make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost(1), 1)),
        make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost(2), 2)),
        make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost({{Stone, 2}}), 3))
    };

    auto playerA = make_shared<Player>(*new Player("Gabriel"));
    auto playerB = make_shared<Player>(*new Player("Catherine"));

    Game game(playerA, playerB, wonders, buildings);
    game.start();

    return 0;
}

int main() {

    test_all();
    game();

    return 0;
}
