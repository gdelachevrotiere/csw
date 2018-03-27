#include "Globals.h"
#include "Player.h"

namespace util {

    string print_ressource(RessourceType r){
        switch(r) {
            case Gold: return "Gold";
            case Wood: return "Wood";
            case Stone: return "Stone";
            case Clay: return "Clay";
            case Glass: return "Glass";
            case Paper: return "Paper";
        }
    }

    string print_science(Science s) {
        switch(s) {
            case Mathematics: return "Mathematics";
            case Physics: return "Physics";
            case Chemistry: return "Chemistry";
            case Biology: return "Biology";
            case Psychology: return "Psychology";
            case Medecine: return "Medecine";
            case Engineering: return "Engineering";
        }
    }

    shared_ptr<Building> pop(vector<shared_ptr<Building>>& v) {
        if(v.empty()) {
            throw runtime_error("the vector is empty and so we can't pop front");
        }
        auto x = v.front();
        v.erase(v.begin());
        return x;
    }

}

namespace lambda {

    Impact income_impact(const int &n) {
        auto lambda = [](Player *p, const int &n) {
            p->earn(n);
        };
        return bind(lambda, _1, n);
    }

    Impact attack_impact(const int &n) {
        auto lambda = [](Player *p, const int &n) {
            p->attack(n);
        };
        return bind(lambda, _1, n);
    }

    Impact multi_impact(const vector<Impact>& impacts) {
        auto lambda = [](Player *p, vector<Impact> impacts) {
            for (const auto &i: impacts) {
                i(p);
            }
        };
        return bind(lambda, _1, impacts);
    }

}
