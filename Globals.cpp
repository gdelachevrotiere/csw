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
    };

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