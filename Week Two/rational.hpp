#ifndef _RATIONAL_H
#define _RATIONAL_H
#include<cmath>

class Rational{
private:
    int num, denom;
    void normalise();
public:
    Rational(const int, const int);
    Rational operator+(const Rational&);
    Rational operator-(const Rational&);
    Rational operator*(const Rational&);
    Rational operator/(const Rational&);
    void print()const;
};

void Rational::normalise(){
    int x=abs(num), gcd=abs(denom);
    //GCD(num, denom) algorithm
    while(x!=0){
        if(x<gcd)std::swap(x, gcd);
        x=x%gcd;
    }
    num/=gcd;
    denom/=gcd;

    if(denom<0){
        num*=-1;
        denom*=-1;
    }
}

Rational::Rational(const int _num=0, const int _denom=1){
    num=_num;
    denom=_denom;
    normalise();
}

Rational Rational::operator+(const Rational& other){
    Rational r(num*other.denom+denom*other.num, denom*other.denom);
    r.normalise();
    return r;
}

Rational Rational::operator-(const Rational& other){
    Rational r(num*other.denom-denom*other.num, denom*other.denom);
    r.normalise();
    return r;
}

Rational Rational::operator*(const Rational& other){
    Rational r(num*other.num, denom*other.denom);
    r.normalise();
    return r;
}

Rational Rational::operator/(const Rational& other){
    Rational r(num*other.denom, denom*other.num);
    r.normalise();
    return r;
}

void Rational::print() const{
    std::cout<<num<<"/"<<denom<<std::endl;
}



#endif // _RATIONAL_H
