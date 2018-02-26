#ifndef GAME_H_
#define GAME_H_

#include "Player.h"
#include "ConflictZone.h"

class Game {
	Player *a, *b;
	ConflictZone conflict_zone;
public:
	Game(Player *, Player *);
	virtual ~Game();
};

#endif /* GAME_H_ */
