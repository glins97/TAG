#include "graph.hpp"

Graph::Graph(string filename){
    this->isLoaded = false;
    this->v = 0;
    this->e = 0;
    this->filename = filename;
    this->load();
    this->calculateVerticesAgglomerationCoefficients();
    this->calculateAverageAgglomerationCoefficient();
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

void Graph::calculateVerticesAgglomerationCoefficients(){
    this->agglomerationCoefficients = vector<double>();

    for (list<int> verticeAdjancencyList: this->adjacencyList){
        int size = verticeAdjancencyList.size();
        int edgesAmmount = 0;
        int maxEdges = size * (size - 1);

        for (int adjacentVertice: verticeAdjancencyList){
            for (int adjacentAdjacentVertice: this->adjacencyList.at(adjacentVertice)){
                for (int initialAdjacentVertice: verticeAdjancencyList){
                    if (adjacentAdjacentVertice == initialAdjacentVertice){
                        edgesAmmount += 1;
                    }
                }
            }
        } 
        if (maxEdges){
            this->agglomerationCoefficients.push_back((double) edgesAmmount/maxEdges);
        }
        else{
            this->agglomerationCoefficients.push_back(0);
        }
    }
}

void Graph::calculateAverageAgglomerationCoefficient(){
    double total = 0;
    for (double value: this->agglomerationCoefficients){
        total += value;
    }
    this->averageAgglomerationCoefficient = total / this->v;
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

void Graph::showVerticesAgglomerationCoefficients(){
    cout << "@showVerticesAgglomerationCoefficients" << endl;
    
    int vectorCount = 0;
    for (list<int> verticeAdjancencyList: this->adjacencyList){
        vectorCount ++;
        cout << "[" << vectorCount << "] -> " << this-> agglomerationCoefficients[vectorCount-1] << endl;
    }
}

void Graph::showAverageAgglomerationCoefficient(){
    cout << "@showAverageAgglomerationCoefficient" << endl;
    cout << "Coeficiente de Aglomeraçao Medio: " << this -> averageAgglomerationCoefficient << endl;
}