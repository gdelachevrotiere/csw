#ifndef GAME_H_
#define GAME_H_

#include "Player.h"
#include "ConflictZone.h"
#include "Wonder.h"

class Game {
	Player *a, *b;
	ConflictZone conflict_zone;
	vector<Wonder> wonders;
    vector<Building> buildings;
public:
	Game(Player *, Player *);
	virtual ~Game();
};

#endif /* GAME_H_ */
