#include "lambda.h"
#include "Player.h"

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