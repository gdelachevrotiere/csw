#include "Globals.h"
#include "Player.h"
#include "RawMaterial.h"
#include "Wonder.h"
#include "ConflictZone.h"
#include "MilitaryBuilding.h"
#include "CommercialBuilding.h"
#include "lambda.h"

void run(const string &name, const function<void()>& lambda) {
    cout << "[UNIT] Starting " << name << "..." << endl;
    lambda();
    cout << "[UNIT] ..." << name << " successful!" << endl;
}

void player_test() {
    auto wood = make_shared<RawMaterial>(*new RawMaterial(Cost(1), Wood));
    auto clay = make_shared<RawMaterial>(*new RawMaterial(Cost(2, RessourceMap{{Wood, 1}}), Clay, 2));
    auto bad = make_shared<RawMaterial>(*new RawMaterial(Cost(10), Wood));
    auto appian = make_shared<Wonder>(*new Wonder("The Appian Way", Cost(2, RessourceMap{{Wood, 1},{Clay, 2}}), vector<Impact>()));

    Player player("john", 0);
    player.earn(1);

    assert(player.get_gold()==1);
    player.claim_wonder(appian);
    assert(!player.is_active(wood));
    player.claim(wood);
    assert(player.enough_wealth(wood));
    assert(!player.is_active(clay));
    player.build();
    assert(wood->is_built());
    assert(!clay->is_built());
    assert(player.get_wealth().get_gold() == 0);
    player.earn(2);
    player.claim(clay);
    assert(player.enough_wealth(clay));
    player.build();
    assert(clay->is_built());
    assert(player.get_gold()==0);
    assert(!player.enough_wealth(appian));
    player.earn(2);
    assert(player.enough_wealth(appian));
    player.claim(bad);
    player.build_wonder(appian);
    assert(player.get_wealth().get_gold() == 0);

    cout << player.print() << endl;
}

void conflict_zone_test() {
    shared_ptr<Player> playerA(new Player("gabriel"));
    shared_ptr<Player> playerB(new Player("catherine"));
    auto zone = ConflictZone(5, playerA, playerB);
    assert(zone.get_pawn_position()==0);
    assert(!zone.get_winner());
    zone.move_pawn(2);
    assert(zone.get_pawn_position()==2);
    zone.move_pawn(-3);
    assert(zone.get_pawn_position()==-1);
    zone.move_pawn(10);
    assert(zone.get_pawn_position()==5);
    assert(zone.get_winner()==playerB);

    cout << zone.print() << endl;
}

void military_win_test() {
    shared_ptr<Player> playerA(new Player("gabriel", 10));
    shared_ptr<Player> playerB(new Player("catherine", 0));
    auto zone = ConflictZone(6, playerA, playerB);

    auto military1 = make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost(1), 1));
    auto military2 = make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost(4), 2));
    auto military3 = make_shared<MilitaryBuilding>(*new MilitaryBuilding(Cost(2), 3));

    playerA->claim(military1);
    playerA->build();
    assert(zone.get_pawn_position()==-1);
    assert(playerA->get_wealth().get_gold()==9);

    playerA->claim(military2);
    playerA->build();
    assert(zone.get_pawn_position()==-3);
    assert(playerA->get_wealth().get_gold()==5);

    playerA->claim(military3);
    playerA->build();
    assert(zone.get_pawn_position()==-6);
    assert(playerA->get_wealth().get_gold()==3);

    assert(zone.get_winner()==playerA);
    cout << zone.print() << endl;
}

void wonders_test() {
    vector<Impact> impacts1 { income_impact(1) };
    vector<Impact> impacts2 { income_impact(2) };
    vector<Impact> impacts3 { attack_impact(1) };
    vector<Impact> impacts4 { attack_impact(2) };

    auto wonder1 = make_shared<Wonder>(*new Wonder("wonder1", Cost(0), impacts1));
    auto wonder2 = make_shared<Wonder>(*new Wonder("wonder2", Cost(0), impacts2));
    auto wonder3 = make_shared<Wonder>(*new Wonder("wonder3", Cost(0), impacts3));
    auto wonder4 = make_shared<Wonder>(*new Wonder("wonder4", Cost(0), impacts4));

    auto bad1 = make_shared<RawMaterial>(*new RawMaterial(Cost(10), Wood));
    auto bad2 = make_shared<RawMaterial>(*new RawMaterial(Cost(10), Wood));
    auto bad3 = make_shared<RawMaterial>(*new RawMaterial(Cost(10), Wood));
    auto bad4 = make_shared<RawMaterial>(*new RawMaterial(Cost(10), Wood));

    auto playerA = make_shared<Player>(*new Player("gabriel", 0));
    auto playerB = make_shared<Player>(*new Player("catherine", 0));
    auto zone = ConflictZone(3, playerA, playerB);

    playerA->claim_wonder(wonder1);
    playerA->claim_wonder(wonder2);
    playerA->claim_wonder(wonder3);
    playerA->claim_wonder(wonder4);

    assert(playerA->get_wealth().get_gold()==0);
    playerA->claim(bad1);
    playerA->build_wonder(wonder1);
    assert(playerA->get_wealth().get_gold()==1);

    playerA->claim(bad2);
    playerA->build_wonder(wonder2);
    assert(playerA->get_wealth().get_gold()==3);

    playerA->claim(bad3);
    playerA->build_wonder(wonder3);
    assert(zone.get_pawn_position()==-1);

    playerA->claim(bad4);
    playerA->build_wonder(wonder4);
    assert(zone.get_pawn_position()==-3);
    assert(zone.get_winner()==playerA);
}

