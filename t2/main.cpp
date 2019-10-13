#include "io.hpp"
#include "graph.hpp"

using namespace std;

int main(){
    auto g = Graph(MODE_AJACENCY_MATRIX);
    g.load("resources/courses", "resources/requisites");
    g.print();
    return 0;
}