#include "City.h"

City::City(vector<shared_ptr<Building>> buildings) {
    this->buildings = buildings;
}

string City::print() {
    stringstream sout;
    sout << "The following buildings are available: " << endl;
    sout << "-------------------------------------------" << endl;
    for (int i=0; i<buildings.size(); i++) {
        sout << i << ") " << buildings[i]->print();
    }
    return sout.str();
}

long City::get_size() {
    return buildings.size();
}

City::~City() {

}