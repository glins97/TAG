#include "io.hpp"
#include "graph.hpp"

using namespace std;

int main(){
    auto g = Graph(MODE_AJACENCY_MATRIX);
    g.load("resources/courses", "resources/requisites");
    cout << "Curso: Ciência da Computação" << endl;

    save_graph("DAG", g);
    cout << "DAG Gerado: DAG.svg ou DAG.txt" << endl;

    auto topological_order = g.get_topological_order();
    cout << "Ordenação topológica: TOP.svg ou TOP.txt" << endl;
    save_topological_order("TOP", topological_order, g);

    vector<vector<int>> paths;
    vector<int> values;
    g.get_critical_paths(&paths, &values);
    save_path("Path1", paths[0], g);
    save_path("Path2", paths[1], g);
    
    cout << "Caminhos críticos distintos: " << endl;
    cout << "  1. Path1.svg ou Path1.txt" << endl;
    cout << "  2. Path2.svg ou Path2.txt" << endl;
    cout << endl;

    return 0;
}