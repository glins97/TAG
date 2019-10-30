#include "teacher.hpp"
Teacher::Teacher(){
    this->chosenSchool = "";
    this->finishedProposing = false;
    this->preferences = new vector<string>();
    this->propostions = new vector<string>();
}

Teacher::Teacher(string id, int hab){
    this->chosenSchool = "";
    this->finishedProposing = false;
    this->id = id;
    this->hab = hab;
    this->preferences = new vector<string>();
    this->propostions = new vector<string>();
}

void Teacher::addPreference(string p){
    if (p != "None")
        this->preferences->push_back(p);
}

string Teacher::repr(){
    auto s = this->id + ", " + to_string(this->hab);
    for (auto p: *(this->preferences)){
        s = s + " " + p;
    }
    s = s + " || " + this->chosenSchool;
    return s;
}

bool Teacher::isFree(){
    return this->chosenSchool == "";
}

void Teacher::propose(School* school, bool successfuly, int preference){
    this->propostions->push_back(school->id);

    if (successfuly){
        if (preference == 1){
            school->chosenTeacherP1 = this->id;
        }
        else if (preference == 2){
            school->chosenTeacherP2 = this->id;
        }
        this->chosenSchool = school->id;
    }
   
    if (this->propostions->size() == 50) 
        this->finishedProposing = true;   
}