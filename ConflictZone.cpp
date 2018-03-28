#include "ConflictZone.h"
#include "Player.h"

ConflictZone::ConflictZone(int halfSize, shared_ptr<Player> playerA, shared_ptr<Player> playerB) {
    this->halfSize = halfSize;
	pawnPosition = 0;
    this->playerA = playerA;
    this->playerB = playerB;
    playerA->set_conflict_zone(this);
    playerB->set_conflict_zone(this);
}

void ConflictZone::register_attack(Player* player, int n) {
    if (player == playerA.get()) {
        move_pawn(-n);
    } else if (player == playerB.get()) {
        move_pawn(n);
    } else {
        throw runtime_error("This player pointer is unknown to the conflict zone");
    }
}

void ConflictZone::move_pawn(int steps) {
    if (get_winner()) {
        throw runtime_error("The conflict is already finished, can't move the pawn");
    }
    pawnPosition += steps;
    if (pawnPosition > halfSize) {
        pawnPosition = halfSize;
    } else if (pawnPosition < -halfSize) {
        pawnPosition = -halfSize;
    }
}

int ConflictZone::get_pawn_position() {
    return pawnPosition;
}

// PlayerA wins <-[-5....0....+5]-> PlayerB wins
optional<shared_ptr<Player>> ConflictZone::get_winner() {
    optional<shared_ptr<Player>> winner = nullopt;
    if (get_pawn_position() <= -halfSize) {
        winner = playerA;
    } else if (get_pawn_position() >= halfSize) {
        winner = playerB;
    }
    return winner;
}

string ConflictZone::print() {
    stringstream sout;
    sout << "ConflictZone[halfSize=" << halfSize << ":" << get_pawn_position()
         << ",A=" << playerA->get_name() << ",B=" << playerB->get_name() << "]";
    return sout.str();
}

string ConflictZone::pretty_print() {
    stringstream sout;
    int length = 1 + 2 * halfSize;
    sout << "[CONFLICT ZONE]" << endl;
    sout << "-------------------";
    for (int i=0; i<length; i++) { sout << "-----"; }
    sout << endl;
    sout << "<" << playerB->get_name() << "> | ";
    for (int i=0; i<length; i++) {
        sout << ((halfSize + get_pawn_position()) == i ? " X |" : "   |");
    }
    sout << " <" << playerA->get_name() << ">" << endl;
    sout << "-------------------";
    for (int i=0; i<length; i++) { sout << "-----"; }
    return sout.str();
}
