#ifndef CWS_COST_H
#define CWS_COST_H

#include "Globals.h"

class Cost {
    int gold;
    RessourceMap ressources;
public:
    Cost(int, RessourceMap);
    Cost(RessourceMap r): Cost(0, r) {};
    Cost(int g): Cost(g, RessourceMap()) {};
    Cost(): Cost(0, RessourceMap()) {};
    virtual ~Cost();

    int get_ressource(RessourceType);
};


#endif
