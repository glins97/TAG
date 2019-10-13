#pragma once
using namespace std;

#include "base.hpp"
#include <string>

class Course: public GraphItemBase{
    public:
        int credits;
        string name;
};

