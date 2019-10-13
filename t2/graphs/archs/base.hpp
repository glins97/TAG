#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../items/base.hpp"

using namespace std;

class Graph{
    public:
        vector<vector<GraphItemBase*>> data;
        virtual void load(string filename) {};
        void print();

        int v;
        int e;
};



