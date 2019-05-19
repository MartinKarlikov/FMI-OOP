#ifndef STUDENT_H_
#define STUDENT_H_
#include"Person.hpp"
#include<cstring>

class Student:public Person{
protected:
    int fn;
    int course;
    char* bachelor;

    void copyStudent(const std::string&, const int, const char*, const int);
    void deleteStudent();

    void printInfo(std::ostream&)const;
    void readInfo(std::istream&);

public:
    Student(const std::string&, const int, const char*, const int);
    Student(const Student&);
    ~Student();
    Student& operator=(const Student&);

    void printGrades(const std::string&)const;
};


void Student::copyStudent(const std::string& _name, const int _fn, const char* _bachelor, const int _course){
    Person::setName(_name);
    fn=_fn;
    bachelor=new char[strlen(_bachelor)];
    strcpy(bachelor, _bachelor);
    course=_course;
}

void Student::deleteStudent(){
    delete[] bachelor;
}

void Student::printInfo(std::ostream& os) const{
    os<<fn<<" "<<name<<", "<<bachelor<<" "<<course<<std::endl;
}

void Student::readInfo(std::istream& is){
    delete[] bachelor;
    bachelor=new char[128];
    getline(is, name);
    is>>fn>>bachelor>>course;
}

Student::Student(const std::string& _name="", const int _fn=12345, const char* _bachelor="", const int _course=0){
    copyStudent(_name, _fn, _bachelor, _course);
}

Student::Student(const Student& other){
    copyStudent(other.name, other.fn, other.bachelor, other.course);
}

Student::~Student(){
    deleteStudent();
}

Student& Student::operator=(const Student& other){
    if(this!=&other){
        deleteStudent();
        copyStudent(other.name, other.fn, other.bachelor, other.course);
    }
    return *this;
}


void Student::printGrades(const std::string& file) const{
    std::ifstream fin(file);
    std::string _name;
    bool found=false;
    while(getline(fin, _name) && !found){
        if(name==_name){
            found=true;
            std::string grade;
            while(getline(fin, grade)){
                if(grade=="*"){
                    break;
                }
                std::cout<<grade<<std::endl;
            }
        }
    }
    fin.close();
}



#endif // STUDENT_H_
