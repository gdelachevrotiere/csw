#ifndef CWS_GLOBALS_H
#define CWS_GLOBALS_H

#include <map>
#include <array>
#include <vector>
#include <iostream>
#include <memory>
#include <functional>
using namespace std;

enum RessourceType { Gold, Wood, Stone, Clay, Glass, Paper };

typedef map<RessourceType,int> RessourceMap;

#endif
