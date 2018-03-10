#include "Globals.h"
#include "Player.h"
#include "RawMaterial.h"
#include "Wonder.h"
#include "ConflictZone.h"
#include "MilitaryBuilding.h"

void player_test() {
    auto wood = make_shared<RawMaterial>(*new RawMaterial(Cost(1), Wood));
    auto clay = make_shared<RawMaterial>(*new RawMaterial(Cost(2, RessourceMap{{Wood, 1}}), Clay, 2));
    auto appian = make_shared<Wonder>(*new Wonder("The Appian Way", Cost(2, RessourceMap{{Wood, 1},{Clay, 2}}), vector<shared_ptr<Impact>>()));

    Player player("john", 0);
    player.get_wallet()->receive(1);

    assert(player.get_wallet()->get_gold()==1);
    player.claim(appian);
    assert(!player.can_build(wood));
    player.claim(wood);
    assert(player.can_build(wood));
    assert(!player.can_build(clay));
    player.build(wood);
    assert(wood->is_built());
    assert(!clay->is_built());
    assert(player.get_wealth().get_gold() == 0);
    player.get_wallet()->receive(2);
    player.claim(clay);
    assert(player.can_build(clay));
    player.build(clay);
    assert(clay->is_built());
    assert(player.get_wallet()->get_gold()==0);
    assert(!player.can_build(appian));
    player.get_wallet()->receive(2);
    assert(player.can_build(appian));
    player.build(appian);
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
    playerA->build(military1);
    assert(zone.get_pawn_position()==-1);
    assert(playerA->get_wealth().get_gold()==9);

    playerA->claim(military2);
    playerA->build(military2);
    assert(zone.get_pawn_position()==-3);
    assert(playerA->get_wealth().get_gold()==5);

    playerA->claim(military3);
    playerA->build(military3);
    assert(zone.get_pawn_position()==-6);
    assert(playerA->get_wealth().get_gold()==3);

    assert(zone.get_winner()==playerA);
    cout << zone.print() << endl;
}

void wonders_test() {
    auto grant_1_gold = Impact(make_grant_gold(1));
    auto grant_2_gold = Impact(make_grant_gold(2));
    auto attack_1 = Impact(make_attack(1));
    auto attack_2 = Impact(make_attack(2));

    vector<shared_ptr<Impact>> impacts1 { make_shared<Impact>(grant_1_gold) };
    vector<shared_ptr<Impact>> impacts2 { make_shared<Impact>(grant_2_gold) };
    vector<shared_ptr<Impact>> impacts3 { make_shared<Impact>(attack_1) };
    vector<shared_ptr<Impact>> impacts4 { make_shared<Impact>(attack_2) };
    auto wonder1 = make_shared<Wonder>(*new Wonder("wonder1", Cost(0), impacts1));
    auto wonder2 = make_shared<Wonder>(*new Wonder("wonder2", Cost(0), impacts2));
    auto wonder3 = make_shared<Wonder>(*new Wonder("wonder3", Cost(0), impacts3));
    auto wonder4 = make_shared<Wonder>(*new Wonder("wonder4", Cost(0), impacts4));

    shared_ptr<Player> playerA(new Player("gabriel", 0));
    shared_ptr<Player> playerB(new Player("catherine", 0));
    auto zone = ConflictZone(3, playerA, playerB);

    assert(playerA->get_wealth().get_gold()==0);
    playerA->claim(wonder1);
    playerA->build(wonder1);
    assert(playerA->get_wealth().get_gold()==1);

    playerA->claim(wonder2);
    playerA->build(wonder2);
    assert(playerA->get_wealth().get_gold()==3);

    playerA->claim(wonder3);
    playerA->build(wonder3);
    assert(zone.get_pawn_position()==-1);

    playerA->claim(wonder4);
    playerA->build(wonder4);
    assert(zone.get_pawn_position()==-3);
    assert(zone.get_winner()==playerA);
}

void test_all() {
    player_test();
    conflict_zone_test();
    military_win_test();
    wonders_test();
}