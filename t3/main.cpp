#include <map>
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
int in(vector<T> v, T obj){
    int i = 1;
    for (auto o: v)
        if (o == obj) return i;
        else i++;
    return 0;
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

void galeShapley(vector<Teacher>* teachers, vector<School>* schools){
    int count = 0;
    auto freeTeachers = freeTeachersThatHaventProposed(*teachers, &count);
    while (count){
        School school = School();
        Teacher teacher = freeTeachers.back();
        freeTeachers.pop_back();

        int hasUnproposedSchool = getUnproposedSchool(teacher, *schools, &school);
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
                    teacher.hab > getObjById(*teachers, school.chosenTeacherP1).hab) {
                auto lastTeacher = getObjById(*teachers, school.chosenTeacherP1);
                lastTeacher.chosenSchool = "";
                update(teachers, lastTeacher);
                propose(&teacher, &school, true, 1);
            }
            else if(school.chosenTeacherP2 != "" &&
                    teacher.hab > getObjById(*teachers, school.chosenTeacherP2).hab) {
                auto lastTeacher = getObjById(*teachers, school.chosenTeacherP2);
                lastTeacher.chosenSchool = "";
                update(teachers, lastTeacher);
                propose(&teacher, &school, true, 2);
            }

            // School is matched, and current teacher is not a better match
            else{
                propose(&teacher, &school, false, -1);
            }
            update(teachers, teacher);
            update(schools, school);
        }
        freeTeachers = freeTeachersThatHaventProposed(*teachers, &count);
    }
}


void checkForCorrectness(vector<School> schools, vector<Teacher> teachers){
    // check if there is any teacher available that chould be matched with another school
    for (auto school: schools){
        int habp1 = 3;
        if (school.chosenTeacherP1 != "") habp1 = getObjById(teachers, school.chosenTeacherP1).hab;
        int habp2 = 3;
        if (school.chosenTeacherP2 != "") habp2 = getObjById(teachers, school.chosenTeacherP2).hab;

        for (auto teacher: teachers){
            bool failed = false;
            int currentPreferenceIndex = in(*(teacher.preferences), teacher.chosenSchool);
            int schoolPreferenceIndex = in(*(teacher.preferences), school.id);

            if (schoolPreferenceIndex < currentPreferenceIndex && schoolPreferenceIndex > 0 &&
                    (teacher.hab > habp2 || teacher.hab > habp1))
            {
                cout << "[ALGORITHM FAILED] We have a teacher match:\n" << teacher.repr() << endl;
                cout << schoolPreferenceIndex << " " << currentPreferenceIndex << endl;
                cout << school.repr() << endl;
                if (school.chosenTeacherP1 != "")
                    cout << "\t" << "School P1: " << getObjById(teachers, school.chosenTeacherP1).repr() << endl;

                if (school.chosenTeacherP2 != "")
                cout << "\t" << "School P2: " << getObjById(teachers, school.chosenTeacherP2).repr() << endl;
            }
        }
    }
}

int main(){
    auto schools = loadSchools("resources/output_schools");
    auto teachers = loadTeachers("resources/output_teachers");

    galeShapley(&teachers, &schools);
    checkForCorrectness(schools, teachers);

    int allocatedTeachers = printTeachers(teachers);
    cout << "Professores empregados: " << allocatedTeachers << endl;

    return 0;
}