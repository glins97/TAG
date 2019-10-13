#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "utils.hpp"
#include "course.hpp"

#define MODE_AJACENCY_MATRIX 0
#define MODE_AJACENCY_LIST 1

using namespace std;

class Graph{
    public:
        vector<Course> courses;
        vector<vector<int>> data;

        Graph(int mode);
        void load(string courses, string requisites);
        void print();

    private:
        void _load_ajacency_matrix(string filename);
        void _load_ajacency_list(string filename);
        void _load_courses(string filename);
        int mode;
        int v;
        int e;
};

