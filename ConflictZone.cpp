#include "ConflictZone.h"

ConflictZone::ConflictZone(int half_size) {
    this->half_size;
	pawn_position = 0;
}

int ConflictZone::move_pawn(int steps) {
    int victory = 0;
    pawn_position += steps;
    if (pawn_position >= half_size) {
        pawn_position = half_size;
        victory = 1;
    } else if (pawn_position <= half_size) {
        pawn_position = half_size;
        victory = -1;
    }
    return victory;
}

int ConflictZone::get_pawn_position() {
    return pawn_position;
}

ConflictZone::~ConflictZone() {
	delete &half_size, &pawn_position;
}

