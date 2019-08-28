#include "io.hpp"
#include "graph.hpp"

using namespace std;
int main(){
    Graph g = Graph("soc-dolphins.mtx");
  
    int choice = requestGraphMenuChoice();
    while (choice){
        switch (choice) {
            case 1: g.showVerticeDegrees(); break;
            case 2: g.showMaximumCliques(); break;
            case 3: g.showVerticeAgglomerationCoefficients(); break;
            case 4: g.showAverageAgglomerationCoefficient(); break;
            default: break;
        }
    
        choice = requestGraphMenuChoice();
    }
    return 0;
}