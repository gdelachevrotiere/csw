#include "Game.h"

Game::Game(
    shared_ptr<Player> playerA,
    shared_ptr<Player> playerB,
    vector<shared_ptr<Wonder>> wonders,
    vector<shared_ptr<Building>> buildings
) {
	this->playerA = playerA;
	this->playerB = playerB;
	conflictZone = make_unique<ConflictZone>(*new ConflictZone(3));
    this->wonders = wonders;
    this->city = make_unique<City>(*new City(buildings));
}

Game::~Game() {

}

