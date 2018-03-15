#include "City.h"

City::City(const vector<shared_ptr<Building>>& buildings, const vector<int>& layers) {
    auto iter = buildings.begin();
    for( const auto& l: layers ) {
        vector<shared_ptr<Building>> thisLevel;
        for ( int i=0; i<l; i++ ) {
            thisLevel.push_back(*iter);
            iter++;
        }
        levels.push_back(thisLevel);
    }
}

shared_ptr<Building> City::pop(int i) {
    auto b = get_unordered_buildings();
    auto popped = b.at(i);
    b.erase(b.begin() + i);
    return popped;
}

vector<vector<shared_ptr<Building>>> City::get_levels() {
    return levels;
}

vector<shared_ptr<Building>> City::get_unordered_buildings() {
    vector<shared_ptr<Building>> buildings;
    for (const auto& l: levels) {
        for (const auto& b: l) {
            buildings.push_back(b);
        }
    }
    return buildings;
}

vector<shared_ptr<Building>> City::get_available_buildings() {
    return get_unordered_buildings();
}

string City::print() {
    auto buildings = get_available_buildings();
    stringstream sout;
    sout << "The following buildings are available: " << endl;
    sout << "-------------------------------------------" << endl;
    for (int i=0; i<buildings.size(); i++) {
        sout << i << ") " << buildings[i]->print();
    }
    return sout.str();
}

long City::get_size() {
    return get_available_buildings().size();
}