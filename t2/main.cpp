#include "io.hpp"
#include "graph.hpp"

using namespace std;

int main(){
    auto g = Graph(MODE_AJACENCY_MATRIX);
    g.load("resources/courses", "resources/requisites");
    cout << "Curso: Ciência da Computação" << endl << endl;

    save_graph("DAG", g);
    cout << "DAG Gerado: DAG.svg ou DAG.txt" << endl << endl;

    auto topological_order = g.get_topological_order();
    cout << "Ordenação topológica: (TOP.svg, se preferir)" << endl;
    for (int item: topological_order){
        cout << g.courses[item].name << " (" << g.courses[item].code << ") -> ";
    }   
    cout << endl << endl;
    save_topological_order("resources/TOP", topological_order, g);

    vector<vector<int>> paths;
    vector<int> values;
    g.get_critical_paths(&paths, &values);
    save_path("resources/path1", paths[0], g);
    save_path("resources/path2", paths[1], g);cout << "Caminhos críticos distintos: ";
    cout << "\n\t1. ";
    for (int item: paths[0]){
        cout << g.courses[item].name << " (" << g.courses[item].code << ") -> ";
    }      
    cout << values[0] << " créditos somados." << endl;  
    cout << "\n\t2. ";
    for (int item: paths[1]){
        cout << g.courses[item].name << " (" << g.courses[item].code << ") -> ";
    }        
    cout << values[1] << " créditos somados." << endl;  
    

    return 0;
}