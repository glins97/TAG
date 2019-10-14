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
        vector<int> get_topological_order();
        void get_critical_paths(vector<vector<int>>* paths, vector<int>* values);
        void load(string courses, string requisites);
        void print();

    private:
        void _get_critical_path(int vertice, vector<int>* path, int* value);
        void _load_ajacency_matrix(string filename);
        void _load_ajacency_list(string filename);
        void _load_courses(string filename);
        int mode;
        int v;
        int e;
};

