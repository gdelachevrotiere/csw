#ifndef WONDER_H_
#define WONDER_H_

#include <string>
#include <array>
#include <map>
#include <iterator>
#include <vector>
#include "Ressource.h"
#include "Impact.h"
using namespace std;

class Wonder {
	string name;
	bool built;
	map<RessourceType, int> cost;
public:
	Wonder(string, array<int, 5>, vector<Impact>);
	virtual ~Wonder();

	void build();
	map<RessourceType, int> get_cost();
	bool is_built();
};

#endif
