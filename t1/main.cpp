#include "io.hpp"
#include "graph.hpp"

using namespace std;
#define ACTION_QUIT 0

int requestGraphMenuChoice(){
    vector<string> headers = {
        "Listar todos os vertices e seus graus",
        "Listar todos os cliques maximais",
        "Listar o coeficiente de aglomeracao de todos os vertices",
        "Imprimir o coeficiente aglomeracao medio do grafo",
    };

    return requestMenuChoice(headers);
}

int requestGraphMenuAction(Graph g){
    int choice = requestGraphMenuChoice();
    switch (choice) {
        case 1: g.showVerticeDegrees(); break;
        case 2: g.showMaximumCliques(); break;
        case 3: g.showVerticesAgglomerationCoefficients(); break;
        case 4: g.showAverageAgglomerationCoefficient(); break;
        default: break;
    }
    return choice;    
}

int main(){
    clearConsole();
    while (requestGraphMenuAction(Graph("soc-dolphins.mtx")) != ACTION_QUIT);
    return 0;
}