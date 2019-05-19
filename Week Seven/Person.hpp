#ifndef PERSON_H_
#define PERSON_H
#include<iostream>
#include<string>
#include<fstream>


class Person{
protected:
    std::string name;
    void setName(const std::string&);
    Person();

    virtual void printInfo(std::ostream&)const=0;
    virtual void readInfo(std::istream&)=0;

public:
    bool operator==(const Person*);
    virtual void printGrades(const std::string&)const=0;

    friend std::istream& operator>>(std::istream&, Person*);
    friend std::ostream& operator<<(std::ostream&, const Person*);
};

void Person::setName(const std::string& _name){
    name=_name;
}

Person::Person(){
    name="";
}



bool Person::operator==(const Person* other){
    return name==other->name;
}


std::istream& operator>>(std::istream& is, Person* p){
    p->readInfo(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Person* p){
    p->printInfo(os);
    return os;
}

#endif // PERSON_H_
