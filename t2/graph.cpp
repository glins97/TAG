#include "graph.hpp"
#include "utils.hpp"
#include <algorithm>  

Graph::Graph(int mode){
    this->mode = mode;
    this->v = 0;
    this->e = 0;
}

void Graph::get_critical_paths(vector<vector<int>>* paths, vector<int>* values){
    vector<int> candidates = vector<int>();
    
    for (int i = 0; i < this-> v; i++){
        bool has_requisite = false;

        for (int j = 0; j < this-> v; j++){
            if ((this->data)[j][i] > 0){
                has_requisite = true;
                break;
            }
        }

        if (!has_requisite) 
            candidates.push_back(i);
    }

    auto _values = vector<int>();
    auto _paths = vector<vector<int>>();
    for (int candidate: candidates){
        int value = 0;
        vector<int> path = vector<int>();
        this->_get_critical_path(candidate, &path, &value);

        bool pushed = false;
        for (int i = 0; i < _values.size(); i++){
            if (value >= _values[i]){
                pushed = true;
                _values.insert(_values.begin() + i, value);
                _paths.insert(_paths.begin() + i, path);
                break;
            }
        }
        if (!pushed){
            _values.push_back(value);
            _paths.push_back(path);
        }
    }

    *paths = _paths;
    *values = _values;
}

void Graph::_get_critical_path(int vertice, vector<int>* path, int* value){
    int _value = this->courses[vertice].credits;
    auto _path = vector<int>({vertice});

    auto candidates = vector<int>();
    for (int i = 0; i < this-> v; i++){
        if (this->data[vertice][i] > 0)
            candidates.push_back(i);
    } 

    auto max_path = vector<int>();
    auto max_value = 0; 
    for (int candidate: candidates){
        auto c_value = this->courses[vertice].credits;
        auto c_path = vector<int>({vertice});
        this->_get_critical_path(candidate, &c_path, &c_value);   

        if (c_value > max_value){
            max_path = c_path;
            max_value = c_value;
        };
    }

    for (int v: max_path)
        _path.push_back(v);
    _value += max_value;

    *path = vector<int>(_path); 
    *value = int(_value);
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
