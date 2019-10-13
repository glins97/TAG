#include "io.hpp"
#include "graphs/headers.hpp"

using namespace std;

int main(){
    auto g = MatrixGraph();
    g.load("resources/courses");
    return 0;
}