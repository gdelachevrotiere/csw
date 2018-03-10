#include "City.h"

City::City(vector<shared_ptr<Building>> buildings) {
    this->buildings = buildings;
}

void City::print() {
    cout << "The following buildings are available: " << endl;
    cout << "-------------------------------------------" << endl;
    for (int i=0; i<buildings.size(); i++) {
        cout << i << ") ";
        buildings[i]->print();
    }
}

long City::get_size() {
    return buildings.size();
}

City::~City() {

}