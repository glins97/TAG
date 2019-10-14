#include "io.hpp"

void clearConsole(){
    printf("\033c");
}

void save_topological_order(string filename, vector<int> order, Graph graph){
    ofstream out("resources/"+filename);
    string result = "digraph finite_state_machine {\n\tsize=\"18,10\"\n\tnode [shape = circle];"; //headers    
    
    int v = graph.data.size();
    for (int i = 0; i < v - 1; i++){
        result += "\n\t" + graph.courses[order[i]].name + "_" + to_string(graph.courses[order[i]].code) + " -> " + graph.courses[order[i+1]].name + "_" + to_string(graph.courses[order[i + 1]].code) + " [ label = " + to_string(graph.courses[order[i]].credits) + " ]; ";
    }

    result += "\n\t\tordering=out;\n}";
    out << result;
    out.close();

    ofstream out2(filename+".txt");
    result = "";

    int value = 0;
    for (int item: order){
        result += graph.courses[item].name + " (" + to_string(graph.courses[item].code) + ") -> \n";
    }        
    out2 << result;
}

void save_path(string filename, vector<int> path, Graph graph){
    ofstream out("resources/"+filename);

    string result = "digraph finite_state_machine {\n\tsize=\"18,10\"\n\tnode [shape = circle];"; //headers    
    int v = graph.data.size();
    for (int i = 0; i < v; i++){
        bool found = false;
        for (int j = 0; j < v; j++){
            if(graph.data[i][j] > 0){
                string ending = " ]; ";
                if (in(path, i) && in(path, j))
                    ending = ", color=\"0.002 0.999 0.999\" ]; ";

                result += "\n\t" + to_string(graph.courses[i].code) + " -> " + to_string(graph.courses[j].code) + " [ label = " + to_string(graph.courses[i].credits) + ending;
                found = true;
            }
        }
        if (!found){
            result += "\n\t" + to_string(graph.courses[i].code) + "; ";
        }
    }

    result += "\n\t\tordering=out;\n}";
    out << result;
    out.close();

    ofstream out2(filename+".txt");
    result = "";

    int value = 0;
    for (int item: path){
        value += graph.courses[item].credits; 
        result += graph.courses[item].name + " (" + to_string(graph.courses[item].code) + ") -> \n";
    }        
    result += to_string(value) + " créditos somados.";  
    out2 << result;
}

void save_graph(string filename, Graph graph){
    _save_graph_svg(filename, graph);
    _save_graph_txt(filename + ".txt", graph);
}

void _save_graph_svg(string filename, Graph graph){
    ofstream out("resources/"+filename);

    string result = "digraph finite_state_machine {\n\tsize=\"18,10\"\n\tnode [shape = circle];"; //headers
    int v = graph.data.size();
    for (int i = 0; i < v; i++){
        bool found = false;
        for (int j = 0; j < v; j++){
            if(graph.data[i][j] > 0){
                result += "\n\t" + to_string(graph.courses[i].code) + " -> " + to_string(graph.courses[j].code) + " [ label = " + to_string(graph.courses[i].credits) + " ]; ";
                found = true;
            }
        }
        if (!found){
            result += "\n\t" + to_string(graph.courses[i].code) + "; ";
        }
    }
    result += "\n\t\tordering=out;\n}";
    out << result;
    out.close();
}

void _save_graph_txt(string filename, Graph graph){
    ofstream out(filename);

    string result = "Matérias nas linhas desbloqueiam as matérias das colunas.\n\t\t";
    int v = graph.data.size();
    for (int i = 0; i < v; i++){
        result += to_string(graph.courses[i].code) + "\t";
    }
    result += "\n";
    for (int i = 0; i < v; i++){
        result += to_string(graph.courses[i].code) + "\t";
        for (int j = 0; j < v; j++){
            string creditos = "";
            if (graph.data[i][j] > 0) creditos = to_string(graph.data[i][j]);
            result += creditos + "\t\t";
        }
        result += "\n";
    }
    
    out << result;
    out.close();
}