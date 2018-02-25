/*
 * Game.h
 *
 *  Created on: Feb 25, 2018
 *      Author: root
 */

#ifndef GAME_H_
#define GAME_H_

#include "Player.h"

class Game {
	Player *a, *b;
public:
	Game(Player *, Player *);
	virtual ~Game();
};

#endif /* GAME_H_ */
