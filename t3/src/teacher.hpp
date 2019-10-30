#pragma once
using namespace std;

#include <string>
#include <vector>
#include "school.hpp"

class Teacher{
public:
    string id;
    int hab;
    vector<string>* propostions;
    vector<string>* preferences;
    string chosenSchool = "";
    bool finishedProposing = false;

    string repr(); 
    Teacher();
    Teacher(string id, int hab);
    void addPreference(string p);
    bool isFree();
    void propose(School* school, bool successfuly, int preference);
};