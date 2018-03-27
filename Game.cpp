#include "Game.h"

Game::Game(
    shared_ptr<Player> playerA,
    shared_ptr<Player> playerB,
    vector<shared_ptr<Wonder>> wonders,
    shared_ptr<City> city,
    shared_ptr<ConflictZone> conflictZone
) {
	this->playerA = playerA;
	this->playerB = playerB;
	this->conflictZone = conflictZone;
    this->wonders = wonders;
    this->city = city;

    playing = playerA;
}

string Game::print_players() {
    stringstream sout;
    sout << "The players are: " << endl;
    sout << "-----------------" << endl;
    sout << playerA->print() << endl;
    sout << playerB->print() << endl;
    return sout.str();
}

shared_ptr<Player> Game::get_playing() {
    return playing;
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
    cout << "Claim a building[0-" << city->get_size()-1 << "]: ";

    string claim;
    cin >> claim;
    cout << endl;

    //auto claimed = city->pop(stoi(claim));
    //playing->claim(claimed);

    cout << "The building [" << claim << "] was claimed." << endl;
    cout << endl;
    cout << "1) Build" << endl;
    cout << "2) Sell" << endl;
    cout << "3) Build Wonder" << endl;
    cout << endl;
    cout << "Choose an action[1-3]: " << endl;

    string action;
    cin >> action;
    cout << endl;

    switch (stoi(action)) {
        case 1:
            playing->build();
            break;
        case 2:
            playing->sell(graveyard);
            break;
        case 3:
            throw runtime_error("not yet implemented");
        default:
            throw runtime_error("option invalid");
    };

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
    }
}
