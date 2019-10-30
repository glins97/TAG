#pragma once
using namespace std;

#include <string>
#include <vector>
#include <iostream>

class School{
public:
    string id;
    string chosenTeacherP1 = "";
    string chosenTeacherP2 = "";
    int p1;
    int p2;
    string repr(); 
    School();
    School(string id);
    bool isFree();
};