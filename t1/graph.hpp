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
    vector<list<int>> adjacencyList;
    vector<double> agglomerationCoefficients;
    double averageAgglomerationCoefficient;

    Graph(string filename);
    void load();
    void print();
    void showVerticeDegrees();
    void showMaximumCliques();
    void showVerticesAgglomerationCoefficients();
    void calculateVerticesAgglomerationCoefficients();
    void showAverageAgglomerationCoefficient();
    void calculateAverageAgglomerationCoefficient();

private:
    bool isLoaded;
};

