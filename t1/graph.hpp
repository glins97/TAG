#pragma once

#include <string>
#include <vector>
#include <list>

#include <iostream>
#include <fstream>

using namespace std;

class Graph{
public:
    string filename;
    int v;
    int e;
    vector<list<int>>* adjacencyList;

    Graph(string filename);
    void load();
    void print();
    void showVerticeDegrees();
    void showMaximumCliques();
    void showVerticeAgglomerationCoefficients();
    void showAverageAgglomerationCoefficient();

private:
    bool isLoaded;
};

