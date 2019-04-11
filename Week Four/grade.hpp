#ifndef _GRADES_H
#define _GRADES_H
#include<cstring>
#include<iostream>

class Grade{
    private:
        char *subject;
        double grade;
        void copyGrade(const Grade&);
        void deleteGrade();
    public:
        Grade(const char*, const double);
        Grade(const Grade&);
        ~Grade();
        Grade& operator=(const Grade&);
        friend std::ostream& operator<<(std::ostream&, const Grade&);
};

void Grade::copyGrade(const Grade& other){
    subject = new char[strlen(other.subject)+1];
    strcpy(subject, other.subject);
    grade = other.grade;
}

void Grade::deleteGrade(){
    delete[] subject;
}

Grade::Grade(const char* _subject="", const double _grade=2){
    if(_grade>=2 && _grade<=6)grade = _grade;
    else grade = 2;
    subject = new char[strlen(_subject)+1];
    strcpy(subject, _subject);
}

Grade::Grade(const Grade& other){
    copyGrade(other);
}

Grade::~Grade(){
    deleteGrade();
}

Grade& Grade::operator=(const Grade& other){
    if(this!=&other){
        deleteGrade();
        copyGrade(other);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Grade& gr){
    os<<gr.subject<<": "<<gr.grade<<" ";
    return os;
}

std::istream& operator>>(std::istream& is, Grade& gr){
    char subject[128];
    double grade;
    is>>subject>>grade;
    gr = Grade(subject, grade);
    return is;
}




#endif // _GRADES_H
