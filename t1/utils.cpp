#include "utils.hpp"

bool in(list<int> l, int item){
    for (int i: l) if (item == i) return true;
    return false; 
}

list<int> uniteLists(list<int> a, list<int> b){
    list<int> result = a; 
    for (int bX: b){
        bool in = false;
        for (int aX: a){
            if (aX == bX){
                in = true;
            }
        }
        if (!in) result.push_back(bX);
    }
    return result;
}

list<int> intersectLists(list<int> a, list<int> b){
    list<int> result = list<int>(); 
    for (int bX: b){
        bool in = false;
        for (int aX: a){
            if (aX == bX){
                in = true;
            }
        }
        if (in) result.push_back(bX);
    }
    return result;
}

list<int> relativeComplement(list<int> a, list<int> b){
    list<int> result = list<int>(); 
    for (int aX: a){
        bool in = false;
        for (int bX: b){
            if (aX == bX){
                in = true;
            }
        }
        if (!in) result.push_back(aX);
    }
    return result;
}
