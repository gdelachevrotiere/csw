#ifndef CITYNODE_H
#define CITYNODE_H

#include "Globals.h"

class CityNode;
typedef shared_ptr<optional<CityNode>> NodePtr;

class CityNode {
private:
    int id;
    shared_ptr<Building> building;
    NodePtr left;
    NodePtr right;

    NodePtr allocate(int id, const shared_ptr<Building>& building) {
        return make_shared<optional<CityNode>>(*new CityNode(id, building));
    }

    int get_child_size(NodePtr c) {
        return *c ? (**c).get_size() : 0;
    }

public:
    CityNode(int id, const shared_ptr<Building>& building) {
        this->id = id;
        this->building = building;
        left = make_shared<optional<CityNode>>(nullopt);
        right = make_shared<optional<CityNode>>(nullopt);
    }
    ~CityNode() {}

    int get_id() { return id; }
    NodePtr create_left(int id, const shared_ptr<Building>& building) {
        return left = allocate(id, building);
    }
    NodePtr create_right(int id, const shared_ptr<Building>& building) {
        return right = allocate(id, building);
    }
    void set_left(const NodePtr& node) { left = node; }
    void set_right(const NodePtr& node) { right = node; }
    NodePtr get_left() { return left; }
    NodePtr get_right() { return right; }
    bool is_childless() {
        return (!*left) && (!*right);
    }
    shared_ptr<Building> get_building() { return building; }

    vector<shared_ptr<CityNode>> get_descendents() {
        vector<shared_ptr<CityNode>> v { make_shared<CityNode>(*this) };
        if (*left) {
            for (auto n: (**left).get_descendents()) {
                v.push_back(n);
            }
        }
        if (*right) {
            for (auto n: (**right).get_descendents()) {
                v.push_back(n);
            }
        }
        return v;
    }

    int get_size() {
        auto l = get_child_size(left);
        auto r = get_child_size(right);
        return 1 + l + r;
    }

    string print(string offset) {
        stringstream sout;
        sout << offset << building->print() << " (" << get_child_size(left) << "," << get_child_size(right) << ")" << endl;
        if (left) sout << (*left)->print(offset + "[L]->");
        if (right) sout << (*right)->print(offset + "[R]->");
        return sout.str();
    }

};

#endif
