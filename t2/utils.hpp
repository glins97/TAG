#pragma once

#include <vector>

using namespace std;

template <class T>
bool in(vector<T> l, T item);

template <class T>
bool in(vector<T> l, T item){
    for (T i: l) if (item == i) return true;
    return false; 
}