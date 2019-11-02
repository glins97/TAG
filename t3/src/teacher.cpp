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
    s = s + " || " + this->chosenSchool + "(";


    for (auto prop: *(this->propostions)){
        s = s + " " + prop;
    }

    s = s + ") ";
    return s;
}
