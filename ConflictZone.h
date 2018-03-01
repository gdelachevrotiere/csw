#ifndef CONFLICTZONE_H_
#define CONFLICTZONE_H_

class ConflictZone {
	int halfSize;
    int pawnPosition;
public:
	ConflictZone(int);
    ConflictZone(): ConflictZone(0) {};
    int get_pawn_position();
    int move_pawn(int);
	virtual ~ConflictZone();
};

#endif
