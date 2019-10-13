#pragma once
using namespace std;

#include <string>

class Course{
    public:
        int id;
        int code;
        int credits;
        string name;
        Course(int id, int code, string name, int credits);
};