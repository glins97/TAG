#include "graph.hpp"
#include "utils.hpp"

Graph::Graph(int mode){
    this->mode = mode;
    this->is_loaded = false;
    this->v = 0;
    this->e = 0;
}

void Graph::load(string filename){
    if (this->is_loaded){
        cout << "Graph '" << filename << "' already loaded.\n";
        return;
    }

    switch (this->mode){
    case MODE_AJACENCY_MATRIX:
        this->_load_ajacency_matrix(filename);
        break;
    case MODE_AJACENCY_LIST:
        this->_load_ajacency_list(filename);
        break;
    default:
        break;
    }
    
    this->is_loaded = true;
}

void Graph::_load_ajacency_matrix(string filename){
    cout << "_load_ajacency_matrix " << filename << endl;
    ifstream file(filename);
    this->data = vector<vector<int>>();
}

void Graph::_load_ajacency_list(string filename){

}

void Graph::print(){
}
