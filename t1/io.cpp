#include "io.hpp"

int handleChoice(int minValue, int maxValue){
    int choice = minValue - 1;
    cin >> choice;
    while (choice < minValue || choice > maxValue) {
        cout << "Escolha invalida. Tente novamente: ";
        cin >> choice;
    }
    return choice;
}

void buildGraphOptionsMenu(Graph g){
    vector<string> headers = {
        "Listar todos os vertices e seus graus",
        "Listar todos os cliques maximais",
        "Listar o coeficiente de aglomeracao de todos os vertices",
        "Imprimir o coeficiente aglomeracao medio do grafo",
    };

    vector<void (*)()> actions = {
        g.showVerticeDegrees,
        g.showMaximumCliques,
        g.showVerticeAgglomerationCoefficients,
        g.showAverageAgglomerationCoefficient,
    };

    requestMenuAction(headers, actions);
}

void requestMenuAction(vector<string> headers, vector<void (*)()> actions){
    cout << "Escolha uma opçao abaixo:\n";
    int count = 1;
    for (string header: headers){
        cout << "\t" << count << ". " << header << ";" << endl;
        count++;
    }
    cout << "\t" << count << ". Sair." << endl;
    cout << endl;
    cout << "Opçao: ";

    int choice = handleChoice(1, headers.size() + 1);
    if (choice != headers.size() + 1){
        actions[choice - 1]();
        requestMenuAction(headers, actions);
    }
    
}