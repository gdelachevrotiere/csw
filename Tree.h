#ifndef TREE_H
#define TREE_H

class Tree {
private:

    shared_ptr<Building> building;
    optional<shared_ptr<Tree>> left;
    optional<shared_ptr<Tree>> right;

    optional<shared_ptr<Tree>> allocate(const shared_ptr<Building>& building) {
        auto t = make_shared<Tree>(*new Tree(building));
        return optional<shared_ptr<Tree>>(t);
    };

    int get_child_size(optional<shared_ptr<Tree>> c) {
        return c ? (*c)->get_size() : 0;
    }

public:

    Tree(const shared_ptr<Building>& building) {
        this->building = building;
        left = nullopt;
        right = nullopt;
    }

    Tree(vector<shared_ptr<Building>>& buildings) {
        building = util::pop(buildings);
        left = nullopt;
        right = nullopt;
        while(!buildings.empty()) {
            auto b = util::pop(buildings);
            push(b);
        }
    }

    void create_left(const shared_ptr<Building>& building) {
        left = allocate(building);
    }

    void create_right(const shared_ptr<Building>& building) {
        right = allocate(building);
    }

    optional<shared_ptr<Tree>> get_left() {
        return left;
    }

    optional<shared_ptr<Tree>> get_right() {
        return right;
    }

    bool is_childless() {
        if (!get_left() && !get_right()) {
            return true;
        } else {
            return false;
        }
    }
    ~Tree() {}

    int get_size() {
        auto l = get_child_size(left);
        auto r = get_child_size(right);
        return 1 + l + r;
    }

    void push(const shared_ptr<Building>& building) {
        if ( get_child_size(left) <= get_child_size(right) ) {
            if (left) {
                (*left)->push(building);
            } else {
                create_left(building);
            }
        } else {
            if (right) {
                (*right)->push(building);
            } else {
                create_right(building);
            }
        }
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