void sell_building_test() {
    auto commerce_1 = make_shared<CommercialBuilding>(*new CommercialBuilding(Cost(0),4));
    auto commerce_2 = make_shared<CommercialBuilding>(*new CommercialBuilding(Cost(0),6));

    auto wood = make_shared<RawMaterial>(*new RawMaterial(Cost(15), Wood));
    auto clay = make_shared<RawMaterial>(*new RawMaterial(Cost(0), Clay));

    Player player("john", 0);
    auto graveyard = make_shared<Graveyard>(*new Graveyard());

    player.claim(commerce_1);
    player.build();
    assert(player.get_wealth().get_gold()==4);

    assert(!player.enough_wealth(wood));
    player.claim(wood);
    player.sell(graveyard);
    assert(player.get_wealth().get_gold()==7);

    player.claim(commerce_2);
    player.build();
    assert(player.get_wealth().get_gold()==13);
    player.claim(clay);
    player.sell(graveyard);
    cout << player.print() << endl;
    assert(player.get_wealth().get_gold()==17);

    assert(graveyard->size()==2);
}

void quantity_test() {
    auto wood = make_shared<RawMaterial>(*new RawMaterial(Cost(1), Wood));
    auto clay = make_shared<RawMaterial>(*new RawMaterial(Cost(1), Clay));

    auto wonder1 = make_shared<Wonder>(*new Wonder("wonder1", Cost(0), vector<Impact>()));
    auto wonder2 = make_shared<Wonder>(*new Wonder("wonder2", Cost(0), vector<Impact>()));

    auto bad1 = make_shared<RawMaterial>(*new RawMaterial(Cost(10), Wood));
    auto bad2 = make_shared<RawMaterial>(*new RawMaterial(Cost(10), Wood));

    Player player("john", 2);

    assert(player.get_buildings().empty());
    assert(player.get_wonders().empty());
    player.claim(wood);
    assert(player.get_buildings().empty());
    player.build();
    assert(player.get_buildings().size()==1);
    player.claim(clay);
    player.build();
    assert(player.get_buildings().size()==2);
    player.claim_wonder(wonder1);
    assert(player.get_wonders().size()==1);
    player.claim(bad1);
    player.build_wonder(wonder1);
    assert(player.get_wonders().size()==1);
    player.claim(bad2);
    player.claim_wonder(wonder2);
    assert(player.get_wonders().size()==2);
}

void cost_tweak_test() {
    Player player("john", 2);
    auto opponent=make_shared<Player>(*new Player("jean", 2));

    auto wood = make_shared<RawMaterial>(*new RawMaterial(Cost(0), Wood));
    vector<RessourceType> market {Wood, Clay};
    auto commerce = make_shared<CommercialBuilding>(*new CommercialBuilding(Cost(0), market));

    assert(player.get_cost(Wood, opponent)==2);
    assert(player.get_cost(Clay, opponent)==2);
    assert(player.get_cost(Stone, opponent)==2);
    opponent->claim(wood);
    opponent->build();
    assert(player.get_cost(Wood, opponent)==3);
    assert(player.get_cost(Clay, opponent)==2);
    assert(player.get_cost(Stone, opponent)==2);
    player.claim(commerce);
    player.build();
    assert(player.get_cost(Wood, opponent)==1);
    assert(player.get_cost(Clay, opponent)==1);
    assert(player.get_cost(Stone, opponent)==2);

}

void test_all() {
    run("player_test", player_test);
    run("conflict_zone_test", conflict_zone_test);
    run("military_win_test", military_win_test);
    run("wonders_test", wonders_test);
    run("sell_building_test", sell_building_test);
    run("quantity_test", quantity_test);
    run("cost_tweak_test", cost_tweak_test);
}