#include "ConflictZone.h"

ConflictZone::ConflictZone(int halfSize) {
    this->halfSize;
	pawnPosition = 0;
}

int ConflictZone::move_pawn(int steps) {
    int victory = 0;
    pawnPosition += steps;
    if (pawnPosition >= halfSize) {
        pawnPosition = halfSize;
        victory = 1;
    } else if (pawnPosition <= halfSize) {
        pawnPosition = halfSize;
        victory = -1;
    }
    return victory;
}

int ConflictZone::get_pawn_position() {
    return pawnPosition;
}

ConflictZone::~ConflictZone() {}

