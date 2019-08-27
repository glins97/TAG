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
    static void showVerticeDegrees();
    static void showMaximumCliques();
    static void showVerticeAgglomerationCoefficients();
    static void showAverageAgglomerationCoefficient();

private:
    bool isLoaded;
};

