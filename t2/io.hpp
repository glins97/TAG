#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "graph.hpp"

using namespace std;

void save_path(string filename, vector<int> path, Graph graph);
void save_graph(string filename, Graph graph);
void save_topological_order(string filename, vector<int> order, Graph graph);
void _save_graph_svg(string filename, Graph graph);
void _save_graph_txt(string filename, Graph graph);
