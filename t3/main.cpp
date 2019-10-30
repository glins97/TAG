#include "src/io.hpp"

using namespace std;

vector<Teacher> freeTeachersThatHaventProposed(vector<Teacher> teachers, int* count){
    (*count) = 0;
    auto candidates = vector<Teacher>(); 
    for (auto teacher: teachers){
        if (teacher.finishedProposing == false and teacher.isFree()){
            (*count)++;
            candidates.push_back(teacher);
        }
    }
    return candidates;
}

template <class T>
T getObjById(vector<T> v, string id){
    for (auto obj: v)
        if (obj.id == id) return obj;
    cout << "FAILED TO FIND A MATCH: " << id << endl;
    getchar();
    return v.front();
}

template <class T>
bool in(vector<T> v, T obj){
    for (auto o: v)
        if (o == obj) return true;
    return false;
}

int getUnproposedSchool(Teacher teacher, vector<School> schools, School* school){
    int count = 0;
    for (auto s: schools){
        bool proposed = false;
        for (auto s_id: *(teacher.propostions)){
            if (s.id == s_id){
                proposed = true;
            }
        }

        if (proposed == false){
            *school = s;
            count++;
            break;
        }
    }
    return count;
}

template <class T>
void update(vector<T>* v, T obj){
    bool updated = false;
    for (int i = 0; i < (*v).size(); i++){
        if ((*v)[i].id == obj.id){
            (*v)[i] = obj;
            updated = true;
        }
    }
}

void checkForCorrectness(vector<School> schools, vector<Teacher> teachers){
    // check if there is any teacher available that chould be matched with another school
    for (auto school: schools){
        Teacher chosenTeacherP1;
        if (school.chosenTeacherP1 != "") chosenTeacherP1 = getObjById(teachers, school.chosenTeacherP1);
        Teacher chosenTeacherP2;
        if (school.chosenTeacherP2 != "") chosenTeacherP2 = getObjById(teachers, school.chosenTeacherP2);
        
        for (auto teacher: teachers){
            bool failed = false;
            if (teacher.chosenSchool == "" && in(*(teacher.preferences), school.id)){
                if( teacher.hab >= school.p1 &&      
                    school.chosenTeacherP1 != "" &&          
                    teacher.hab > chosenTeacherP1.hab &&          
                    school.p1 != 0){
                    failed = true;
                } 
                if( teacher.hab >= school.p2 &&      
                    school.chosenTeacherP2 != "" &&          
                    teacher.hab > chosenTeacherP2.hab &&          
                    school.p2 != 0){
                    failed = true;
                } 
            }
            if (failed){
                cout << "[ALGORITHM FAILED] We have a teacher match:\n" << teacher.repr() << endl;
                cout << "\t" << school.repr() << endl;
                cout << "\t" << "School P1: " << chosenTeacherP1.repr() << endl;
                cout << "\t" << "School P2: " << chosenTeacherP2.repr() << endl;
            }
        }
    }
}

void printSchools(vector<School> schools, vector<Teacher> teachers){
    for (auto school: schools){

        cout << school.repr() << endl;
        if (school.chosenTeacherP1 != ""){
            auto chosenTeacherP1 = getObjById(teachers, school.chosenTeacherP1);
            cout << "\t" << "School P1: " << school.chosenTeacherP1 << endl;
        }
        
        if (school.chosenTeacherP2 != ""){
            auto chosenTeacherP2 = getObjById(teachers, school.chosenTeacherP2);
            cout << "\t" << "School P2: " << school.chosenTeacherP2 << endl;
        }
    }
}

int printTeachers(vector<Teacher> teachers){
    int allocatedTeachers = 0;
    for (auto teacher: teachers){
        cout << teacher.id << " -> '" << teacher.chosenSchool << "'" << endl;
        if (teacher.chosenSchool != "")
            allocatedTeachers++;
    }
    return allocatedTeachers;
}

int main(){
    auto schools = loadSchools("resources/output_schools");
    auto teachers = loadTeachers("resources/output_teachers");

    int count = 0;
    auto freeTeachers = freeTeachersThatHaventProposed(teachers, &count);
    while (count){
        Teacher teacher = freeTeachers.back();
        freeTeachers.pop_back();
        School school;
        if (getUnproposedSchool(teacher, schools, &school)){
            if (
                in(*(teacher.preferences), school.id) &&
                school.chosenTeacherP1 == "" &&
                school.p1 <= teacher.hab &&
                school.p1 != 0){
                teacher.propose(&school, true, 1);
            }
            else if (
                in(*(teacher.preferences), school.id) &&
                school.chosenTeacherP2 == "" &&
                school.p2 <= teacher.hab &&
                school.p2 != 0){
                teacher.propose(&school, true, 2);
            }

            else if ( // if school current chosen teacher does not have chosen hability, but proposing teacher does
                in(*(teacher.preferences), school.id) &&
                school.chosenTeacherP1 != "" &&
                getObjById(teachers, school.chosenTeacherP1).hab < teacher.hab  &&
                school.p1 <= teacher.hab &&
                school.p1 != 0
            ){
                auto t = getObjById(teachers, school.chosenTeacherP1);
                auto s = getObjById(schools, t.chosenSchool);
                t.chosenSchool = "";
                s.chosenTeacherP1 = "";
                update(&teachers, t);
                update(&schools, s);
                teacher.propose(&school, true, 1);
            }
            else if ( // if school current chosen teacher does not have chosen hability, but proposing teacher does
                in(*(teacher.preferences), school.id) &&
                school.chosenTeacherP2 != "" &&
                getObjById(teachers, school.chosenTeacherP2).hab < teacher.hab  &&
                school.p2 <= teacher.hab &&
                school.p2 != 0
            ){
                auto t = getObjById(teachers, school.chosenTeacherP2);
                auto s = getObjById(schools, t.chosenSchool);
                t.chosenSchool = "";
                s.chosenTeacherP2 = "";
                update(&teachers, t);
                update(&schools, s);
                teacher.propose(&school, true, 2);
            }

            else {
                teacher.propose(&school, false, -1);
            }

            update(&teachers, teacher);
            update(&schools, school);
        }
        freeTeachers = freeTeachersThatHaventProposed(teachers, &count);
    }

    int allocatedTeachers =  printTeachers(teachers);
    cout << "Professores empregados: " << allocatedTeachers << endl;
    printSchools(schools, teachers);
    checkForCorrectness(schools, teachers);
    return 0;
}