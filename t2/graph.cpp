#include "graph.hpp"
#include "utils.hpp"

Graph::Graph(int mode){
    this->mode = mode;
    this->v = 0;
    this->e = 0;
}

void Graph::load(string courses, string requisites){
    this->_load_courses(courses);
    switch (this->mode){
    case MODE_AJACENCY_MATRIX:
        this->_load_ajacency_matrix(requisites);
        break;
    case MODE_AJACENCY_LIST:
        this->_load_ajacency_list(requisites);
        break;
    default:
        break;
    }
}

void Graph::_load_courses(string filename){
    cout << "_load_courses " << filename << endl;
    ifstream file(filename);
    this->courses = vector<Course>();

    int id, code, credits, n;
    string name;

    file >> n;
    for (int i = 0; i < n; i++){
        file >> id >> code >> name >> credits;
        (this->courses).push_back(
            Course(id, code, name, credits)
        );
    }

    file.close();
}

void Graph::_load_ajacency_matrix(string filename){
    cout << "_load_ajacency_matrix " << filename << endl;
    ifstream file(filename);
    this->data = vector<vector<int>>();
    
    file >> this->v >> this->e;
    for (int i = 0; i < this->v; i++){
        auto v = vector<int>();
        for (int j = 0; j < this->v; j++){
            v.push_back(0);
        }
        this->data.push_back(v);
    }

    int course, requisite;
    for (int i = 0; i < this->e; i++){
        file >> course >> requisite;
        (this->data)[requisite][course] = (this->courses)[requisite].credits;
    }
    file.close();
}

void Graph::_load_ajacency_list(string filename){
    cout << "_load_ajacency_list " << filename << endl;
    ifstream file(filename);
    this->data = vector<vector<int>>();

    file >> this->v >> this->e;
    for (int i = 0; i < this->v; i++){
        this->data.push_back(
            vector<int>()
        );
    }

    int course, requisite;
    for (int i = 0; i < this->e; i++){
        file >> course >> requisite;
        (this->data)[requisite].push_back(course);
    }
    file.close();
}

void Graph::print(){
    for (int i; i < this->v; i++){
        cout << "[" << i << "] -> ";
        for (int j: (this->data)[i]){
            cout << j << " -> ";
        }         
        cout << endl;
    }
}
