#include "Game.h"

Game::Game(
    shared_ptr<Player> playerA,
    shared_ptr<Player> playerB,
    vector<shared_ptr<Wonder>> wonders,
    vector<shared_ptr<Building>> buildings
) {
	this->playerA = playerA;
	this->playerB = playerB;
    playing = playerA;
	conflictZone = make_unique<ConflictZone>(*new ConflictZone(3));
    this->wonders = wonders;
    this->city = make_unique<City>(*new City(buildings));
}

void Game::do_round() {
    cout << "The players are: " << endl;
    cout << "-----------------" << endl;
    playerA->print();
    playerB->print();
    cout << endl;

    string chosen;

    city->print();
    cout << endl;
    cout << "Turn: " << playing->get_name() << endl;
    cout << "Choose a building[0-" << city->get_size()-1 << "]: ";
    cin >> chosen;

    playing = (playing == playerA) ? playerB : playerA;
}

void Game::start() {
    bool gameCompleted {false};
    string dummy;

    cout << "Welcome to 7 Wonders Duel C++ version" << endl << endl;
    while(!gameCompleted) {
        do_round();
        cin >> dummy;
    }
};

Game::~Game() {

}

