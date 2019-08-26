#pragma once

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

vector<list<int>> loadGraph(string filename);
void printList(list<int> l);
void printGraph(vector<list<int>> graph);