#include "school.hpp"

School::School(){
    this->chosenTeacherP1 = "";
    this->chosenTeacherP2 = "";
}

School::School(string id){
    this->chosenTeacherP1 = "";
    this->chosenTeacherP2 = "";
    this->id = id;
}

string School::repr(){
    auto s = this->id;
    s += " " + to_string(this->p1);
    s += " " + to_string(this->p2) + " ||";
    s += " " + this->chosenTeacherP1;
    s += " " + this->chosenTeacherP2;
    return s;
}

bool School::isFree(){
    return (this->chosenTeacherP1 == "" && this->p1 != 0) || (this->chosenTeacherP2 == "" && this->p2 != 0);
}