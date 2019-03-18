#ifndef _PAINTING_H
#define _PAINTING_H
#include<cstring>

class Painting{
    private:
        int id;
        char author[100], name[100];
        double value;
    public:
        Painting();
        Painting(const int, const char*, const char*, const double);
        double getValue()const;
        void print()const;
};

Painting::Painting(){
    id=0;
    author[0]='\n';
    name[0]='\n';
    value=0.0;
}

Painting::Painting(const int _id, const char* _author, const char* _name, const double _value){
    id=_id;
    strcpy(author, _author);
    strcpy(name, _name);
    value=_value;
}

double Painting::getValue() const{
    return value;
}


void Painting::print() const{
    std::cout<<"Painting id:"<<id<<" author:"<<author<<" name:"<<name<<" value:"<<value<<std::endl;
}

#endif // _PAINTING_H
