#ifndef _EXHIBITION_H
#define _EXHIBITION_H
#include<cstring>
#include"painting.hpp"

class Exhibition{
    private:
        int ticket;
        Painting pics[30];
        int picSize;
    public:
        Exhibition(const int);
        void addPainting(const Painting&);
        double getValueSum()const;
};

Exhibition::Exhibition(const int _ticket=0){
    ticket=_ticket;
    picSize=0;
}

void Exhibition::addPainting(const Painting& p){
    pics[picSize]=p;
    picSize++;
}

double Exhibition::getValueSum() const{
    double valueSum=0;
    for(int i=0; i<picSize; i++){
        valueSum+=pics[i].getValue();
    }
    return ticket*valueSum;
}


#endif // _EXHIBITION_H
