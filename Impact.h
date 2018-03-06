#ifndef IMPACT_H_
#define IMPACT_H_

#include "Player.h"

class Impact {
    function<void(shared_ptr<Player>)> lambda;
public:
	explicit Impact(function<void(shared_ptr<Player>)>);
	virtual ~Impact();

	void apply(shared_ptr<Player>);
};

#endif
