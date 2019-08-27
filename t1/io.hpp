#pragma once

#include <iostream>
#include <vector>
#include "graph.hpp"
using namespace std;

void requestMenuAction(vector<string> headers, vector<void (*)()> actions);
int handleChoice(int minValue, int maxValue);
void buildGraphOptionsMenu(Graph g);

