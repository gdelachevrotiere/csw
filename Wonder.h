#ifndef WONDER_H_
#define WONDER_H_

#include "Globals.h"
#include "Buildable.h"

class Wonder final: public Buildable {
	string name;
    vector<Impact> impacts;
	vector<RessourceType> sharedProduction;
public:
	Wonder(const string&, const Cost&, const vector<RessourceType>& sharedProduction, const vector<Impact>&);
	Wonder(const string& s, const Cost& c, const vector<RessourceType>& p): Wonder(s, c, p, vector<Impact>()) {};
	Wonder(const string& s, const Cost& c, const vector<Impact>& i): Wonder(s, c, vector<RessourceType>(), i) {};
	virtual ~Wonder() { };

    string get_name();
	vector<RessourceType> get_shared_production();
    Impact get_build_impact();
	string print();
};

#endif
