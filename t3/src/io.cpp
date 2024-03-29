#include "io.hpp"

vector<School> loadSchools(string filename){
    vector<School> schools = vector<School>();

    ifstream file(filename);
    string id;

    for (int i = 0; i < 50; i++){
        file >> id;
        auto s = School(id);
        file >> s.p1 >> s.p2;
        schools.push_back(s);
    }

    file.close();
    return schools;
}

vector<Teacher> loadTeachers(string filename){
    vector<Teacher> teachers = vector<Teacher>();

    ifstream file(filename);
    int hab;
    string id, p1, p2, p3, p4;

    for (int i = 0; i < 100; i++){
        file >> id >> hab >> p1 >> p2 >> p3 >> p4;
        auto s = Teacher(id, hab);
        s.addPreference(p4);
        s.addPreference(p3);
        s.addPreference(p2);
        s.addPreference(p1);
        teachers.push_back(s);
    }

    file.close();
    return teachers;
}
