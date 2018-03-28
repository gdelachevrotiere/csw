#include "Game.h"

Game::Game(
    const shared_ptr<Player> &playerA,
    const shared_ptr<Player> &playerB,
    const vector<shared_ptr<Wonder>> &wonders,
    const vector<shared_ptr<Building>> &buildings
) {
    gameCompleted = false;

	this->playerA = playerA;
	this->playerB = playerB;
    this->conflictZone = make_shared<ConflictZone>(*new ConflictZone(3, playerA, playerB));
    this->wonders = wonders;
    this->city = make_shared<City>(*new City(buildings));
    this->graveyard = make_shared<Graveyard>(*new vector<shared_ptr<Building>>());

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

bool Game::is_completed() {
    if (city->get_available_nodes().size() == 0) {
        return true;
    }
    return false;
}

optional<shared_ptr<Player>> Game::get_winner() {
    optional<shared_ptr<Player>> conflictWinner = conflictZone->get_winner();
    if (conflictWinner) {
        return *conflictWinner;
    }

    optional<shared_ptr<Player>> winner = nullopt;
    if (is_completed()) {
        auto vpA = playerA->get_victory_points();
        auto vpB = playerB->get_victory_points();
        if (vpA > vpB) winner = playerA;
        if (vpB > vpA) winner = playerB;
    }

    return winner;
}

void Game::set_next_turn() {
    playing = (playing == playerA) ? playerB : playerA;
}

void Game::do_round() {

    string claim;
    int iclaim;
    bool claimValid = false;
    string any;

    cout << conflictZone->get_pawn_position() << endl;
    cout << conflictZone->pretty_print() << endl << endl;
    cout << city->print() << endl;
    cout << "Turn: " << playing->print() << endl;

    while (!claimValid) {
        cout << "Claim a building[0-" << city->get_size()-1 << "]: ";
        cin >> claim;
        cout << endl;
        iclaim = stoi(claim);

        auto ids = city->get_available_ids();
        claimValid = find(ids.begin(), ids.end(), iclaim) != ids.end();
        if (!claimValid) {
            cout << "---------- Invalid choice... this building is not available !" << endl;
        }
    }

    cout << "The building [" << claim << "] was claimed." << endl << endl;
    auto building = city->pop(iclaim);
    playing->claim(building);

    string action;
    int iaction;
    bool actionValid = false;

    cout << "1) Build" << endl;
    cout << "2) Sell" << endl;
    cout << "3) Build Wonder" << endl;
    cout << endl;

    while(!actionValid) {
        cout << "Choose an action[1-3]: ";
        cin >> action;
        iaction = stoi(action);

        if( iaction == 1 ) {
            actionValid = playing->can_build(building);
        } else if ( iaction == 2 ) {
            actionValid = true;
        } else if ( iaction == 3) {
            actionValid = false;
        }

        if (!actionValid) {
            cout << "---------- Invalid choice... this action is not possible !";
        }

        cout << endl;
    }

    cout << "The action [" << iaction << "] was chosen." << endl << endl;

    shared_ptr<Building> active;
    int before, after;
    switch (iaction) {
        case 1:
            active = playing->get_active();
            playing->build();
            cout << "The following building was built: " << active->print() << endl << endl;
            break;
        case 2:
            before = playing->get_gold();
            playing->sell(graveyard);
            after = playing->get_gold();
            cout << "The building was sold, the following income was received: " << after - before << endl << endl;
            break;
        case 3:
            throw runtime_error("not yet implemented");
        default:
            throw runtime_error("option invalid");
    };

    auto winner = get_winner();
    if (winner) {
        cout << "The winner is: " << (*winner)->get_name() << endl;
        gameCompleted = true;
    }

}

void Game::start() {
    cout << "Welcome to 7 Wonders Duel C++ version" << endl << endl;
    cout << print_players() << endl;

    while(!gameCompleted) {
        do_round();
        if (!gameCompleted) set_next_turn();
    }

    cout << "Thanks for playing ! " << endl;
}
