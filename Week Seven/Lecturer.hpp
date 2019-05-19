#ifndef LECTURER_H_
#define LECTURER_H_
#include"Person.hpp"
#include<cstring>

class Lecturer:public Person{
protected:
    int id;
    char* subject;

    void copyLecturer(const std::string&, const int, const char*);
    void deleteLecturer();

    void printInfo(std::ostream&)const;
    void readInfo(std::istream&);

public:
    Lecturer(const std::string&, const int, const char*);
    Lecturer(const Lecturer&);
    ~Lecturer();
    Lecturer& operator=(const Lecturer&);

    void printGrades(const std::string&)const;
};


void Lecturer::copyLecturer(const std::string& _name, const int _id, const char* _subject){
    Person::setName(_name);
    id=_id;
    subject=new char[strlen(_subject)];
    strcpy(subject, _subject);
}

void Lecturer::deleteLecturer(){
    delete[] subject;
}

void Lecturer::printInfo(std::ostream& os) const{
    os<<id<<" "<<name<<", "<<subject<<std::endl;
}

void Lecturer::readInfo(std::istream& is){
    delete[] subject;
    subject=new char[128];
    getline(is, name);
    is>>id>>subject;
}

Lecturer::Lecturer(const std::string& _name="", const int _id=12345, const char* _subject=""){
    copyLecturer(_name, _id, _subject);
}

Lecturer::Lecturer(const Lecturer& other){
    copyLecturer(other.name, other.id, other.subject);
}

Lecturer::~Lecturer(){
    deleteLecturer();
}

Lecturer& Lecturer::operator=(const Lecturer& other){
    if(this!=&other){
        deleteLecturer();
        copyLecturer(other.name, other.id, other.subject);
    }
    return *this;
}


void Lecturer::printGrades(const std::string& file) const{
    std::cout<<"Lecturer"<<std::endl;
}



#endif // LECTURER_H_

