#ifndef CWS_GLOBALS_H
#define CWS_GLOBALS_H

#include <map>
#include <array>
#include <vector>
#include <iostream>
#include <memory>
#include <functional>
#include <algorithm>
#include <sstream>
#include <functional>
#include <optional>
#include <cassert>
using namespace std;
using namespace std::placeholders;

class Player;
class Building;

enum RessourceType { Gold, Wood, Stone, Clay, Glass, Paper };
enum Link { Water, Wall, Bullseye};
typedef map<RessourceType,int> RessourceMap;
typedef function<void(Player*)> Impact;
typedef function<Player(Player)> Tweak;
typedef vector<shared_ptr<Building>> Graveyard;
void test_all();
string print_ressource(RessourceType r);

namespace utils {
    vector<vector<RessourceType>> cartesian_product(const vector<vector<RessourceType>> &v);
}

#endif
