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
typedef map<RessourceType,int> RessourceMap;
typedef function<void(Player*)> Impact;
typedef function<Player(Player)> Tweak;
typedef vector<shared_ptr<Building>> Graveyard;
void test_all();

#endif
