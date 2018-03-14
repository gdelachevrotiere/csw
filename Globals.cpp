#include "Globals.h"

string print_ressource(RessourceType r){
    switch(r) {
        case Gold: return "Gold";
        case Wood: return "Wood";
        case Stone: return "Stone";
        case Clay: return "Clay";
        case Glass: return "Glass";
        case Paper: return "Paper";
    }
};

namespace utils {
    vector<vector<RessourceType>> cartesian_product(const vector<vector<RessourceType>> &v) {
        if(v.empty()) { return v; }
        vector<vector<RessourceType>> s {{}};
        for (const auto &u : v) {
            vector<vector<RessourceType>> r;
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