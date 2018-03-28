#ifndef CONFLICTZONE_H_
#define CONFLICTZONE_H_

#include "Globals.h"

class Player;

class ConflictZone {
	int halfSize;
    int pawnPosition;
	shared_ptr<Player> playerA, playerB;
public:
	ConflictZone(int, shared_ptr<Player>, shared_ptr<Player>);
    ConflictZone(shared_ptr<Player> a, shared_ptr<Player> b): ConflictZone(0, a, b) { }
    int get_pawn_position();
    void register_attack(Player*, int);
    void move_pawn(int);
	optional<shared_ptr<Player>> get_winner();
    string print();
    string pretty_print();
    virtual ~ConflictZone() { }
};

#endif
