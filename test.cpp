#include "Globals.h"
#include "Player.h"
#include "RawMaterial.h"
#include "Wonder.h"
#include "ConflictZone.h"
#include "MilitaryBuilding.h"
#include "CommercialBuilding.h"
#include "City.h"
#include "CityNode.h"

int totalTest = 0;
int successTest = 0;

void run(const string &name, const function<void()>& lambda) {
    cout << "[UNIT] Starting " << name << "..." << endl;
    totalTest++;
    try {
        lambda();
        successTest++;
    } catch (const runtime_error& error) {
        cout << "error is: " << error.what() << endl;
    }
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
    assert(player.get_gold() == 0);
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
    assert(player.get_gold() == 0);

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
    assert(playerA->get_gold()==9);

    playerA->claim(military2);
    playerA->build();
    assert(zone.get_pawn_position()==-3);
    assert(playerA->get_gold()==5);

    playerA->claim(military3);
    playerA->build();
    assert(zone.get_pawn_position()==-6);
    assert(playerA->get_gold()==3);

    assert(zone.get_winner()==playerA);
    cout << zone.print() << endl;
}

void wonders_test() {
    vector<Impact> impacts1 { lambda::income_impact(1) };
    vector<Impact> impacts2 { lambda::income_impact(2) };
    vector<Impact> impacts3 { lambda::attack_impact(1) };
    vector<Impact> impacts4 { lambda::attack_impact(2) };

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

    assert(playerA->get_gold()==0);
    playerA->claim(bad1);
    playerA->build_wonder(wonder1);
    assert(playerA->get_gold()==1);

    playerA->claim(bad2);
    playerA->build_wonder(wonder2);
    assert(playerA->get_gold()==3);

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
    assert(player.get_gold()==4);

    assert(!player.enough_wealth(wood));
    player.claim(wood);
    player.sell(graveyard);
    assert(player.get_gold()==7);

    player.claim(commerce_2);
    player.build();
    assert(player.get_gold()==13);
    player.claim(clay);
    player.sell(graveyard);
    cout << player.print() << endl;
    assert(player.get_gold()==17);

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

void shared_production_test() {
    auto bad1 = make_shared<RawMaterial>(*new RawMaterial(Cost(10), Wood));
    auto bad2 = make_shared<RawMaterial>(*new RawMaterial(Cost(10), Wood));

    auto wonder1 = make_shared<Wonder>(*new Wonder("wonder1", Cost(0), vector<RessourceType>({Wood, Stone}) ));
    auto wonder2 = make_shared<Wonder>(*new Wonder("wonder2", Cost(0), vector<RessourceType>({Wood, Clay}) ));

    Player player("john", 2);
    player.claim_wonder(wonder1);
    player.claim_wonder(wonder2);
    assert(player.get_production_alternatives().size() == 1);
    player.claim(bad1);
    player.build_wonder(wonder1);
    assert(player.get_production_alternatives().size() == 2);
    player.claim(bad2);
    player.build_wonder(wonder2);
    assert(player.get_production_alternatives().size() == 4);
}

void total_cost_test() {
    auto b1 = make_shared<RawMaterial>(*new RawMaterial(Cost(0), Wood));
    auto b2 = make_shared<RawMaterial>(*new RawMaterial(Cost(1), Wood));
    auto b3 = make_shared<RawMaterial>(*new RawMaterial(Cost(1), Clay));
    auto b4 = make_shared<RawMaterial>(*new RawMaterial(Cost(1), Clay));
    auto b5 = make_shared<RawMaterial>(*new RawMaterial(Cost(2), Stone));
    auto b6 = make_shared<RawMaterial>(*new RawMaterial(Cost(2), Stone));

    auto playerA = make_shared<Player>(*new Player("gabriel", 2));
    auto playerB = make_shared<Player>(*new Player("catherine", 5));

    for (const auto& b: {b1, b2, b3}) playerA->qbuild(b);
    for (const auto& b: {b4, b5, b6}) playerB->qbuild(b);

    assert(playerA->get_gold()==0);
    playerA->earn(5);
    auto market = vector<RessourceType>({Stone});
    auto commerce1 = make_shared<CommercialBuilding>(*new CommercialBuilding(Cost(0, {{Wood,1}, {Stone,1}}), market));
    assert(playerA->get_total_cost(commerce1, playerB)==4);
    playerA->qbuild(commerce1);

    auto commerce2 = make_shared<CommercialBuilding>(*new CommercialBuilding(Cost(0, {{Wood,1}, {Stone,1}}), 0));
    assert(commerce1->get_market()==vector<RessourceType>({Stone}));
    assert(playerA->get_total_cost(commerce2, playerB)==1);
    playerA->qbuild(commerce2);
}

void city_test() {
    vector<shared_ptr<Building>> buildings;
    vector<int> v {0, 1, 2, 0, 2, 1, 1, 3, 1, 2};
    for(const auto& i: v) {
        buildings.push_back( make_shared<RawMaterial>(*new RawMaterial(Cost(i), Wood)) );
    };

    City city(buildings);
    cout << city.print() << endl;
    auto available = city.get_available_buildings();
    assert(city.get_size()==10);
    cout << city.print_available() << endl;
    assert(available.size()==4);
    assert(city.get_available_ids() == vector<int>({ 6, 7, 8, 9 }));
    assert(city.get_unordered_nodes()[9]->is_childless());
    city.pop(9);
    assert(city.get_available_ids() == vector<int>({ 6, 7, 8 }));
    city.pop(8);
    assert(city.get_available_ids() == vector<int>({ 5, 6, 7}));
    city.pop(6);
    city.pop(7);
    assert(city.get_available_ids() == vector<int>({ 3, 4, 5}));
    city.pop(3);
    city.pop(4);
    city.pop(5);
    assert(city.get_available_ids() == vector<int>({ 1, 2 }));
    city.pop(1);
    city.pop(2);
    assert(city.get_available_ids() == vector<int>({ 0 }));
    city.pop(0);
    assert(city.get_size()==0);

}

void dynamic_test() {

}

void test_all() {
    cout << "===================================" << endl;
    cout << "Starting unit test...." << endl;
    cout << "===================================" << endl;

    run("player_test", player_test);
    run("conflict_zone_test", conflict_zone_test);
    run("military_win_test", military_win_test);
    run("wonders_test", wonders_test);
    run("sell_building_test", sell_building_test);
    run("quantity_test", quantity_test);
    run("cost_tweak_test", cost_tweak_test);
    run("shared_production_test", shared_production_test);
    run("total_cost_test", total_cost_test);
    run("city_test", city_test);

    cout << "===================================" << endl;
    cout << "Tests completed ! Success [" << successTest << "/" << totalTest << "]" << endl;
    cout << "===================================" << endl;

    if (successTest < totalTest)
        throw runtime_error("some unit tests failed");
}
