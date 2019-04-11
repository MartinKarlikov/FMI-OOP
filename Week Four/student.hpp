#ifndef _STUDENT_H
#define _STUDENT_H
#include<iostream>
#include<cstring>
#include"grade.hpp"


class Student{
    private:
        char *name;
        int fn;
        char major[3];
        Grade *grades;
        int gradesSize;
        void copyStudent(const Student&);
        void deleteStudent();
        void copyGrades(const Grade*, const int);
    public:
        Student(const char*, const int, const char*, const Grade*, const int);
        Student(const Student&);
        ~Student();
        Student& operator=(const Student&);

        friend std::ostream& operator<<(std::ostream&, const Student&);
};

void Student::copyStudent(const Student& other){
    name = new char[strlen(other.name)+1];
    strcpy(name, other.name);
    fn = other.fn;
    strcpy(major, other.major);
    copyGrades(other.grades, other.gradesSize);
}

void Student::deleteStudent(){
    delete[] name;
    delete[] grades;
}

void Student::copyGrades(const Grade* _grades, const int _gradesSize){
    grades = new Grade[_gradesSize];
    for(int i=0; i<_gradesSize; i++)
        grades[i] = _grades[i];
    gradesSize = _gradesSize;
}

Student::Student(const char* _name="", const int _fn=10000, const char* _major="I", const Grade* _grades=new Grade[0], const int _gradesSize=0){
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
    fn = _fn;
    if(fn<10000 || fn>99999)fn = 10000;
    strcpy(major, _major);
    if(strcmp(major, "KI") && strcmp(major, "I") && strcmp(major, "SI"))strcpy(major, "I");
    copyGrades(_grades, _gradesSize);
}

Student::Student(const Student& other){
    copyStudent(other);
}

Student::~Student(){
    deleteStudent();
}

Student& Student::operator=(const Student& other){
    if(this!=&other){
        deleteStudent();
        copyStudent(other);
    }
}

 std::ostream& operator<<(std::ostream& os, const Student& st){
    os<<st.fn<<" "<<st.name<<", "<<st.major<<std::endl;
    for(int i=0; i<st.gradesSize; i++)
        os<<st.grades[i]<<std::endl;
    return os;
 }





#endif // _STUDENT_H
