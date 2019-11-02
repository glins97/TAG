#include "school.hpp"

School::School(){
    this->chosenTeacherP1 = "";
    this->chosenTeacherP2 = "";
    this->p1 = 0;
    this->p2 = 0;
}

School::School(string id){
    this->chosenTeacherP1 = "";
    this->chosenTeacherP2 = "";
    this->id = id;
    this->p1 = 0;
    this->p2 = 0;
}

string School::repr(){
    auto s = this->id;
    s += " " + to_string(this->p1);
    s += " " + to_string(this->p2);
    return s;
}

bool School::isFree(){
    return (this->chosenTeacherP1 == "" && this->p1 != 0) || (this->chosenTeacherP2 == "" && this->p2 != 0);
}

