#include "io.hpp"

vector<list<int>> loadGraph(string filename){
    vector<list<int>> graph;

    ifstream file(filename);
    int n1, n2, edges;
    file >> n1 >> n2 >> edges;
    
    for (int i = 0; i < n1; i++){
        graph.push_back(list<int>());
    }

    int v1, v2;
    for (int i = 0; i < edges; i++){
        file >> v1 >> v2;
        graph[v2-1].push_back(v1-1);
        graph[v1-1].push_back(v2-1);
    }

    return graph;
}

void printList(list<int> l){
    for (int i: l){
        cout << i + 1 << " -> ";
    }
    cout << endl;
}

void printGraph(vector<list<int>> graph){
    int count = 0;
    for (list<int>l : graph){
        count++;
        cout << "[" << count << "] -> ";
        printList(l); 
    }
}