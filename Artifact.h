#ifndef Artifact_H_
#define Artifact_H_

#include "Globals.h"

class Player;

class Artifact {
	int victoryPoints;
    Impact preModifier;
	Impact postModifier;
public:
	Artifact(const int&, const Impact&, const Impact&);
	virtual ~Artifact() { };

	int get_victory_points();
	Impact get_pre_modifier();
	Impact get_post_modifier();
};

#endif
