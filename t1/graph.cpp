#include "graph.hpp"

Graph::Graph(string filename){
    this->isLoaded = false;
    this->v = 0;
    this->e = 0;
    this->filename = filename;
    this->load();
}

void Graph::load(){
    if (this->isLoaded){
        cout << "Graph '" << this-> filename << "' already loaded.\n";
        return;
    }
    
    ifstream file(this->filename);
    file >> this->v 
        >> this->v
        >> this->e;

    this->isLoaded = true;
    this->adjacencyList = vector<list<int>>();
    for (int i = 0; i < this->v; i++){
        (this->adjacencyList).push_back(list<int>());
    }

    int v1, v2;
    for (int i = 0; i < this->e; i++){
        file >> v1 >> v2;
        (this->adjacencyList).at(v2-1).push_back(v1-1);
        (this->adjacencyList).at(v1-1).push_back(v2-1);
    }
}

void Graph::print(){
    for (int i; i < this->adjacencyList.size(); i++){
        cout << "[" << i + 1 << "] -> ";
        for (int j: this->adjacencyList.at(i)){
            cout << j + 1 << " -> ";
        }         
        cout << endl;
    }
}

void Graph::showVerticeDegrees(){
    cout << "@showVerticeDegrees" << endl;
    
    int vectorCount = 0;
    for (list<int> verticeAdjancencyList: this->adjacencyList){
        vectorCount ++;
        cout << "[" << vectorCount << "] -> " << verticeAdjancencyList.size() << endl;
    }
}

void Graph::showMaximumCliques(){
    cout << "@showMaximumCliques" << endl;
}

void Graph::showVerticeAgglomerationCoefficients(){
    cout << "@showVerticeAgglomerationCoefficients" << endl;
}

void Graph::showAverageAgglomerationCoefficient(){
    cout << "@showAverageAgglomerationCoefficient" << endl;
}