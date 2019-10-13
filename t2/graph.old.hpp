#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "utils.hpp"
#define MODE_AJACENCY_MATRIX 0;
#define MODE_AJACENCY_LIST 1;

using namespace std;

template <class T>
class Graph{
    public:
        vector<vector<T>> data;

        Graph();
        void load();
        void print();

    private:
        int v;
        int e;
};

