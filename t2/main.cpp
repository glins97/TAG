#include "io.hpp"
#include "graph.hpp"

using namespace std;

int main(){
    auto g = Graph(MODE_AJACENCY_MATRIX);
    g.load("resources/courses", "resources/requisites");
    vector<vector<int>> paths;
    vector<int> values;
    g.get_critical_paths(&paths, &values);

    for (int i = 0; i < values.size(); i++){
        cout << "[" << values[i] << "] ";
        for (int item: paths[i]){
            cout << item << " ";
        }        
        cout << endl;
    }
    return 0;
}