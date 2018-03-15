#ifndef CWS_CITY_H
#define CWS_CITY_H

#include "Globals.h"
#include "Building.h"

class City {
    vector<vector<shared_ptr<Building>>> levels;
public:
    City(const vector<shared_ptr<Building>>&, const vector<int>&);
    ~City() { };

    vector<vector<shared_ptr<Building>>> get_levels();
    vector<shared_ptr<Building>> get_unordered_buildings();
    vector<shared_ptr<Building>> get_available_buildings();

    long get_size();
    shared_ptr<Building> pop(int);
    string print();
};


#endif
