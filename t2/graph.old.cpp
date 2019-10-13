#include "graph.hpp"
#include "utils.hpp"

template <class T>
Graph<T>::Graph(){
    this->isLoaded = false;
    this->v = 0;
    this->e = 0;
}

template <class T>
void Graph<T>::load(){
    if (this->isLoaded){
        cout << "Graph '" << this-> filename << "' already loaded.\n";
        return;
    }

    switch (this->mode){
    case MODE_AJACENCY_MATRIX:
        this->_load_ajacency_matrix();
        break;
    case MODE_AJACENCY_LIST:
        this->_load_ajacency_list();
        break;
    default:
        break;
    }
    
    this->isLoaded = true;
}

template <class T>
void Graph<T>::_load_ajacency_matrix(){
    ifstream file(this->filename);
    file >> this->v;
    this->adjacencyMatrix = vector<vector<T>>();

    int v1, v2;
    for (int i = 0; i < this->e; i++){
        file >> v1 >> v2;
        this->insert(v1, v2);
    }
}

template <class T>
void Graph<T>::_load_ajacency_list(){

}

void Graph::print(){
}
