#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "utils.hpp"
#define MODE_AJACENCY_MATRIX 0
#define MODE_AJACENCY_LIST 1

using namespace std;

class Graph{
    public:
        vector<vector<int>> data;

        Graph(int mode);
        void load(string filename);
        void print();

    private:
        void _load_ajacency_matrix(string filename);
        void _load_ajacency_list(string filename);
        bool is_loaded;
        int mode;
        int v;
        int e;
};

