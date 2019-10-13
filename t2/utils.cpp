#include "utils.hpp"

template <class T>
bool in(vector<T> l, T item){
    for (T i: l) if (item == i) return true;
    return false; 
}

