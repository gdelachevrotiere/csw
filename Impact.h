#ifndef IMPACT_H_
#define IMPACT_H_

#include "Player.h"

class Impact {
    function<void(Player*)> lambda;
public:
	explicit Impact(function<void(Player*)>);
	virtual ~Impact();

	void resolve(Player*);
};

#endif
