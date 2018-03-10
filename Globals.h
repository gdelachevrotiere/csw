#ifndef CWS_GLOBALS_H
#define CWS_GLOBALS_H

#include <map>
#include <array>
#include <vector>
#include <iostream>
#include <memory>
#include <functional>
#include <algorithm>
#include <sstream>
#include <functional>
#include <optional>
#include <cassert>
using namespace std;

enum RessourceType { Gold, Wood, Stone, Clay, Glass, Paper };
typedef map<RessourceType,int> RessourceMap;
void test_all();

#endif
