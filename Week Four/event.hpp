#ifndef _EVENT_H
#define _EVENT_H
#include<iostream>
#include<cstring>
#include<fstream>

struct Date{
    int d, m, y;
    Date(int _d=1, int _m=1, int _y=1999){
        if(_d<1 || _d>31)_d=1;
        if(_m<1 || _m>12)_m=1;
        d=_d;
        m=_m;
        y=_y;
    }
};
std::ostream& operator<<(std::ostream& os, const Date& date){
    os<<date.d<<"/"<<date.m<<"/"<<date.y;
    return os;
}
std::istream& operator>>(std::istream& is, Date& date){
    is>>date.d>>date.m>>date.y;
    return is;
}


class Event{
    private:
        Date date;
        char* name;
        char* description;
        void copyEvent(const Event&);
        void deleteEvent();
    public:
        Event(const Date&, const char*, const char*);
        Event(const Event&);
        ~Event();
        Event& operator=(const Event&);
        void printIn(const char*)const;

        friend std::ostream& operator<<(std::ostream&, const Event&);
};

void Event::copyEvent(const Event& other){
    name = new char[strlen(other.name)+1];
    strcpy(name, other.name);
    description = new char[strlen(other.description)+1];
    strcpy(description, other.description);
    date = other.date;
}

void Event::deleteEvent(){
    delete[] name;
    delete[] description;
}

Event::Event(const Date& _date, const char* _name, const char* _description){
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
    description = new char[strlen(_description)+1];
    strcpy(description, _description);
    date = _date;
}

Event::Event(const Event& other){
    copyEvent(other);
}

Event::~Event(){
    deleteEvent();
}

Event& Event::operator=(const Event& other){
    if(this!=&other){
        deleteEvent();
        copyEvent(other);
    }
    return *this;
}

void Event::printIn(const char* filename) const{
    std::ofstream fout(filename, std::ios::app);
    fout<<(*this)<<std::endl;
    fout.close();
}


std::ostream& operator<<(std::ostream& os, const Event& event){
    os<<event.date<<": "<<event.name<<std::endl<<event.description;
    return os;
}



#endif // _EVENT_H
