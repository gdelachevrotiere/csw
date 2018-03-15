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
enum Science { Mathematics, Physics, Chemistry, Biology, Psychology, Medecine, Engineering };
typedef map<RessourceType,int> RessourceMap;
typedef function<void(Player*)> Impact;
typedef function<Player(Player)> Tweak;
typedef vector<shared_ptr<Building>> Graveyard;
void test_all();

namespace lambda {

    Impact income_impact(const int &n);
    Impact attack_impact(const int &n);
    Impact multi_impact(const vector<Impact>& impacts);

}

namespace util {

    string print_ressource(RessourceType r);

    template<class T>
    vector<vector<T>> cartesian_product(const vector<vector<T>> &v) {
        if(v.empty()) { return v; }
        vector<vector<T>> s {{}};
        for (const auto &u : v) {
            vector<vector<T>> r;
            for (const auto &x : s) {
                for (const auto &y : u) {
                    r.push_back(x);
                    r.back().push_back(y);
                }
            }
            s = move(r);
        }
        return s;
    }
}

#endif
