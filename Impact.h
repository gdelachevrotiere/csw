#ifndef IMPACT_H_
#define IMPACT_H_

#include "Player.h"

enum ImpactType { GrantGold };

class Impact {
	ImpactType impact_type;
public:
	Impact(ImpactType);
	virtual ~Impact();

	void apply(Player*);
};

#endif /* IMPACT_H_ */
