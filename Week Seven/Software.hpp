#ifndef SOFTWARE_H_
#define SOFTWARE_H_
#include"Student.hpp"
#include"Lecturer.hpp"

class Software{
private:
    static int size;
    static Person **people;
    static std::string filename;
    Software()=delete;
public:
    static void add(const Student&);
    static void add(const Lecturer&);
    static void printInfo();
    static bool isInDatabase(const Person*);
};
int Software::size=0;
std::string Software::filename="grades.txt";
Person** Software::people=new Person*[128];

void Software::add(const Student& student){
    Software::people[Software::size]=new Student(student);
    Software::size++;
}

void Software::add(const Lecturer& lecturer){
    Software::people[Software::size]=new Lecturer(lecturer);
    Software::size++;
}

void Software::printInfo(){
    for(int i=0; i<size; i++){
        std::cout<<people[i];
        Software::people[i]->printGrades(filename);
    }
}

bool Software::isInDatabase(const Person* person){
    for(int i=0; i<size; i++){
        if((*Software::people[i])==person)return true;
    }
    return false;
}


#endif // SOFTWARE_H_


