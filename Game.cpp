#include "Game.h"

Game::Game(
    shared_ptr<Player> playerA,
    shared_ptr<Player> playerB,
    vector<shared_ptr<Wonder>> wonders,
    shared_ptr<City> city
) {
	this->playerA = playerA;
	this->playerB = playerB;
    playing = playerA;
	conflictZone = make_unique<ConflictZone>(*new ConflictZone(3, playerA, playerB));
    this->wonders = wonders;
    this->city = city;
}

string Game::print_players() {
    stringstream sout;
    sout << "The players are: " << endl;
    sout << "-----------------" << endl;
    sout << playerA->print() << endl;
    sout << playerB->print() << endl;
    return sout.str();
}

optional<shared_ptr<Player>> Game::get_winner() {
    int a = 1;
    int b = 2;
    optional<shared_ptr<Player>> none = nullopt;
    return (a == 2) ? playerA : none;
}

void Game::set_next_turn() {
    playing = (playing == playerA) ? playerB : playerA;
}

void Game::do_round() {
    cout << print_players() << endl;
    cout << city->print() << endl;
    cout << "Turn: " << playing->get_name() << endl;
    cout << "Choose a building[0-" << city->get_size()-1 << "]: ";

    string chosen;
    cin >> chosen;

    auto winner = get_winner();
    if (winner) {
        cout << "The winner is: " << (*winner)->get_name() << endl;
    }
    set_next_turn();
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

