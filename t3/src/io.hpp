#pragma once
using namespace std;

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "school.hpp"
#include "teacher.hpp"

vector<School> loadSchools(string filename);
vector<Teacher> loadTeachers(string filename);

template <class T>
void printVector(vector<T> v){
    for (auto obj: v)
        cout << obj.repr() << endl;
}
