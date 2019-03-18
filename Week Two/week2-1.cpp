#include<iostream>
#include"rational.hpp"
using namespace std;

int main()
{
    Rational r1(1, 2), r2(1, -6), r3(2, 3);
    r1.print();
    r2.print();
    r3.print();
    (r1+r2).print();
    (r1-r2).print();
    (r1*r3).print();
    (r1/r3).print();

    return 0;
}
