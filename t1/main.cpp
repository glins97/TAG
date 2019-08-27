#include "io.hpp"
#include "graph.hpp"

using namespace std;
int main(){
    Graph g = Graph("soc-dolphins.mtx");
    buildGraphOptionsMenu(g);
    return 0;
}