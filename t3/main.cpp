#include "src/io.hpp"

using namespace std;

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

void printSchools(vector<School> schools, vector<Teacher> teachers){
    for (auto school: schools){

        cout << endl << school.repr() << endl;
        if (school.chosenTeacherP1 != ""){
            auto chosenTeacherP1 = getObjById(teachers, school.chosenTeacherP1);
            cout << "  " << "P1: " << school.chosenTeacherP1 << endl;
        }

        if (school.chosenTeacherP2 != ""){
            auto chosenTeacherP2 = getObjById(teachers, school.chosenTeacherP2);
            cout << "  " << "P2: " << school.chosenTeacherP2 << endl;
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

template <class T>
void update(vector<T>* v, T obj){
    for (int i = 0; i < (*v).size(); i++){
        if ((*v)[i].id == obj.id){
            (*v)[i] = obj;
            return;
        }
    }
}

int getUnproposedSchool(Teacher teacher, vector<School> schools, School* school){
    int count = 0;
    for (auto s: *(teacher.preferences)){
        bool proposed = in(*(teacher.propostions), s);

        if (!proposed){
            *school = getObjById(schools, s);
            count++;
            break;
        }
    }
    return count;
}

vector<Teacher> freeTeachersThatHaventProposed(vector<Teacher> teachers, int* count){
    (*count) = 0;
    auto candidates = vector<Teacher>();
    for (auto teacher: teachers){
        if (!teacher.finishedProposing and teacher.chosenSchool == ""){
            (*count)++;
            candidates.push_back(teacher);
        }
    }
    return candidates;
}


void propose(Teacher* teacher, School* school, bool successfuly, int preference){
    teacher->propostions->push_back(school->id);
    if (teacher->propostions->size() == teacher->preferences->size())
        teacher->finishedProposing = true;

    if (successfuly){
        if (preference == 1){
            school->chosenTeacherP1 = teacher->id;
        }
        else if (preference == 2){
            school->chosenTeacherP2 = teacher->id;
        }
        teacher->chosenSchool = school->id;
    }

}

int main(){
    auto schools = loadSchools("resources/output_schools");
    auto teachers = loadTeachers("resources/output_teachers");

    int count = 0;
    int i = 1;
    auto freeTeachers = freeTeachersThatHaventProposed(teachers, &count);
    while (count){
        School school = School();
        Teacher teacher = freeTeachers.back();
        freeTeachers.pop_back();

        int hasUnproposedSchool = getUnproposedSchool(teacher, schools, &school);
        if (hasUnproposedSchool){
            // School is not matched, and current teacher is a match
            if (school.chosenTeacherP1 == "" &&
                teacher.hab >= school.p1){
                propose(&teacher, &school, true, 1);
            }
            else if (school.chosenTeacherP2 == "" &&
                    school.p2 > 0 &&
                    teacher.hab >= school.p2){
                propose(&teacher, &school, true, 2);
            }

            // School is matched, but current teacher is a better match
            else if(school.chosenTeacherP1 != "" &&
                    teacher.hab > getObjById(teachers, school.chosenTeacherP1).hab) {
                auto lastTeacher = getObjById(teachers, school.chosenTeacherP1);
                lastTeacher.chosenSchool = "";
                update(&teachers, lastTeacher);
                propose(&teacher, &school, true, 1);
            }
            else if(school.chosenTeacherP2 != "" &&
                    school.p2 > 0 &&
                    teacher.hab > getObjById(teachers, school.chosenTeacherP2).hab) {
                auto lastTeacher = getObjById(teachers, school.chosenTeacherP2);
                lastTeacher.chosenSchool = "";
                update(&teachers, lastTeacher);
                propose(&teacher, &school, true, 2);
            }

            // School is matched, and current teacher is not a better match
            else{
                propose(&teacher, &school, false, -1);
            }
            update(&teachers, teacher);
            update(&schools, school);
        }
        freeTeachers = freeTeachersThatHaventProposed(teachers, &count);
    }

    int allocatedTeachers =  printTeachers(teachers);
    cout << "Professores empregados: " << allocatedTeachers << endl;
    printSchools(schools, teachers);
    return 0;
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