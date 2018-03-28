#include "City.h"

City::City(const vector<shared_ptr<Building>>& buildings) {
    if (buildings.size() < _size)
        throw runtime_error("buildings vector size has to be at least 10");

    auto shuffled = buildings;
    random_shuffle(shuffled.begin(), shuffled.end());

    for (int i=0; i<_size; i++) {
        auto n = make_shared<optional<CityNode>>(*new CityNode(i, shuffled[i]));
        nodes.push_back(n);
    }

    for (auto e: _edges1) {
        (*nodes[e[0]])->set_left(nodes[e[1]]);
        (*nodes[e[0]])->set_right(nodes[e[2]]);
    }
}

shared_ptr<Building> City::pop(const int& i) {
    if (!nodes[i])
        throw runtime_error("the node has already been popped");
    if (!(*nodes[i])->is_childless())
        throw runtime_error("the node still has children and can't be popped");

    auto building = (*nodes[i])->get_building();
    *nodes[i] = optional<CityNode>(nullopt);
    return building;
}

vector<shared_ptr<CityNode>> City::get_unordered_nodes() {
    vector<shared_ptr<CityNode>> alive;
    for (auto n: nodes) {
        if (*n) {
            alive.push_back(make_shared<CityNode>(**n));
        }
    }
    return alive;
}

vector<shared_ptr<Building>> City::get_unordered_buildings() {
    vector<shared_ptr<Building>> buildings;
    for( auto n: get_unordered_nodes()) {
        buildings.push_back(n->get_building());
    }
    return buildings;
}

vector<shared_ptr<CityNode>> City::get_available_nodes() {
    vector<shared_ptr<CityNode>> available;
    for( auto n: get_unordered_nodes()) {
        if (n->is_childless()) {
            available.push_back(n);
        }
    }
    return available;
}

vector<int> City::get_available_ids() {
    vector<int> available;
    for( auto n: get_available_nodes()) {
        available.push_back(n->get_id());
    }
    return available;
}

vector<shared_ptr<Building>> City::get_available_buildings() {
    vector<shared_ptr<Building>> available;
    for( auto n: get_available_nodes()) {
        available.push_back(n->get_building());
    }
    return available;
}

string City::print() {
    stringstream sout;
    sout << "[CITY]" << endl;
    sout << "-------------------------------------------" << endl;
    for (auto n : get_unordered_nodes()) {
        auto left = *n->get_left();
        auto leftIdx = left ? to_string(left->get_id()) : "*";
        auto right = *n->get_right();
        auto rightIdx = right ? to_string(right->get_id()) : "*";
        auto available = "[" + leftIdx + "," + rightIdx + "]";
        sout << n->get_id() << ") " << available << " " << n->get_building()->pretty_print() << endl;
    }
    sout << "-------------------------------------------" << endl;
    return sout.str();
}

string City::print_available() {
    stringstream sout;
    sout << "The following buildings are available: " << endl;
    sout << "-------------------------------------------" << endl;
    for (auto n : get_available_nodes()) {
        sout << n->get_id() << ") " << n->get_building()->pretty_print() << endl;
    }
    return sout.str();
}

long City::get_size() {
    return get_unordered_nodes().size();
}
