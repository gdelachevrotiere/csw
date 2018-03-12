#ifndef Artifact_H_
#define Artifact_H_

#include "Globals.h"

class Player;

class Artifact {
	int victoryPoints;
    function<void(Player*)> preModifier;
    function<void(Player*)> postModifier;
public:
	Artifact();
	virtual ~Artifact();
};

#endif
