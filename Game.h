#ifndef GAME_H_
#define GAME_H_

#include "Player.h"
#include "ConflictZone.h"
#include "Wonder.h"
#include "City.h"

class Game {
	shared_ptr<Player> playerA, playerB;
    unique_ptr<ConflictZone> conflictZone;
	vector<shared_ptr<Wonder>> wonders;
	unique_ptr<City> city;
    shared_ptr<Player> playing;
public:
	Game(shared_ptr<Player>, shared_ptr<Player>, vector<shared_ptr<Wonder>>, vector<shared_ptr<Building>>);
	virtual ~Game();

	void start();
	void do_round();
};

#endif
