#ifndef GAME_H_
#define GAME_H_

#include "Player.h"
#include "ConflictZone.h"
#include "Wonder.h"
#include "City.h"

class Game {
    bool gameCompleted;
	shared_ptr<Player> playerA, playerB;
    shared_ptr<ConflictZone> conflictZone;
	vector<shared_ptr<Wonder>> wonders;
    shared_ptr<City> city;
    shared_ptr<Player> playing;
    shared_ptr<Graveyard> graveyard;
public:
	Game(
        const shared_ptr<Player>&,
        const shared_ptr<Player>&,
        const vector<shared_ptr<Wonder>>&,
        const vector<shared_ptr<Building>>&
    );
    virtual ~Game() { }

    bool is_completed();
	string print_players();
    shared_ptr<Player> get_playing();
	void set_next_turn();
    optional<shared_ptr<Player>> get_winner();
    void start();
	void do_round();
};

#endif
