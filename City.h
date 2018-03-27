#ifndef CWS_CITY_H
#define CWS_CITY_H

#include "Globals.h"
#include "Building.h"
#include "CityNode.h"

class City {
    static const size_t _size = 10;
    vector<shared_ptr<optional<CityNode>>> nodes;
    const vector<array<int,3>> _edges1 {
                {0, 1, 2},
            {1, 3, 4}, {2, 4, 5},
        {3, 6, 7}, {4 ,7 ,8}, {5, 8, 9}
    };

public:
    City(const vector<shared_ptr<Building>>&);
    ~City() {}

    vector<shared_ptr<optional<CityNode>>> get_optional_nodes() { return nodes; }
    vector<shared_ptr<CityNode>> get_unordered_nodes();
    vector<shared_ptr<Building>> get_unordered_buildings();

    vector<shared_ptr<CityNode>> get_available_nodes();
    vector<int> get_available_ids();
    vector<shared_ptr<Building>> get_available_buildings();

    long get_size();
    shared_ptr<Building> pop(const int&);
    string print();
    string print_available();
};


#endif
