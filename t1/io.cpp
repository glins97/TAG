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

int requestMenuChoice(vector<string> headers){
    cout << "Escolha uma opçao abaixo:\n";
    int count = 1;
    int quit = headers.size() + 1;
    for (string header: headers){
        cout << "\t" << count << ". " << header << ";" << endl;
        count++;
    }
    cout << "\t" << count << ". Sair." << endl;
    cout << endl;
    cout << "Opçao: ";

    int choice = handleChoice(1, quit);
    if (choice == quit) return 0;
    return choice;
}

int requestGraphMenuChoice(){
    vector<string> headers = {
        "Listar todos os vertices e seus graus",
        "Listar todos os cliques maximais",
        "Listar o coeficiente de aglomeracao de todos os vertices",
        "Imprimir o coeficiente aglomeracao medio do grafo",
    };

    return requestMenuChoice(headers);
}